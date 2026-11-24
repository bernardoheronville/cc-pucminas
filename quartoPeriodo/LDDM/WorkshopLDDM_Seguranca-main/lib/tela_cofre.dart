import 'dart:async';
import 'package:flutter/material.dart';
import 'package:local_auth/local_auth.dart';
import 'seguranca_service.dart';

class TelaCofre extends StatefulWidget {
  const TelaCofre({super.key});

  @override
  State<TelaCofre> createState() => _TelaCofreState();
}

class _TelaCofreState extends State<TelaCofre> {
  final _seguranca = SegurancaService();

  bool _carregando = true;
  bool _desbloqueado = false;
  String _tokenSessao = '';
  double _saldo = 2450.00;

  bool _temHardware = false;
  bool _suportado = false;
  List<BiometricType> _tipos = [];
  int _falhas = 0;
  int _segundosBloqueio = 0;
  Timer? _timer;

  @override
  void initState() {
    super.initState();
    _carregarEstado();
  }

  @override
  void dispose() {
    _timer?.cancel();
    super.dispose();
  }

  Future<void> _carregarEstado() async {
    await _seguranca.inicializarDados();
    final sensores = await _seguranca.verificarSensores();
    final falhas = await _seguranca.obterFalhas();
    final bloqueio = await _seguranca.segundosRestantesBloqueio();

    if (!mounted) return;
    setState(() {
      _temHardware = sensores.temHardware;
      _suportado = sensores.suportado;
      _tipos = sensores.tipos;
      _falhas = falhas;
      _segundosBloqueio = bloqueio;
      _carregando = false;
    });

    if (bloqueio > 0) _iniciarCronometro();
  }

  void _iniciarCronometro() {
    _timer?.cancel();
    _timer = Timer.periodic(const Duration(seconds: 1), (t) async {
      final restantes = await _seguranca.segundosRestantesBloqueio();
      if (!mounted) {
        t.cancel();
        return;
      }
      setState(() => _segundosBloqueio = restantes);
      if (restantes <= 0) t.cancel();
    });
  }

  Future<void> _atualizarStatusBloqueio() async {
    final falhas = await _seguranca.obterFalhas();
    final bloqueio = await _seguranca.segundosRestantesBloqueio();
    if (!mounted) return;
    setState(() {
      _falhas = falhas;
      _segundosBloqueio = bloqueio;
    });
    if (bloqueio > 0) _iniciarCronometro();
  }

  void _aviso(String texto, {bool erro = false}) {
    if (!mounted) return;
    ScaffoldMessenger.of(context).clearSnackBars();
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: Text(texto),
        backgroundColor: erro ? Colors.red.shade800 : Colors.green.shade800,
      ),
    );
  }

  /// Requisito (i): Desbloqueia a sessão via Biometria ou PIN nativo do aparelho
  Future<void> _desbloquearNativo() async {
    final res = await _seguranca.autenticarBiometriaOuPinCelular(
      'Use sua biometria ou PIN do celular para liberar sua sessão',
    );
    await _atualizarStatusBloqueio();

    if (res.sucesso) {
      final token = await _seguranca.lerTokenSessao();
      if (!mounted) return;
      setState(() {
        _desbloqueado = true;
        _tokenSessao = token;
      });
      _aviso(res.mensagem);
    } else {
      _aviso(res.mensagem, erro: true);
      if (res.abrirSenhaApp && _segundosBloqueio == 0) {
        _abrirModalSenhaApp(alterarSenha: false);
      }
    }
  }

  /// Requisito (ii): Transfere R$ 500,00 via Biometria ou PIN nativo do celular
  Future<void> _transferirNativo() async {
    final res = await _seguranca.autenticarBiometriaOuPinCelular(
      'Confirme sua biometria ou PIN do celular para transferir R\$ 500,00',
    );
    await _atualizarStatusBloqueio();

    if (res.sucesso) {
      setState(() => _saldo -= 500.00);
      _aviso('Pix de R\$ 500,00 autorizado com sucesso!');
    } else {
      _aviso(res.mensagem, erro: true);
      if (res.abrirSenhaApp && _segundosBloqueio == 0) {
        _abrirModalSenhaApp(alterarSenha: false, confirmarPix: true);
      } else if (_segundosBloqueio > 0) {
        setState(() => _desbloqueado = false);
      }
    }
  }

  /// Modal para Senha do App (desbloqueio, transferência ou alteração de senha)
  Future<void> _abrirModalSenhaApp({
    required bool alterarSenha,
    bool confirmarPix = false,
  }) async {
    final ctrl = TextEditingController();
    final titulo = alterarSenha
        ? 'Alterar Senha do App'
        : (confirmarPix ? 'Autorizar Pix com Senha do App' : 'Entrar com Senha do App');

    final digitada = await showDialog<String>(
      context: context,
      builder: (ctx) => AlertDialog(
        title: Text(titulo),
        content: TextField(
          controller: ctrl,
          obscureText: true,
          decoration: InputDecoration(
            labelText: alterarSenha
                ? 'Nova senha (mín. 4 caracteres)'
                : 'Senha do App (padrão: 1234)',
            border: const OutlineInputBorder(),
          ),
        ),
        actions: [
          TextButton(
            onPressed: () => Navigator.pop(ctx),
            child: const Text('Cancelar'),
          ),
          FilledButton(
            onPressed: () => Navigator.pop(ctx, ctrl.text.trim()),
            child: const Text('Confirmar'),
          ),
        ],
      ),
    );

    if (digitada == null || digitada.isEmpty) return;

    if (alterarSenha) {
      if (digitada.length < 4) {
        _aviso('A senha precisa ter pelo menos 4 caracteres.', erro: true);
        return;
      }
      await _seguranca.alterarSenhaApp(digitada);
      _aviso('Nova Senha do App salva no FlutterSecureStorage!');
      return;
    }

    final res = await _seguranca.autenticarSenhaApp(digitada);
    await _atualizarStatusBloqueio();

    if (res.sucesso) {
      if (confirmarPix) {
        if (!mounted) return;
        setState(() => _saldo -= 500.00);
        _aviso('Pix de R\$ 500,00 autorizado via Senha do App!');
      } else {
        final token = await _seguranca.lerTokenSessao();
        if (!mounted) return;
        setState(() {
          _desbloqueado = true;
          _tokenSessao = token;
        });
        _aviso(res.mensagem);
      }
    } else {
      _aviso(res.mensagem, erro: true);
      if (_segundosBloqueio > 0) {
        setState(() => _desbloqueado = false);
      }
    }
  }

  String _formatarTipos() {
    if (_tipos.isEmpty) return 'Nenhuma biometria cadastrada';
    return _tipos.map((t) {
      switch (t) {
        case BiometricType.fingerprint:
          return 'Digital';
        case BiometricType.face:
          return 'Facial';
        case BiometricType.iris:
          return 'Íris';
        case BiometricType.strong:
          return 'Forte (Class 3)';
        case BiometricType.weak:
          return 'Fraca (Class 2)';
      }
    }).join(', ');
  }

  @override
  Widget build(BuildContext context) {
    final cores = Theme.of(context).colorScheme;
    final bloqueado = _segundosBloqueio > 0;

    return Scaffold(
      appBar: AppBar(
        title: const Text('Cofre Biométrico'),
        actions: [
          if (_desbloqueado)
            IconButton(
              tooltip: 'Trancar sessão',
              icon: const Icon(Icons.lock),
              onPressed: () => setState(() {
                _desbloqueado = false;
                _tokenSessao = '';
              }),
            ),
        ],
      ),
      body: _carregando
          ? const Center(child: CircularProgressIndicator())
          : ListView(
              padding: const EdgeInsets.all(20),
              children: [
                Card(
                  color: cores.surfaceContainerHighest,
                  child: Padding(
                    padding: const EdgeInsets.all(16),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        const Text(
                          'Diagnóstico de Segurança (local_auth)',
                          style: TextStyle(fontWeight: FontWeight.bold),
                        ),
                        const Divider(),
                        Text('Sensor biométrico: ${_temHardware ? "Sim" : "Não"}'),
                        Text('PIN/Bloqueio no aparelho: ${_suportado ? "Sim" : "Não"}'),
                        Text('Biometrias ativas: ${_formatarTipos()}'),
                        Text('Falhas consecutivas: $_falhas / ${SegurancaService.maxTentativas}'),
                      ],
                    ),
                  ),
                ),
                const SizedBox(height: 16),
                if (bloqueado)
                  Container(
                    padding: const EdgeInsets.all(16),
                    margin: const EdgeInsets.only(bottom: 16),
                    decoration: BoxDecoration(
                      color: cores.errorContainer,
                      borderRadius: BorderRadius.circular(12),
                      border: Border.all(color: cores.error),
                    ),
                    child: Text(
                      'Bloqueio temporário ativo após 3 falhas.\nAguarde ${_segundosBloqueio}s para tentar novamente.',
                      style: TextStyle(
                        color: cores.onErrorContainer,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                if (!_desbloqueado) ...[
                  const SizedBox(height: 24),
                  Icon(Icons.lock_outline, size: 72, color: cores.primary),
                  const SizedBox(height: 12),
                  const Text(
                    'Sessão Bloqueada',
                    textAlign: TextAlign.center,
                    style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold),
                  ),
                  const SizedBox(height: 24),
                  FilledButton.icon(
                    onPressed: bloqueado ? null : _desbloquearNativo,
                    icon: const Icon(Icons.fingerprint),
                    label: const Text('Desbloquear (Biometria ou PIN do Celular)'),
                    style: FilledButton.styleFrom(
                      padding: const EdgeInsets.symmetric(vertical: 16),
                    ),
                  ),
                  const SizedBox(height: 12),
                  OutlinedButton.icon(
                    onPressed: bloqueado ? null : () => _abrirModalSenhaApp(alterarSenha: false),
                    icon: const Icon(Icons.password),
                    label: const Text('Entrar com Senha do App (Fallback)'),
                    style: OutlinedButton.styleFrom(
                      padding: const EdgeInsets.symmetric(vertical: 14),
                    ),
                  ),
                ] else ...[
                  Card(
                    child: Padding(
                      padding: const EdgeInsets.all(20),
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          const Text('Saldo Protegido'),
                          Text(
                            'R\$ ${_saldo.toStringAsFixed(2)}',
                            style: TextStyle(
                              fontSize: 30,
                              fontWeight: FontWeight.bold,
                              color: cores.primary,
                            ),
                          ),
                          const SizedBox(height: 16),
                          const Text(
                            'Segredo lido do FlutterSecureStorage:',
                            style: TextStyle(fontWeight: FontWeight.bold, fontSize: 12),
                          ),
                          const SizedBox(height: 6),
                          Container(
                            width: double.infinity,
                            padding: const EdgeInsets.all(10),
                            decoration: BoxDecoration(
                              color: cores.surfaceContainerHighest,
                              borderRadius: BorderRadius.circular(8),
                            ),
                            child: Text(
                              _tokenSessao,
                              style: const TextStyle(fontFamily: 'monospace'),
                            ),
                          ),
                          const SizedBox(height: 20),
                          SizedBox(
                            width: double.infinity,
                            child: FilledButton.icon(
                              onPressed: bloqueado || _saldo < 500 ? null : _transferirNativo,
                              icon: const Icon(Icons.send_to_mobile),
                              label: const Text('Transferir R\$ 500,00 (Biometria / PIN Celular)'),
                              style: FilledButton.styleFrom(
                                padding: const EdgeInsets.symmetric(vertical: 16),
                              ),
                            ),
                          ),
                          const SizedBox(height: 12),
                          SizedBox(
                            width: double.infinity,
                            child: OutlinedButton.icon(
                              onPressed: bloqueado || _saldo < 500
                                  ? null
                                  : () => _abrirModalSenhaApp(alterarSenha: false, confirmarPix: true),
                              icon: const Icon(Icons.key),
                              label: const Text('Transferir R\$ 500,00 com Senha do App'),
                              style: OutlinedButton.styleFrom(
                                padding: const EdgeInsets.symmetric(vertical: 14),
                              ),
                            ),
                          ),
                          const SizedBox(height: 12),
                          SizedBox(
                            width: double.infinity,
                            child: TextButton.icon(
                              onPressed: () => _abrirModalSenhaApp(alterarSenha: true),
                              icon: const Icon(Icons.edit),
                              label: const Text('Alterar Senha do App'),
                            ),
                          ),
                        ],
                      ),
                    ),
                  ),
                ],
              ],
            ),
    );
  }
}
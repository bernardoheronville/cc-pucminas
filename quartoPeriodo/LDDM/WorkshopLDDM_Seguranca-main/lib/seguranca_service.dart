import 'package:flutter/services.dart';
import 'package:flutter_secure_storage/flutter_secure_storage.dart';
import 'package:local_auth/local_auth.dart';

class ResultadoAuth {
  final bool sucesso;
  final String mensagem;
  final bool abrirSenhaApp;

  const ResultadoAuth({
    required this.sucesso,
    required this.mensagem,
    this.abrirSenhaApp = false,
  });
}

class SegurancaService {
  final LocalAuthentication _auth = LocalAuthentication();
  final FlutterSecureStorage _storage = const FlutterSecureStorage();

  static const _chaveToken = 'token_sessao_autenticada';
  static const _chaveSenhaApp = 'senha_app_cofre';
  static const _chaveFalhas = 'falhas_consecutivas';
  static const _chaveBloqueioAte = 'bloqueio_ate_iso';

  static const int maxTentativas = 3;
  static const int segundosBloqueio = 30;

  /// Simula uma sessão já autenticada no servidor e grava a senha inicial do app (1234)
  Future<void> inicializarDados() async {
    if (await _storage.read(key: _chaveToken) == null) {
      await _storage.write(
        key: _chaveToken,
        value: 'SESSAO_AUTENTICADA_#9842',
      );
    }
    if (await _storage.read(key: _chaveSenhaApp) == null) {
      await _storage.write(key: _chaveSenhaApp, value: '1234');
    }
  }

  /// Verifica hardware biométrico, suporte a credenciais do aparelho e tipos cadastrados
  Future<({bool temHardware, bool suportado, List<BiometricType> tipos})>
      verificarSensores() async {
    final temHardware = await _auth.canCheckBiometrics;
    final suportado = await _auth.isDeviceSupported();
    final tipos = await _auth.getAvailableBiometrics();
    return (temHardware: temHardware, suportado: suportado, tipos: tipos);
  }

  Future<int> segundosRestantesBloqueio() async {
    final iso = await _storage.read(key: _chaveBloqueioAte);
    if (iso == null) return 0;

    final limite = DateTime.tryParse(iso);
    if (limite == null) return 0;

    final restantes = limite.difference(DateTime.now()).inSeconds;
    if (restantes <= 0) {
      await _storage.delete(key: _chaveBloqueioAte);
      return 0;
    }
    return restantes;
  }

  Future<int> obterFalhas() async {
    final valor = await _storage.read(key: _chaveFalhas);
    return int.tryParse(valor ?? '0') ?? 0;
  }

  Future<String> _registrarFalha(String motivoBase) async {
    final falhas = (await obterFalhas()) + 1;

    if (falhas >= maxTentativas) {
      final fim = DateTime.now().add(const Duration(seconds: segundosBloqueio));
      await _storage.write(key: _chaveBloqueioAte, value: fim.toIso8601String());
      await _storage.write(key: _chaveFalhas, value: '0');
      return '3 falhas consecutivas! Acesso bloqueado por ${segundosBloqueio}s.';
    }

    await _storage.write(key: _chaveFalhas, value: falhas.toString());
    return '$motivoBase ($falhas/$maxTentativas falhas).';
  }

  Future<void> _limparFalhas() async {
    await _storage.write(key: _chaveFalhas, value: '0');
    await _storage.delete(key: _chaveBloqueioAte);
  }

  /// Autentica via sistema operacional: aceita Digital, Facial e PIN/Padrão do celular
  Future<ResultadoAuth> autenticarBiometriaOuPinCelular(String motivo) async {
    final bloqueio = await segundosRestantesBloqueio();
    if (bloqueio > 0) {
      return ResultadoAuth(
        sucesso: false,
        mensagem: 'Bloqueado. Aguarde ${bloqueio}s.',
      );
    }

    try {
      final suportado = await _auth.isDeviceSupported();
      if (!suportado) {
        return const ResultadoAuth(
          sucesso: false,
          mensagem: 'Aparelho sem biometria ou PIN configurado. Use a Senha do App.',
          abrirSenhaApp: true,
        );
      }

      // biometricOnly: false permite Digital, Facial (incluindo Class 2)
      // e o próprio PIN/Senha de bloqueio do celular.
      final ok = await _auth.authenticate(
        localizedReason: motivo,
        biometricOnly: false,
      );

      if (ok) {
        await _limparFalhas();
        return const ResultadoAuth(
          sucesso: true,
          mensagem: 'Autenticado pelo sistema do aparelho!',
        );
      }

      final msg = await _registrarFalha('Autenticação cancelada ou não reconhecida');
      return ResultadoAuth(sucesso: false, mensagem: msg);
    } on LocalAuthException catch (e) {
      final codigo = e.code.name;
      final semCredencialNativa = codigo == 'noBiometricsEnrolled' ||
          codigo == 'noBiometricHardware' ||
          codigo == 'noCredentialsSet';

      if (semCredencialNativa) {
        return const ResultadoAuth(
          sucesso: false,
          mensagem: 'Nenhuma biometria ou PIN nativo ativo. Use a Senha do App.',
          abrirSenhaApp: true,
        );
      }

      final msg = await _registrarFalha('Falha na verificação ($codigo)');
      return ResultadoAuth(sucesso: false, mensagem: msg);
    } on PlatformException catch (e) {
      return ResultadoAuth(
        sucesso: false,
        mensagem: 'Erro nativo (${e.code}): ${e.message ?? "verifique MainActivity"}',
        abrirSenhaApp: true,
      );
    }
  }

  /// Valida a Senha própria do App armazenada no FlutterSecureStorage
  Future<ResultadoAuth> autenticarSenhaApp(String senhaDigitada) async {
    final bloqueio = await segundosRestantesBloqueio();
    if (bloqueio > 0) {
      return ResultadoAuth(
        sucesso: false,
        mensagem: 'Bloqueado. Aguarde ${bloqueio}s.',
      );
    }

    final senhaSalva = await _storage.read(key: _chaveSenhaApp);
    if (senhaDigitada == senhaSalva) {
      await _limparFalhas();
      return const ResultadoAuth(
        sucesso: true,
        mensagem: 'Autorizado com a Senha do App!',
      );
    }

    final msg = await _registrarFalha('Senha do App incorreta');
    return ResultadoAuth(sucesso: false, mensagem: msg);
  }

  Future<void> alterarSenhaApp(String novaSenha) =>
      _storage.write(key: _chaveSenhaApp, value: novaSenha);

  Future<String> lerTokenSessao() async =>
      await _storage.read(key: _chaveToken) ?? '';
}
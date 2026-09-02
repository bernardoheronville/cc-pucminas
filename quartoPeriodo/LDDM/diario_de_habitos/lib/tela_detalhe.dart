import 'package:flutter/material.dart';

class TelaDetalhe extends StatelessWidget {
  const TelaDetalhe({super.key});

  static const String nome = 'Monitoria';
  static const String meta = 'Meta: 10 horas semanais';
  static const IconData icone = Icons.menu_book;
  static const String descricao =
      'Ajudar os alunos com dúvidas.'
      ' Fazer aulões para os alunos.'
      ' Fechar a meta na semana.';
      
  static const String _endereco = 'assets/imagens/image.png';
  static const double _alturaImagem = 180;
  static const double _raioAvatar = 28;

  @override
  Widget build(BuildContext context) {
    final cores = Theme.of(context).colorScheme;
    final textos = Theme.of(context).textTheme;

    return Scaffold(
      appBar: AppBar(title: const Text(nome)),
      body: SingleChildScrollView(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Padding(
              padding: const EdgeInsets.all(16),
              child: ClipRRect(
                borderRadius: BorderRadius.circular(12),
                child: Stack(
                  children: [
                    Image.asset(
                      _endereco,
                      height: _alturaImagem,
                      width: double.infinity,
                      fit: BoxFit.cover,
                      errorBuilder: (context, erro, pilha) =>
                          _PlaceholderImagem(
                            altura: _alturaImagem,
                            child: Column(
                              mainAxisSize: MainAxisSize.min,
                              children: [
                                Icon(
                                  Icons.image_not_supported_outlined,
                                  size: 32,
                                  color: cores.onPrimaryContainer,
                                ),
                                const SizedBox(height: 8),
                                Text(
                                  'Imagem não encontrada',
                                  style: textos.bodySmall?.copyWith(
                                    color: cores.onPrimaryContainer,
                                  ),
                                ),
                              ],
                            ),
                          ),
                    ),
                    Positioned.fill(
                      child: Padding(
                        padding: const EdgeInsets.symmetric(horizontal: 16),
                        child: Row(
                          children: [
                            CircleAvatar(
                              radius: _raioAvatar,
                              backgroundColor: cores.onPrimary,
                              child: Icon(icone, color: cores.primary),
                            ),
                            const SizedBox(width: 12),
                            Expanded(
                              child: Column(
                                mainAxisSize: MainAxisSize.min,
                                mainAxisAlignment: MainAxisAlignment.center,
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text(
                                    nome,
                                    style: textos.titleLarge?.copyWith(
                                      color: cores.onPrimary,
                                    ),
                                    maxLines: 1,
                                    overflow: TextOverflow.ellipsis,
                                  ),
                                  Text(
                                    meta,
                                    style: textos.bodyMedium?.copyWith(
                                      color: cores.onPrimary,
                                    ),
                                    maxLines: 1,
                                    overflow: TextOverflow.ellipsis,
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ),
            Padding(
              padding: const EdgeInsets.symmetric(horizontal: 16),
              child: Row(
                children: const [
                  Expanded(
                    child: _Indicador(
                      icone: Icons.today,
                      valor: '5 / 10',
                      rotulo: 'Semana',
                    ),
                  ),
                  Expanded(
                    child: _Indicador(
                      icone: Icons.local_fire_department,
                      valor: '12',
                      rotulo: 'Sequência',
                    ),
                  ),
                  Expanded(
                    child: _Indicador(
                      icone: Icons.calendar_month,
                      valor: '50%',
                      rotulo: 'Na semana',
                    ),
                  ),
                ],
              ),
            ),
            const SizedBox(height: 24),
            Padding(
              padding: const EdgeInsets.symmetric(horizontal: 16),
              child: Card(
                child: Padding(
                  padding: const EdgeInsets.all(16),
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text('Sobre o hábito', style: textos.titleMedium),
                      const SizedBox(height: 8),
                      Row(
                        children: [
                          Icon(icone, color: cores.primary),
                          const SizedBox(width: 8),
                          Expanded(child: Text(meta)),
                        ],
                      ),
                      const SizedBox(height: 16),
                      Text(descricao, style: textos.bodyMedium),
                    ],
                  ),
                ),
              ),
            ),
            const SizedBox(height: 24),
          ],
        ),
      ),
    );
  }
}

class _PlaceholderImagem extends StatelessWidget {
  const _PlaceholderImagem({required this.altura, required this.child});

  final double altura;
  final Widget child;

  @override
  Widget build(BuildContext context) => Container(
    height: altura,
    width: double.infinity,
    color: Theme.of(context).colorScheme.primaryContainer,
    alignment: Alignment.center,
    child: child,
  );
}

class _Indicador extends StatelessWidget {
  const _Indicador({
    required this.icone,
    required this.valor,
    required this.rotulo,
  });

  final IconData icone;
  final String valor;
  final String rotulo;

  @override
  Widget build(BuildContext context) {
    final cores = Theme.of(context).colorScheme;
    final textos = Theme.of(context).textTheme;

    return Container(
      padding: const EdgeInsets.symmetric(vertical: 12, horizontal: 4),
      margin: const EdgeInsets.symmetric(horizontal: 4),
      decoration: BoxDecoration(
        color: cores.surfaceContainerHighest,
        borderRadius: BorderRadius.circular(12),
      ),
      child: Column(
        children: [
          Icon(icone, color: cores.primary),
          const SizedBox(height: 8),
          Text(
            valor,
            style: textos.titleMedium,
            maxLines: 1,
            overflow: TextOverflow.ellipsis,
          ),
          Text(
            rotulo,
            style: textos.bodySmall,
            maxLines: 1,
            overflow: TextOverflow.ellipsis,
          ),
        ],
      ),
    );
  }
}
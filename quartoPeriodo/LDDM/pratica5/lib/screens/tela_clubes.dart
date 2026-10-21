import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import '../models/clube.dart';
import '../state/clubes_store.dart';

class TelaClubes extends StatelessWidget {
  const TelaClubes({super.key});

  @override
  Widget build(BuildContext context) {
    final loja = context.watch<ClubesStore>();

    return Scaffold(
      appBar: AppBar(
        title: const Text('Clubes do Brasileirão'),
        actions: [
          IconButton(
            tooltip: 'Atualizar',
            icon: const Icon(Icons.refresh),
            onPressed:
                loja.estado == Estado.carregando ? null : () => loja.carregar(),
          ),
        ],
      ),
      body: switch (loja.estado) {
        Estado.carregando => const Center(child: CircularProgressIndicator()),
        Estado.erro => _TelaDeErro(
            mensagem: loja.mensagemErro ?? 'Não foi possível carregar.',
            aoTentarDeNovo: () => loja.carregar(),
          ),
        Estado.pronto => loja.todos.isEmpty
            ? _TelaVazia(aoAtualizar: () => loja.carregar())
            : _ListaDeClubes(loja: loja),
      },
    );
  }
}

class _TelaDeErro extends StatelessWidget {
  const _TelaDeErro({required this.mensagem, required this.aoTentarDeNovo});

  final String mensagem;
  final VoidCallback aoTentarDeNovo;

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(24),
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            Icon(Icons.wifi_off,
                size: 64, color: Theme.of(context).colorScheme.error),
            const SizedBox(height: 16),
            Text('Ops, algo deu errado',
                style: Theme.of(context).textTheme.titleLarge),
            const SizedBox(height: 8),
            Text(mensagem, textAlign: TextAlign.center),
            const SizedBox(height: 24),
            FilledButton.icon(
              onPressed: aoTentarDeNovo,
              icon: const Icon(Icons.refresh),
              label: const Text('Tentar de novo'),
            ),
          ],
        ),
      ),
    );
  }
}

class _TelaVazia extends StatelessWidget {
  const _TelaVazia({required this.aoAtualizar});

  final VoidCallback aoAtualizar;

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(24),
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            const Icon(Icons.sports_soccer, size: 64),
            const SizedBox(height: 16),
            const Text(
              'A API respondeu, mas não há clubes cadastrados no momento.',
              textAlign: TextAlign.center,
            ),
            const SizedBox(height: 24),
            OutlinedButton(
              onPressed: aoAtualizar,
              child: const Text('Atualizar'),
            ),
          ],
        ),
      ),
    );
  }
}

class _ListaDeClubes extends StatelessWidget {
  const _ListaDeClubes({required this.loja});

  final ClubesStore loja;

  @override
  Widget build(BuildContext context) {
    final clubes = loja.visiveis;

    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.fromLTRB(12, 12, 12, 4),
          child: TextField(
            onChanged: loja.buscar,
            decoration: const InputDecoration(
              prefixIcon: Icon(Icons.search),
              hintText: 'Buscar clube ou sigla',
              border: OutlineInputBorder(),
              isDense: true,
            ),
          ),
        ),
        if (loja.temClassificacao)
          Padding(
            padding: const EdgeInsets.symmetric(vertical: 8),
            child: SegmentedButton<Ordem>(
              segments: const [
                ButtonSegment(value: Ordem.nome, label: Text('A–Z')),
                ButtonSegment(
                    value: Ordem.classificacao, label: Text('Classificação')),
              ],
              selected: {loja.ordem},
              onSelectionChanged: (s) => loja.ordenarPor(s.first),
            ),
          ),
        Expanded(
          child: clubes.isEmpty
              ? Center(
                  child: Text('Nenhum clube encontrado para "${loja.busca}".'),
                )
              : GridView.builder(
                  padding: const EdgeInsets.all(12),
                  gridDelegate: const SliverGridDelegateWithMaxCrossAxisExtent(
                    maxCrossAxisExtent: 180,
                    childAspectRatio: 0.85,
                    crossAxisSpacing: 10,
                    mainAxisSpacing: 10,
                  ),
                  itemCount: clubes.length,
                  itemBuilder: (context, i) => _CartaoClube(clube: clubes[i]),
                ),
        ),
      ],
    );
  }
}

class _CartaoClube extends StatelessWidget {
  const _CartaoClube({required this.clube});

  final Clube clube;

  @override
  Widget build(BuildContext context) {
    final posicao = clube.posicao;

    return Card(
      clipBehavior: Clip.antiAlias,
      child: InkWell(
        onTap: () => _mostrarDetalhes(context, clube),
        child: Padding(
          padding: const EdgeInsets.all(10),
          child: Column(
            children: [
              Expanded(
                child: Center(
                  child: _Escudo(url: clube.escudoUrl, tamanho: 64),
                ),
              ),
              const SizedBox(height: 8),
              Text(
                clube.apelido,
                maxLines: 2,
                overflow: TextOverflow.ellipsis,
                textAlign: TextAlign.center,
                style: const TextStyle(fontWeight: FontWeight.bold),
              ),
              Text(
                posicao == null
                    ? clube.abreviacao
                    : '${clube.abreviacao} · ${posicao}º',
                style: Theme.of(context).textTheme.bodySmall,
              ),
            ],
          ),
        ),
      ),
    );
  }
}

void _mostrarDetalhes(BuildContext context, Clube clube) {
  final posicao = clube.posicao;
  showModalBottomSheet<void>(
    context: context,
    builder: (_) => SafeArea(
      child: Padding(
        padding: const EdgeInsets.all(24),
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            _Escudo(url: clube.escudoUrl, tamanho: 96),
            const SizedBox(height: 12),
            Text(clube.nome, style: Theme.of(context).textTheme.headlineSmall),
            const SizedBox(height: 8),
            Text('Sigla: ${clube.abreviacao}'),
            if (posicao != null) Text('Classificação: ${posicao}º'),
            Text('ID na API: ${clube.id}'),
          ],
        ),
      ),
    ),
  );
}

class _Escudo extends StatelessWidget {
  const _Escudo({required this.url, required this.tamanho});

  final String? url;
  final double tamanho;

  @override
  Widget build(BuildContext context) {
    final endereco = url;
    if (endereco == null) {
      return Icon(Icons.shield_outlined, size: tamanho);
    }
    return Image.network(
      endereco,
      width: tamanho,
      height: tamanho,
      fit: BoxFit.contain,
      errorBuilder: (context, erro, pilha) =>
          Icon(Icons.shield_outlined, size: tamanho),
      loadingBuilder: (context, filho, progresso) {
        if (progresso == null) return filho;
        return SizedBox(
          width: tamanho,
          height: tamanho,
          child: const Center(child: CircularProgressIndicator(strokeWidth: 2)),
        );
      },
    );
  }
}

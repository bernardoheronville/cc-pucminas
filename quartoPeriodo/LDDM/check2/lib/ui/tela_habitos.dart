import 'package:flutter/material.dart';

import '../models/habito.dart';
import '../stores/habito_store.dart';
import 'tela_novo_habito.dart';

IconData iconeHabito(String icone) => switch (icone) {
  'agua' => Icons.local_drink,
  'leitura' => Icons.menu_book,
  'caminhada' => Icons.directions_walk,
  'sono' => Icons.bedtime,
  _ => Icons.check_circle,
};

class TelaHabitos extends StatelessWidget {
  const TelaHabitos({super.key, required this.store});

  final HabitoStore store;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Meus Hábitos')),
      body: ListenableBuilder(
        listenable: store,
        builder: (context, _) {
          final habitos = store.habitos;

          if (habitos.isEmpty) {
            return const Center(child: Text('Nenhum hábito cadastrado.'));
          }

          return ListView.builder(
            itemCount: habitos.length,
            itemBuilder: (_, i) {
              final h = habitos[i];
              final meta = 'Meta: ${h.frequenciaSemanal}x/semana';
              return ListTile(
                leading: Icon(iconeHabito(h.icone)),
                title: Text(h.nome),
                subtitle: Text(h.descricao.isEmpty ? meta : '$meta\n${h.descricao}'),
                isThreeLine: h.descricao.isNotEmpty,
                onTap: () => Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (_) => TelaDetalheHabito(habito: h, store: store),
                  ),
                ),
              );
            },
          );
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () => Navigator.push(
          context,
          MaterialPageRoute(builder: (_) => TelaNovoHabito(store: store)),
        ),
        child: const Icon(Icons.add),
      ),
    );
  }
}

class TelaDetalheHabito extends StatelessWidget {
  const TelaDetalheHabito({super.key, required this.habito, required this.store});

  final Habito habito;
  final HabitoStore store;

  @override
  Widget build(BuildContext context) => Scaffold(
    appBar: AppBar(title: Text(habito.nome)),
    body: Column(
      children: [
        ListTile(
          leading: Icon(iconeHabito(habito.icone)),
          title: Text(habito.nome),
          subtitle: Text('Meta: ${habito.frequenciaSemanal}x por semana'),
        ),
        ListTile(
          leading: const Icon(Icons.format_list_numbered),
          title: Text('Posição na lista: ${store.posicaoDe(habito)} de ${store.total}'),
        ),
        const SizedBox(height: 16),
        FilledButton(
          onPressed: () {
            store.remover(habito);
            Navigator.pop(context);
          },
          child: const Text('Excluir'),
        ),
        FilledButton(
          onPressed: () {
            store.favoritar(habito);
            Navigator.pop(context);
          },
          child: const Text('Favoritar'),
        ),
        FilledButton(
          onPressed: () {
            store.arquivar(habito);
            Navigator.pop(context);
          },
          child: const Text('Arquivar'),
        ),
      ],
    ),
  );
}

class TelaResumo extends StatelessWidget {
  const TelaResumo({super.key, required this.store});

  final HabitoStore store;

  @override
  Widget build(BuildContext context) => Scaffold(
    appBar: AppBar(title: const Text('Resumo')),
    body: ListenableBuilder(
      listenable: store,
      builder: (context, _) => Center(
        child: Text('${store.total} ${store.total == 1 ? 'hábito' : 'hábitos'}'),
      ),
    ),
  );
}

import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'models/habito.dart';
import 'stores/habitos_store.dart';
import 'tela_detalhe.dart';

void main() {
  runApp(const MeuApp());
}

class MeuApp extends StatelessWidget {
  const MeuApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Diário de Hábitos',
      theme: ThemeData(
        primarySwatch: Colors.teal,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: const TelaPrincipal(),
    );
  }
}

/// Camada de INTERFACE: a lista vive no store, não aqui.
class TelaPrincipal extends StatefulWidget {
  const TelaPrincipal({super.key});

  @override
  State<TelaPrincipal> createState() => _TelaPrincipalState();
}

class _TelaPrincipalState extends State<TelaPrincipal> {
  final HabitosStore store = HabitosStore();

  void _abrirModalAdicionar(BuildContext context) {
    final nomeController = TextEditingController();
    final descController = TextEditingController();
    final freqController = TextEditingController();

    showModalBottomSheet(
      context: context,
      isScrollControlled: true,
      builder: (ctx) => Padding(
        padding: EdgeInsets.only(
          top: 16,
          left: 16,
          right: 16,
          bottom: MediaQuery.of(ctx).viewInsets.bottom + 16,
        ),
        child: Column(
          mainAxisSize: MainAxisSize.min,
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            const Text(
              'Novo Hábito',
              style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 12),
            TextField(
              controller: nomeController,
              decoration: const InputDecoration(labelText: 'Nome do Hábito'),
            ),
            TextField(
              controller: descController,
              decoration: const InputDecoration(labelText: 'Descrição'),
            ),
            TextField(
              controller: freqController,
              keyboardType: TextInputType.number,
              decoration: const InputDecoration(
                labelText: 'Frequência Semanal (dias)',
              ),
            ),
            const SizedBox(height: 16),
            ElevatedButton(
              onPressed: () {
                final nome = nomeController.text;
                final desc = descController.text;
                final freq = int.tryParse(freqController.text) ?? 0;

                if (nome.isNotEmpty && freq > 0) {
                  store.adicionarHabito(
                    Habito(
                      nome: nome,
                      descricao: desc,
                      frequenciaSemanal: freq,
                    ),
                  );
                  Navigator.of(ctx).pop();
                }
              },
              child: const Text('Salvar'),
            ),
          ],
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Diário de Hábitos')),
      body: Observer(
        builder: (_) {
          if (store.habitos.isEmpty) {
            return const Center(child: Text('Nenhum hábito cadastrado.'));
          }
          return ListView.builder(
            itemCount: store.habitos.length,
            itemBuilder: (ctx, index) {
              final habito = store.habitos[index];
              return Card(
                margin: const EdgeInsets.symmetric(horizontal: 12, vertical: 6),
                child: ListTile(
                  title: Text(habito.nome),
                  subtitle: Text(
                    'Meta: ${habito.frequenciaSemanal}x/semana\n${habito.descricao}',
                  ),
                  isThreeLine: true,
                  trailing: const Icon(Icons.arrow_forward_ios, size: 16),
                  onTap: () => Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (_) =>
                          TelaDetalhe(habito: habito, store: store),
                    ),
                  ),
                ),
              );
            },
          );
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () => _abrirModalAdicionar(context),
        child: const Icon(Icons.add),
      ),
    );
  }
}
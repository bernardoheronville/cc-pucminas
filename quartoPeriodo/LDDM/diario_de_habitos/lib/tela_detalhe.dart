import 'package:flutter/material.dart';
import 'models/habito.dart';
import 'stores/habitos_store.dart';

class TelaDetalhe extends StatefulWidget {
  final Habito habito;
  final HabitosStore store;

  const TelaDetalhe({super.key, required this.habito, required this.store});

  @override
  State<TelaDetalhe> createState() => _TelaDetalheState();
}

class _TelaDetalheState extends State<TelaDetalhe> {
  void _registrarConclusao() {
    final registrou = widget.store.registrarConclusao(widget.habito);
    setState(() {});
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: Text(registrou
            ? 'Hábito concluído hoje! 🎉'
            : 'Este hábito já foi registrado hoje.'),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    final habito = widget.habito;
    return Scaffold(
      appBar: AppBar(title: Text(habito.nome)),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text(
              habito.nome,
              style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 8),
            Text(
              habito.descricao,
              style: const TextStyle(fontSize: 16, color: Colors.black87),
            ),
            const SizedBox(height: 12),
            Chip(
              label: Text(
                'Meta: ${habito.frequenciaSemanal} dias por semana',
                style: const TextStyle(color: Colors.white),
              ),
              backgroundColor: Colors.teal,
            ),
            const Divider(height: 32),
            const Text(
              'Histórico de Realizações',
              style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 8),
            Expanded(
              child: habito.historico.isEmpty
                  ? const Center(
                      child: Text('Nenhum registro efetuado até o momento.'),
                    )
                  : ListView.builder(
                      itemCount: habito.historico.length,
                      itemBuilder: (context, index) {
                        return ListTile(
                          leading: const Icon(
                            Icons.check_circle,
                            color: Colors.green,
                          ),
                          title: Text(habito.historico[index]),
                        );
                      },
                    ),
            ),
            SizedBox(
              width: double.infinity,
              child: ElevatedButton.icon(
                onPressed: _registrarConclusao,
                icon: const Icon(Icons.done),
                label: const Text('Marcar como Concluído Hoje'),
                style: ElevatedButton.styleFrom(
                  padding: const EdgeInsets.symmetric(vertical: 14),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
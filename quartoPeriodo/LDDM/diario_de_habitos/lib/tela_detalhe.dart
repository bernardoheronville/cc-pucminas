import 'package:flutter/material.dart';
import 'main.dart';

class TelaDetalhe extends StatefulWidget {
  final Habito habito;

  const TelaDetalhe({super.key, required this.habito});

  @override
  State<TelaDetalhe> createState() => _TelaDetalheState();
}

class _TelaDetalheState extends State<TelaDetalhe> {
  void _registrarConclusao() {
    final hoje = DateTime.now();
    final dataFormatada =
        "${hoje.day.toString().padLeft(2, '0')}/${hoje.month.toString().padLeft(2, '0')}/${hoje.year}";

    if (!widget.habito.historico.contains(dataFormatada)) {
      setState(() {
        widget.habito.historico.add(dataFormatada);
      });
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('Hábito concluído hoje! 🎉')),
      );
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('Este hábito já foi registrado hoje.')),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.habito.nome),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text(
              widget.habito.nome,
              style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 8),
            Text(
              widget.habito.descricao,
              style: const TextStyle(fontSize: 16, color: Colors.black87),
            ),
            const SizedBox(height: 12),
            Chip(
              label: Text(
                'Meta: ${widget.habito.frequenciaSemanal} dias por semana',
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
              child: widget.habito.historico.isEmpty
                  ? const Center(
                      child: Text('Nenhum registro efetuado até o momento.'),
                    )
                  : ListView.builder(
                      itemCount: widget.habito.historico.length,
                      itemBuilder: (context, index) {
                        return ListTile(
                          leading: const Icon(
                            Icons.check_circle,
                            color: Colors.green,
                          ),
                          title: Text(widget.habito.historico[index]),
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
import 'package:flutter/material.dart';

import '../models/habito.dart';
import '../stores/habito_store.dart';

class TelaNovoHabito extends StatefulWidget {
  const TelaNovoHabito({super.key, required this.store});

  final HabitoStore store;

  @override
  State<TelaNovoHabito> createState() => _TelaNovoHabitoState();
}

class _TelaNovoHabitoState extends State<TelaNovoHabito> {
  final _chave = GlobalKey<FormState>();
  final _nome = TextEditingController();
  final _descricao = TextEditingController();
  final _frequencia = TextEditingController();

  @override
  void dispose() {
    _nome.dispose();
    _descricao.dispose();
    _frequencia.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) => Scaffold(
    appBar: AppBar(title: const Text('Novo hábito')),
    body: Form(
      key: _chave,
      child: SingleChildScrollView(
        padding: const EdgeInsets.all(16),
        child: Column(
          children: [
            TextFormField(
              controller: _nome,
              decoration: const InputDecoration(labelText: 'Nome'),
              validator: (v) =>
                  (v == null || v.trim().isEmpty) ? 'Informe o nome' : null,
            ),
            TextFormField(
              controller: _descricao,
              decoration: const InputDecoration(labelText: 'Descrição'),
            ),
            TextFormField(
              controller: _frequencia,
              keyboardType: TextInputType.number,
              decoration: const InputDecoration(
                labelText: 'Frequência semanal (dias)',
              ),
              validator: (v) {
                final n = int.tryParse(v ?? '');
                if (n == null || n <= 0) return 'Informe um número maior que 0';
                return null;
              },
            ),
            const SizedBox(height: 24),
            FilledButton(
              onPressed: () {
                if (_chave.currentState!.validate()) {
                  widget.store.adicionar(
                    Habito(
                      nome: _nome.text.trim(),
                      descricao: _descricao.text.trim(),
                      frequenciaSemanal: int.parse(_frequencia.text),
                    ),
                  );
                  Navigator.pop(context);
                }
              },
              child: const Text('Salvar'),
            ),
          ],
        ),
      ),
    ),
  );
}

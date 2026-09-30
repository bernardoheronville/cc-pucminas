import 'package:flutter/material.dart';
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

class Habito {
  String nome;
  String descricao;
  int frequenciaSemanal;
  List<String> historico;

  Habito({
    required this.nome,
    required this.descricao,
    required this.frequenciaSemanal,
    List<String>? historico,
  }) : historico = historico ?? [];
}

class TelaPrincipal extends StatefulWidget {
  const TelaPrincipal({super.key});

  @override
  State<TelaPrincipal> createState() => _TelaPrincipalState();
}

class _TelaPrincipalState extends State<TelaPrincipal> {
  final List<Habito> _habitos = [
    Habito(
      nome: 'Beber Água',
      descricao: 'Beber pelo menos 2 litros por dia',
      frequenciaSemanal: 7,
    ),
    Habito(
      nome: 'Exercício',
      descricao: 'Caminhada ou academia',
      frequenciaSemanal: 5,
    ),
  ];

  void _adicionarHabito(Habito habito) {
    setState(() {
      _habitos.add(habito);
    });
  }

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
                  _adicionarHabito(
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
      appBar: AppBar(
        title: const Text('Diário de Hábitos'),
      ),
      body: _habitos.isEmpty
          ? const Center(child: Text('Nenhum hábito cadastrado.'))
          : ListView.builder(
              itemCount: _habitos.length,
              itemBuilder: (ctx, index) {
                final habito = _habitos[index];
                return Card(
                  margin: const EdgeInsets.symmetric(
                    horizontal: 12,
                    vertical: 6,
                  ),
                  child: ListTile(
                    title: Text(habito.nome),
                    subtitle: Text(
                      'Meta: ${habito.frequenciaSemanal}x/semana\n${habito.descricao}',
                    ),
                    isThreeLine: true,
                    trailing: const Icon(Icons.arrow_forward_ios, size: 16),
                    onTap: () async {
                      await Navigator.push(
                        context,
                        MaterialPageRoute(
                          builder: (context) => TelaDetalhe(habito: habito),
                        ),
                      );
                      setState(() {});
                    },
                  ),
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
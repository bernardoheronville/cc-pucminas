import 'package:flutter/material.dart';

void main() => runApp(const DiarioApp());

class Habito {
  final String nome;
  final String meta;
  final IconData icone;

  const Habito(this.nome, this.meta, this.icone);
}

Future<List<Habito>> carregarHabitos() async {
  await Future.delayed(const Duration(seconds: 4));
  //throw Exception('servidor fora do ar');
  return const [
    Habito('Beber água', 'Meta: 8 copos por dia', Icons.local_drink),
    Habito('Ler', 'Meta: 20 páginas por dia', Icons.menu_book),
    Habito('Caminhar', 'Meta: 30 minutos por dia', Icons.directions_walk),
    Habito('Dormir cedo', 'Meta: antes das 23h', Icons.bedtime),
  ];
  //return const [];
}

class DiarioApp extends StatelessWidget {
  const DiarioApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Meus Hábitos',
      home: TelaHabitos(futuro: carregarHabitos()), 
    );
  }
}

class TelaHabitos extends StatelessWidget {
  const TelaHabitos({super.key, required this.futuro});

  final Future<List<Habito>> futuro;

  @override
  Widget build(BuildContext context) => Scaffold(
    appBar: AppBar(title: const Text('Meus Hábitos')),
    body: FutureBuilder<List<Habito>>(
      future: futuro,
      builder: (context, snapshot) {
        if (snapshot.connectionState != ConnectionState.done) {
          return const Center(child: CircularProgressIndicator());
        }
        if (snapshot.hasError) {
          return const Center(child: Text('Não foi possível carregar'));
        }
        final habitos = snapshot.data!;
        if (habitos.isEmpty) {
          return const Center(child: Text('Nenhum hábito ainda'));
        }
        return ListView(
          children: [
            for (final h in habitos)
              ListTile(
                leading: Icon(h.icone),
                title: Text(h.nome),
                subtitle: Text(h.meta),
              ),
          ],
        );
      },
    ),
  );
}
import 'package:flutter/material.dart';

void main() => runApp(const DiarioApp());

class Habito {
  final String nome;
  final String meta;
  final IconData icone;

  const Habito(this.nome, this.meta, this.icone);
}

const habitos = [
  Habito('Beber água', 'Meta: 8 copos por dia', Icons.local_drink),
  Habito('Ler', 'Meta: 20 páginas por dia', Icons.menu_book),
  Habito('Caminhar', 'Meta: 30 minutos por dia', Icons.directions_walk),
  Habito('Dormir cedo', 'Meta: antes das 23h', Icons.bedtime),
  Habito('Jogar', 'Meta: 30 minutos por dia', Icons.gamepad)
];

class DiarioApp extends StatelessWidget {
  const DiarioApp({super.key});

  @override
  Widget build(BuildContext context) => MaterialApp(
    title: 'Diário de Hábitos',
    home: Scaffold(
      appBar: AppBar(title: const Text('Meus Hábitos')),
      body: ListView(
        children: [
          for (final h in habitos)
            ListTile(
              leading: Icon(h.icone),
              title: Text(h.nome),
              subtitle: Text(h.meta),
            ),
        ],
      ),
    ),
  );
}
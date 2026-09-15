import 'package:flutter/material.dart';

void main() => runApp(const AlbunsApp());

class Album {
  final String titulo;
  final String artista;
  final int faixas;

  const Album(this.titulo, this.artista, this.faixas);
}

const List<Album> albuns = [
  Album('Clube da Esquina', 'Milton Nascimento', 21),
  Album('Acabou Chorare', 'Novos Baianos', 9),
  Album('Tropicália', 'Vários', 12),
];

int menorAcervo(List<Album> lista) {
  int menor = lista.first.faixas;
  for (final a in lista) {
    if (a.faixas < menor) {
      menor = a.faixas;
    }
  }
  return menor;
}

class AlbunsApp extends StatelessWidget {
  const AlbunsApp({super.key});

  @override
  Widget build(BuildContext context) => MaterialApp(
    title: 'Álbuns',
    debugShowCheckedModeBanner: false,
    theme: ThemeData(
      colorScheme: ColorScheme.fromSeed(seedColor: const Color(0xFF1A5276)),
      useMaterial3: true,
    ),
    home: const TelaAlbuns(),
  );
}

class TelaAlbuns extends StatelessWidget {
  const TelaAlbuns({super.key});

  @override
  Widget build(BuildContext context) => Scaffold(
    appBar: AppBar(
      title: const Text('Álbuns'),
      backgroundColor: Theme.of(context).colorScheme.primary,
      foregroundColor: Colors.white,
      actions: [IconButton(icon: const Icon(Icons.search), onPressed: () {})],
    ),
    body: Column(
      children: [
        Expanded(
          child: ListView(
            children: [
              for (final a in albuns)
                ListTile(
                  leading: Row(
                    mainAxisSize: MainAxisSize.min,
                    children: const [
                      Icon(Icons.circle, color: Colors.green, size: 14),
                      SizedBox(width: 8),
                      Icon(Icons.album),
                    ],
                  ),
                  title: Text(a.titulo),
                  subtitle: Text('${a.artista} · ${a.faixas} faixas'),
                ),
            ],
          ),
        ),
        Container(
          width: double.infinity,
          padding: const EdgeInsets.all(12),
          color: Theme.of(context).colorScheme.secondaryContainer,
          child: Text(
            'menor: ${menorAcervo(albuns)} faixas',
            style: const TextStyle(fontWeight: FontWeight.bold),
          ),
        ),
      ],
    ),
  );
}

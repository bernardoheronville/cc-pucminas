import 'package:flutter/material.dart';
import 'models/habito.dart';
import 'stores/habito_store.dart';

class TelaDetalhe extends StatelessWidget {
  final Habito habito;
  final HabitoStore store;

  const TelaDetalhe({super.key, required this.habito, required this.store});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text(habito.nome)),
      body: Padding(
        padding: const EdgeInsets.all(16),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text('Nome: ${habito.nome}', style: const TextStyle(fontSize: 22)),
            const SizedBox(height: 8),
            Text('Meta: ${habito.frequenciaSemanal}x por semana'),
            const SizedBox(height: 8),
            Text('Posição na lista: ${store.posicaoDe(habito)} de ${store.total}'),
            const SizedBox(height: 24),
            ElevatedButton(
              onPressed: () {
                store.arquivar(habito);  
                Navigator.pop(context);   
              },
              child: const Text('Arquivar'),
            ),
          ],
        ),
      ),
    );
  }
}
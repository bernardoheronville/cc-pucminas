import 'package:flutter/material.dart';

import 'stores/habito_store.dart';
import 'ui/tela_habitos.dart';

void main() {
  runApp(const MeuApp());
}

class MeuApp extends StatelessWidget {
  const MeuApp({super.key});

  @override
  Widget build(BuildContext context) => MaterialApp(
    title: 'Diário de Hábitos',
    theme: ThemeData(
      colorScheme: ColorScheme.fromSeed(seedColor: const Color(0xFF1A5276)),
      useMaterial3: true,
    ),
    home: const TelaPrincipal(),
  );
}

class TelaPrincipal extends StatefulWidget {
  const TelaPrincipal({super.key});

  @override
  State<TelaPrincipal> createState() => _TelaPrincipalState();
}

class _TelaPrincipalState extends State<TelaPrincipal> {
  final store = HabitoStore();
  int _aba = 0;

  @override
  Widget build(BuildContext context) {
    final telas = [
      TelaHabitos(store: store),
      TelaResumo(store: store),
    ];

    return Scaffold(
      body: telas[_aba],
      bottomNavigationBar: NavigationBar(
        selectedIndex: _aba,
        onDestinationSelected: (i) => setState(() => _aba = i),
        destinations: const [
          NavigationDestination(icon: Icon(Icons.list), label: 'Hábitos'),
          NavigationDestination(icon: Icon(Icons.bar_chart), label: 'Resumo'),
        ],
      ),
    );
  }
}

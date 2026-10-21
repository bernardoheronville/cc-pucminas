import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import 'data/clubes_api.dart';
import 'screens/tela_clubes.dart';
import 'state/clubes_store.dart';

void main() => runApp(const App());

class App extends StatelessWidget {
  const App({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Clubes do Brasileirão',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        useMaterial3: true,
        colorScheme: ColorScheme.fromSeed(seedColor: const Color(0xFF1B7F3B)),
      ),
      home: ChangeNotifierProvider(
        create: (_) => ClubesStore(ClubesApi()),
        child: const TelaClubes(),
      ),
    );
  }
}

import 'package:flutter/material.dart';
import 'tela_cofre.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();
  runApp(const SegurancaApp());
}

class SegurancaApp extends StatelessWidget {
  const SegurancaApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Cofre Biométrico',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: const Color(0xFF1A5276)),
        useMaterial3: true,
      ),
      home: const TelaCofre(),
    );
  }
}
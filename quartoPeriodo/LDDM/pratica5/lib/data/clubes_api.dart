import 'dart:async';
import 'dart:convert';

import 'package:http/http.dart' as http;

import '../models/clube.dart';

class ErroDeRede implements Exception {
  const ErroDeRede(this.mensagem);
  final String mensagem;

  @override
  String toString() => mensagem;
}

class ClubesApi {
  static const _url = 'https://api.cartolafc.globo.com/clubes';

  Future<List<Clube>> carregar() async {
    final resposta = await _buscar();

    if (resposta.statusCode != 200) {
      throw ErroDeRede('O servidor respondeu ${resposta.statusCode}.');
    }

    final bruto = _decodificar(resposta.body);

    if (bruto is! Map) {
      throw const ErroDeRede('O servidor devolveu um formato inesperado.');
    }

    return bruto.values
        .whereType<Map>()
        .map((m) => Clube.fromMap(Map<String, Object?>.from(m)))
        .toList();
  }

  Future<http.Response> _buscar() async {
    try {
      return await http
          .get(Uri.parse(_url))
          .timeout(const Duration(seconds: 10));
    } on TimeoutException {
      throw const ErroDeRede('O servidor demorou demais para responder.');
    } on http.ClientException {
      throw const ErroDeRede('Sem conexão com a internet.');
    }
  }

  Object? _decodificar(String corpo) {
    try {
      return jsonDecode(corpo);
    } on FormatException {
      throw const ErroDeRede('A resposta do servidor não é um JSON válido.');
    }
  }
}

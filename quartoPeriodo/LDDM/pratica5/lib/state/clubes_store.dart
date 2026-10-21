import 'package:flutter/foundation.dart';

import '../data/clubes_api.dart';
import '../models/clube.dart';

enum Estado { carregando, pronto, erro }

enum Ordem { nome, classificacao }

class ClubesStore extends ChangeNotifier {
  ClubesStore(this._repo) {
    carregar(); 
  }

  final ClubesApi _repo;

  List<Clube> _clubes = [];
  Estado estado = Estado.carregando;
  String? mensagemErro;

  String _busca = '';
  Ordem _ordem = Ordem.nome;
  bool _descartado = false;

  String get busca => _busca;
  Ordem get ordem => _ordem;

  List<Clube> get todos => List.unmodifiable(_clubes);

  bool get temClassificacao => _clubes.any((c) => c.posicao != null);

  List<Clube> get visiveis {
    final termo = _busca.trim().toLowerCase();
    final lista = _clubes.where((c) {
      if (termo.isEmpty) return true;
      return c.nome.toLowerCase().contains(termo) ||
          c.apelido.toLowerCase().contains(termo) ||
          c.abreviacao.toLowerCase().contains(termo);
    }).toList();

    lista.sort((a, b) {
      if (_ordem == Ordem.classificacao) {
        return (a.posicao ?? 999).compareTo(b.posicao ?? 999);
      }
      return a.nome.toLowerCase().compareTo(b.nome.toLowerCase());
    });
    return lista;
  }

  void buscar(String texto) {
    _busca = texto;
    notifyListeners();
  }

  void ordenarPor(Ordem ordem) {
    _ordem = ordem;
    notifyListeners();
  }

  Future<void> carregar() async {
    estado = Estado.carregando;
    notifyListeners(); 
    try {
      _clubes = await _repo.carregar();
      estado = Estado.pronto;
    } on ErroDeRede catch (e) {
      estado = Estado.erro;
      mensagemErro = e.mensagem;
    } catch (_) {
      estado = Estado.erro;
      mensagemErro = 'Não foi possível carregar os clubes.';
    }
    if (_descartado) return;
    notifyListeners(); 
  }

  @override
  void dispose() {
    _descartado = true;
    super.dispose();
  }
}

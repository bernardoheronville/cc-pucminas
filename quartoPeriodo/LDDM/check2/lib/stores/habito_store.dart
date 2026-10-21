import 'package:flutter/foundation.dart';
import '../models/habito.dart';

class HabitoStore extends ChangeNotifier {
  final List<Habito> _habitos = [
      Habito(
        nome: 'Beber água',
        descricao: '8 copos por dia',
        frequenciaSemanal: 7,
        icone: 'agua',
      ),
      Habito(
        nome: 'Ler',
        descricao: '20 páginas por dia',
        frequenciaSemanal: 5,
        icone: 'leitura',
      ),
      Habito(
        nome: 'Caminhar',
        descricao: '30 minutos por dia',
        frequenciaSemanal: 4,
        icone: 'caminhada',
      ),
      Habito(
        nome: 'Dormir cedo',
        descricao: 'Antes das 23h',
        frequenciaSemanal: 7,
        icone: 'sono',
      ),
  ];

  List<Habito> get habitos => List.unmodifiable(_habitos);
  int get total => _habitos.length;

  int posicaoDe(Habito h) => _habitos.indexOf(h) + 1;

  void adicionar(Habito h) {
    _habitos.add(h);
    notifyListeners();
  }

  void remover(Habito h) {
    if (_habitos.remove(h)) {
      notifyListeners();
    }
  }

  void arquivar(Habito h) {
    if (_habitos.remove(h)) {
      _habitos.add(h); 
      notifyListeners();
    }
  }

  void favoritar(Habito h) {
    if (_habitos.remove(h)) {
      _habitos.insert(0, h);
      notifyListeners();
    }
  }
}
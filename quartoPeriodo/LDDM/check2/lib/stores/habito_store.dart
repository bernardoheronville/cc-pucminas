import 'package:flutter/foundation.dart';
import '../models/habito.dart';

class HabitoStore extends ChangeNotifier {
  final List<Habito> _habitos = [
    
  ];

  List<Habito> get habitos => List.unmodifiable(_habitos);
  int get total => _habitos.length;

  int posicaoDe(Habito h) => _habitos.indexOf(h) + 1;

  void adicionar(Habito h) {
    _habitos.add(h);
    notifyListeners();
  }

  void arquivar(Habito h) {
    if (_habitos.remove(h)) {
      _habitos.add(h); 
      notifyListeners();
    }
  }
}
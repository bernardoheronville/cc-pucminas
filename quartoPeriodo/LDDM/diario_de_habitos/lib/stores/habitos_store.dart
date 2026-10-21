import 'package:flutter/foundation.dart';
import '../dados/habitos_repositorio.dart';
import '../models/habito.dart';

class HabitosStore extends ChangeNotifier {
  HabitosStore([HabitosRepositorio? repositorio])
      : _repositorio = repositorio ?? HabitosRepositorio();

  final HabitosRepositorio _repositorio;

  List<Habito> _habitos = [];
  bool _carregando = true;
  String? _erro;

  List<Habito> get habitos => List.unmodifiable(_habitos);
  bool get carregando => _carregando;
  String? get erro => _erro;

  Future<void> carregar() async {
    try {
      _habitos = await _repositorio.carregar();
      _erro = null;
    } catch (e) {
      _erro = e.toString();
    }
    _carregando = false;
    notifyListeners();
  }

  Future<void> adicionarHabito(Habito habito) async {
    habito.id = await _repositorio.inserir(habito);
    _habitos.add(habito);
    notifyListeners();
  }

  Future<bool> registrarConclusao(Habito habito) async {
    final id = habito.id;
    if (id == null) return false;

    final hoje = DateTime.now();
    final dataFormatada =
        "${hoje.day.toString().padLeft(2, '0')}/${hoje.month.toString().padLeft(2, '0')}/${hoje.year}";

    if (habito.historico.contains(dataFormatada)) {
      return false;
    }

    await _repositorio.registrarConclusao(id, dataFormatada);
    habito.historico.add(dataFormatada);
    notifyListeners();
    return true;
  }
}

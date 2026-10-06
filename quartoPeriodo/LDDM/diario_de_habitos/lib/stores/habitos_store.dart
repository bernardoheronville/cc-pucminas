import 'package:mobx/mobx.dart';
import '../dados/habitos_repositorio.dart';
import '../models/habito.dart';

class HabitosStore {
  final HabitosRepositorio _repositorio;

  final ObservableList<Habito> habitos;

  HabitosStore([HabitosRepositorio? repositorio])
      : this._(repositorio ?? HabitosRepositorio());

  HabitosStore._(HabitosRepositorio repositorio)
      : _repositorio = repositorio,
        habitos = ObservableList<Habito>.of(repositorio.carregar());

  void adicionarHabito(Habito habito) {
    habitos.add(habito);
    _repositorio.salvar(habitos);
  }

  bool registrarConclusao(Habito habito) {
    final hoje = DateTime.now();
    final dataFormatada =
        "${hoje.day.toString().padLeft(2, '0')}/${hoje.month.toString().padLeft(2, '0')}/${hoje.year}";

    if (habito.historico.contains(dataFormatada)) {
      return false; 
    }

    habito.historico.add(dataFormatada);
    _repositorio.salvar(habitos);
    return true;
  }
}
import 'package:mobx/mobx.dart';
import '../models/habito.dart';

part 'habitos_store.g.dart';

class HabitosStore = _HabitosStoreBase with _$HabitosStore;

abstract class _HabitosStoreBase with Store {
  @observable
  ObservableList<Habito> habitos = ObservableList<Habito>.of([
    Habito(
      nome: 'Beber Água',
      descricao: 'Beber pelo menos 2 litros por dia',
      frequenciaSemanal: 7,
    ),
    Habito(
      nome: 'Exercício',
      descricao: 'Caminhada ou academia',
      frequenciaSemanal: 5,
    ),
  ]);

  @action
  void adicionarHabito(Habito habito) {
    habitos.add(habito);
  }

  @action
  bool registrarConclusao(Habito habito) {
    final hoje = DateTime.now();
    final dataFormatada =
        "${hoje.day.toString().padLeft(2, '0')}/${hoje.month.toString().padLeft(2, '0')}/${hoje.year}";

    if (!habito.historico.contains(dataFormatada)) {
      habito.historico.add(dataFormatada);
      habitos = ObservableList<Habito>.of(habitos);
      return true;
    }
    return false;
  }
}
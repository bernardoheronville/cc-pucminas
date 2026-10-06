import '../models/habito.dart';

class HabitosRepositorio {
  List<Habito> _guardados = [
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
  ];

  List<Habito> carregar() => List<Habito>.of(_guardados);

  void salvar(List<Habito> habitos) {
    _guardados = List<Habito>.of(habitos);
  }
}
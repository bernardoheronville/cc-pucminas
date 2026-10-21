class Habito {
  final String nome;
  final String descricao;
  final int frequenciaSemanal;
  final String icone;

  Habito({
    required this.nome,
    required this.descricao,
    required this.frequenciaSemanal,
    this.icone = 'padrao',
  });
}

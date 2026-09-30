class Habito {
  String nome;
  String descricao;
  int frequenciaSemanal;
  List<String> historico;

  Habito({
    required this.nome,
    required this.descricao,
    required this.frequenciaSemanal,
    List<String>? historico,
  }) : historico = historico ?? [];
}
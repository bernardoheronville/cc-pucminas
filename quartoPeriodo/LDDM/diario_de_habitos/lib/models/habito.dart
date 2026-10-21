class Habito {
  int? id;
  String nome;
  String descricao;
  int frequenciaSemanal;
  List<String> historico;

  Habito({
    this.id,
    required this.nome,
    required this.descricao,
    required this.frequenciaSemanal,
    List<String>? historico,
  }) : historico = historico ?? [];

  Map<String, Object?> toMap() => {
        'id': id,
        'nome': nome,
        'descricao': descricao,
        'frequencia_semanal': frequenciaSemanal,
      };

  factory Habito.fromMap(Map<String, Object?> m, {List<String>? historico}) =>
      Habito(
        id: m['id'] as int?,
        nome: m['nome'] as String,
        descricao: m['descricao'] as String,
        frequenciaSemanal: m['frequencia_semanal'] as int,
        historico: historico,
      );
}

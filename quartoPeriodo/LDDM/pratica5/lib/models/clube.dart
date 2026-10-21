class Clube {
  const Clube({
    required this.id,
    required this.nome,
    required this.abreviacao,
    required this.apelido,
    this.escudoUrl,
    this.posicao,
  });

  final int id;
  final String nome;
  final String abreviacao;
  final String apelido;
  final String? escudoUrl;
  final int? posicao;

  factory Clube.fromMap(Map<String, Object?> m) {
    String? escudo;
    final escudos = m['escudos'];
    if (escudos is Map) {
      escudo = escudos['60x60'] as String? ?? escudos['45x45'] as String?;
    }

    final nome = m['nome'] as String? ?? '(sem nome)';

    return Clube(
      id: (m['id'] as num?)?.toInt() ?? 0,
      nome: nome,
      abreviacao: m['abreviacao'] as String? ?? '---',
      apelido: m['apelido'] as String? ?? m['nome_fantasia'] as String? ?? nome,
      escudoUrl: escudo,
      posicao: (m['posicao'] as num?)?.toInt(),
    );
  }
}

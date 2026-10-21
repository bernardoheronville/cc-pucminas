import 'package:path/path.dart';
import 'package:sqflite/sqflite.dart';
import '../models/habito.dart';

class HabitosRepositorio {
  Future<Database>? _db;

  Future<Database> _abrir() => _db ??= _criarBanco();

  Future<Database> _criarBanco() async => openDatabase(
        join(await getDatabasesPath(), 'habitos.db'),
        version: 1,
        onConfigure: (db) => db.execute('PRAGMA foreign_keys = ON'),
        onCreate: (db, _) async {
          await db.execute(
            'CREATE TABLE habitos('
            'id INTEGER PRIMARY KEY AUTOINCREMENT, '
            'nome TEXT NOT NULL, '
            'descricao TEXT NOT NULL, '
            'frequencia_semanal INTEGER NOT NULL)',
          );
          await db.execute(
            'CREATE TABLE conclusoes('
            'id INTEGER PRIMARY KEY AUTOINCREMENT, '
            'habito_id INTEGER NOT NULL, '
            'data TEXT NOT NULL, '
            'UNIQUE(habito_id, data), '
            'FOREIGN KEY(habito_id) REFERENCES habitos(id) ON DELETE CASCADE)',
          );

          await db.insert('habitos', {
            'nome': 'Beber Água',
            'descricao': 'Beber pelo menos 2 litros por dia',
            'frequencia_semanal': 7,
          });
          await db.insert('habitos', {
            'nome': 'Exercício',
            'descricao': 'Caminhada ou academia',
            'frequencia_semanal': 5,
          });
        },
      );

  Future<List<Habito>> carregar() async {
    final db = await _abrir();
    final linhas = await db.query('habitos', orderBy: 'id ASC');
    final conclusoes = await db.query('conclusoes', orderBy: 'id ASC');

    final historicoPorHabito = <int, List<String>>{};
    for (final c in conclusoes) {
      historicoPorHabito
          .putIfAbsent(c['habito_id'] as int, () => [])
          .add(c['data'] as String);
    }

    return linhas
        .map((l) => Habito.fromMap(l, historico: historicoPorHabito[l['id'] as int]))
        .toList();
  }

  Future<int> inserir(Habito h) async {
    final db = await _abrir();
    return db.insert('habitos', h.toMap());
  }

  Future<void> registrarConclusao(int habitoId, String data) async {
    final db = await _abrir();
    await db.insert(
      'conclusoes',
      {'habito_id': habitoId, 'data': data},
      conflictAlgorithm: ConflictAlgorithm.ignore,
    );
  }
}

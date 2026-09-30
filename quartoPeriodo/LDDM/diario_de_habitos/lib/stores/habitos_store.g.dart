// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'habitos_store.dart';

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic, no_leading_underscores_for_local_identifiers

mixin _$HabitosStore on _HabitosStoreBase, Store {
  late final _$habitosAtom =
      Atom(name: '_HabitosStoreBase.habitos', context: context);

  @override
  ObservableList<Habito> get habitos {
    _$habitosAtom.reportRead();
    return super.habitos;
  }

  @override
  set habitos(ObservableList<Habito> value) {
    _$habitosAtom.reportWrite(value, super.habitos, () {
      super.habitos = value;
    });
  }

  late final _$_HabitosStoreBaseActionController =
      ActionController(name: '_HabitosStoreBase', context: context);

  @override
  void adicionarHabito(Habito habito) {
    final _$actionInfo = _$_HabitosStoreBaseActionController.startAction(
        name: '_HabitosStoreBase.adicionarHabito');
    try {
      return super.adicionarHabito(habito);
    } finally {
      _$_HabitosStoreBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  bool registrarConclusao(Habito habito) {
    final _$actionInfo = _$_HabitosStoreBaseActionController.startAction(
        name: '_HabitosStoreBase.registrarConclusao');
    try {
      return super.registrarConclusao(habito);
    } finally {
      _$_HabitosStoreBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  String toString() {
    return '''
habitos: ${habitos}
    ''';
  }
}

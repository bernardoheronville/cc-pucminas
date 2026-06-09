1.  Possui deadlock? Sim.

    Entre quais transações? No primeiro momento entre T1, T2 e T3. No segundo momento entre T2 e T3.

    Escalonamento efetivamente executado:A execução limpa será a T3 inteira, seguida da reinicialização de T1 e T2.

    r3(y), r3(z), w3(y), r3(x), c3, r1(x), r1(y), w1(x), r1(z), c1, r2(z), r2(x), r2(y), w2(z), c2

2.  Possui deadlock? Sim.

    Entre quais transações? Entre T2 e T3.

    Escalonamento efetivamente executado:
    As operações originais que deram certo (sem T2), finalizando T1, depois T3, e por fim o reinício de T2:
    
    r3(y), r1(x), r3(z), r1(y), w1(x), r1(z), c1, w3(y), r3(x), c3, r2(z), r2(x), r2(y), w2(z), c2

3.  Ele será composto pelo fluxo normal que sobreviveu sem o T3, seguido da reinicialização de T3:

    r2(z), r1(x), r2(x), r2(y), r1(y), w2(z), w1(x), r1(z), c2, c1, r3(y), r3(z), w3(y), r3(x), c3



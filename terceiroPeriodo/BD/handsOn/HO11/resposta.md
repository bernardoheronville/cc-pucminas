1. Atores

        Índice Primário:

                Tamanho do registro: 16 + 16 = 32 bytes

                Blocagem: 2048 / 32 = 64 | 64 registros por bloco

                Nível 1: 910 / 64 = 14,21 | 15 blocos necessários

                Nível 2: 910 / 64 = 14,21 | 15

                Nível 3: 15 / 64 = 0,23 | 1 

                Número de blocos necessários: 15 + 1 | 16 blocos necessários

                Espaço total gasto: 16 x 2048 = 32.768 bytes

                Numero de acessos a blocos: 2 + 1 = 3 

2. Funcionarios:

        Índice Primário:

                Tamanho do registro: 11 + 16 = 32 bytes

                Blocagem: 2048 / 27 = 75,85 | 75 registros por bloco

                Nível 1: 319 / 75 = 4,25 | 5 blocos necessários

                Nível 2: 319 / 75 = 4,25 | 5

                Nível 3: 5 / 75 = 0,06 | 1 

                Número de blocos necessários: 5 + 1 | 6 blocos necessários

                Espaço total gasto: 6 x 2048 = 12.288 bytes

                Numero de acessos a blocos: 2 + 1 = 3 

        Índice Secundário (Arvore B+):

                Nível Folha:

                        Tamanho do registro: 11 + 16 = 27 bytes

                        Blocagem: 2048 / 27 = 75,85 | 75 registros por bloco

                        Fator de Bloco: 75 x 0,69 = 51,75 | 52

                        # Blocos Folhas: 3.500 / 52 = 67,30 | 68 folhas

                Nós Internos:

                        Ordem Máxima: (p x 12) + ((p - 1) x 11) <= 2048 | p = 89 ponteiros

                        Fator de Bloco Interno: 89 x 0,69 = 61,41 | 62 ponteiros por bloco

                        # Nós Nível 2: 68 / 62 = 1,09 | 2

                        # Nós Nível 3: 2 / 62 = 0,03 | 1 

                Espaço Total:

                        Total de Blocos: 68 + 2 + 1 = 71

                        Espaço: 71 x 2048 = 145.408 bytes

                        Acesso: 3 + 1 = 4


3. Midias:

        Índice Primário:

                Tamanho do registro: 24 + 16 = 40 bytes

                Blocagem: 2048 / 40 = 51,2 | 51 registros por bloco

                Nível 1: 357.143 / 51 = 7002,80 | 7003 blocos necessários

                Nível 2: 7003 / 51 = 137,31 | 138

                Nível 3: 138 / 51 = 2,70 | 3

                Nível 4: 3 / 51 = 0,05 | 1

                Número de blocos necessários: 7003 + 138 + 3 + 1 | 7145 blocos necessários

                Espaço total gasto: 7145 x 2048 = 14.632.960 bytes

                Numero de acessos a blocos: 4 + 1 | 5 

        Índice Secundário (Arvore B+):

                Nível Folha:

                        Tamanho do registro: 16 + 16 = 32 bytes

                        Blocagem: 2048 / 32 = 64 | 64 registros por bloco

                        Fator de Bloco: 64 x 0,69 = 44,16 | 45

                        # Blocos Folhas: 10.000.000 / 45 = 222222,22 | 222223 folhas

                Nós Internos:

                        Ordem Máxima: (p x 12) + ((p - 1) x 16) <= 2048 | p = 73 ponteiros

                        Fator de Bloco Interno: 73 x 0,69 = 50,37 | 51 ponteiros por bloco

                        # Nós Nível 2: 222223 / 51 = 4357,31 | 4358

                        # Nós Nível 3: 4358 / 51 = 85,45 | 86 

                        # Nós Nível 4: 86 / 51 = 1,68 | 2

                        # Nós Nível 5: 2 / 51 = 0,03 | 1

                Espaço Total:

                        Total de Blocos: 222223 + 4358 + 86 + 2 + 1 = 226.670

                        Espaço: 226.670 x 2048 = 464.220.160 bytes

                        Acesso: 5 + 1 = 6

4. Aluguel:

        Índice Primário:

                Tamanho do registro: 47 + 16 = 63 bytes

                Blocagem: 2048 / 63 = 32,5 | 32 registros por bloco

                Nível 1: 909.091 / 32 = 28409,09 | 28.410 

                Nível 2: 28.410 / 32 = 887,8125 | 888

                Nível 3: 888 / 32 = 27,75 | 28

                Nível 4: 28 / 32 = 0,875 | 1

                Número de blocos necessários: 28.410 + 888 + 28 + 1 | 29.327 blocos necessários

                Espaço total gasto: 29.327 x 2048 = 60.061.696 bytes

                Numero de acessos a blocos: 4 + 1 | 5

        Índice Secundário de CPF_Cliente (Arvore B+):

                Nível Folha:

                        Tamanho do registro: 11 + 16 = 27 bytes

                        Blocagem: 2048 / 27 = 75,85 | 75 registros por bloco

                        Fator de Bloco: 75 x 0,69 = 51,75 | 52

                        # Blocos Folhas: 20.000.000 / 52 = 384.615,38 | 384.616 folhas

                Nós Internos:

                        Ordem Máxima: (p x 12) + ((p - 1) x 11) <= 2048 | p = 89 ponteiros

                        Fator de Bloco Interno: 89 x 0,69 = 61,41 | 62 ponteiros por bloco

                        # Nós Nível 2: 384.616 / 62 = 6203,48 | 6.204

                        # Nós Nível 3: 6.204 / 62 = 100,06 | 101

                        # Nós Nível 4: 101 / 62 = 1,62 | 2

                        # Nós Nível 5: 2 / 62 = 0,03 | 1

                Espaço Total:

                        Total de Blocos: 384.616 + 6.204 + 101 + 2 + 1 = 390.924

                        Espaço: 390.924 x 2048 = 800.612.352 bytes

                        Acesso: 5 + 1 = 6

        Índice Secundário de ID_Mídia (Arvore B+):

                Nível Folha:

                        Tamanho do registro: 24 + 16 = 40 bytes

                        Blocagem: 2048 / 40 = 51,2 | 51 registros por bloco

                        Fator de Bloco: 51 x 0,69 = 35,19 | 36

                        # Blocos Folhas: 20.000.000 / 36 = 555.555,55 | 555.556 folhas

                Nós Internos:

                        Ordem Máxima: (p x 12) + ((p - 1) x 24) <= 2048 | p = 57 ponteiros

                        Fator de Bloco Interno: 57 x 0,69 = 39,33 | 40 ponteiros por bloco

                        # Nós Nível 2: 555.556 / 40 = 13.888,9 | 13.889

                        # Nós Nível 3: 13.889 / 40 = 347,22 | 348

                        # Nós Nível 4: 348 / 40 = 8,7 | 9

                        # Nós Nível 5: 9 / 40 = 0,22 | 1

                Espaço Total:

                        Total de Blocos: 555.556 + 13.889 + 348 + 9 + 1 = 569.803

                        Espaço: 569.803 x 2048 = 1.166.956.544 bytes

                        Acesso: 5 + 1 = 6

        Índice Secundário de CPF_Funcionario (Arvore B+):

                Nível Folha:

                        Tamanho do registro: 11 + 16 = 27 bytes

                        Blocagem: 2048 / 27 = 75,85 | 75 registros por bloco

                        Fator de Bloco: 75 x 0,69 = 51,75 | 52

                        # Blocos Folhas: 20.000.000 / 52 = 384.615,38 | 384.616 folhas

                Nós Internos:

                        Ordem Máxima: (p x 12) + ((p - 1) x 11) <= 2048 | p = 89 ponteiros

                        Fator de Bloco Interno: 89 x 0,69 = 61,41 | 62 ponteiros por bloco

                        # Nós Nível 2: 384.616 / 62 = 6203,48 | 6.204

                        # Nós Nível 3: 6.204 / 62 = 100,06 | 101

                        # Nós Nível 4: 101 / 62 = 1,62 | 2

                        # Nós Nível 5: 2 / 62 = 0,03 | 1

                Espaço Total:

                        Total de Blocos: 384.616 + 6.204 + 101 + 2 + 1 = 390.924

                        Espaço: 390.924 x 2048 = 800.612.352 bytes

                        Acesso: 5 + 1 = 6

5. Cliente:

        Índice Primário:

                Tamanho do registro: 11 + 16 = 27 bytes

                Blocagem: 2048 / 27 = 75,85 | 75 registros por bloco

                Nível 1: 20000 / 75 = 266,66 | 267

                Nível 2: 267 / 75 = 3,56 | 4

                Nível 3: 4 / 75 = 0,05 | 1

                Número de blocos necessários: 267 + 4 + 1 | 272 blocos necessários

                Espaço total gasto: 272 x 2048 = 557.056 bytes

                Numero de acessos a blocos: 3 + 1 | 4
6. Filmes:

        Índice Primário:

                Tamanho do registro: 16 + 16 = 32 bytes

                Blocagem: 2048 / 32 = 64 | 64 registros por bloco

                Nível 1: 250.000 / 64 = 3906,25 | 3907

                Nível 2: 3907 / 64 = 61,04 | 62

                Nível 3: 62 / 64 = 0,96 | 1

                Número de blocos necessários: 3907 + 62 + 1 | 3970 blocos necessários

                Espaço total gasto: 3970 x 2048 = 8.130.560 bytes

                Numero de acessos a blocos: 3 + 1 = 4

7. Pagamentos:

        Índice Primário:

                Tamanho do registro: 48 + 16 = 64 bytes

                Blocagem: 2048 / 64 = 32 | 32 registros por bloco

                Nível 1: 3.333.334 / 32 = 104.166,68 | 104.167

                Nível 2: 104.167 / 32 = 3255,21 | 3256

                Nível 3: 3256 / 32 = 101,75 | 102

                Nível 4: 102 / 32 = 3,18 | 4

                Nível 5: 4 / 32 = 0,12 | 1

                Número de blocos necessários: 104.167 + 3.256 + 102 + 4 + 1 | 107.530 blocos necessários

                Espaço total gasto: 107.530 x 2048 = 220.221.440 bytes

                Numero de acessos a blocos: 5 + 1 = 6

        Índice Secundário (Arvore B+):

                Nível Folha:

                        Tamanho do registro: 47 + 16 = 63 bytes

                        Blocagem: 2048 / 63 = 32,50 | 32 registros por bloco

                        Fator de Bloco: 32 x 0,69 = 22,08 | 23

                        # Blocos Folhas: 50.000.000 / 23 = 2.173.913,04 | 2.173.914 folhas

                Nós Internos:

                        Ordem Máxima: (p x 12) + ((p - 1) x 47) <= 2048 | p = 35 ponteiros

                        Fator de Bloco Interno: 35 x 0,69 = 24,15 | 25 ponteiros por bloco

                        # Nós Nível 2: 2.173.914 / 25 = 86.956,56 | 86.957

                        # Nós Nível 3: 86.957 / 25 = 3.478,28 | 3.479

                        # Nós Nível 4: 3.479 / 25 = 139,16 | 140

                        # Nós Nível 5: 140 / 25 = 5,6 | 6

                        # Nós Nível 6: 6 / 25 = 0,24 | 1

                Espaço Total:

                        Total de Blocos: 2.173.914 + 86.957 + 3.479 + 140 + 6 + 1 = 2.264.497

                        Espaço: 2.264.497 x 2048 = 4.637.689.856 bytes

                        Acesso: 6 + 1 = 7

8. AtoresEmFilmes:

        Índice Primário:

                Tamanho do registro: 32 + 16 = 48 bytes

                Blocagem: 2048 / 48 = 42,66 | 42 registros por bloco

                Nível 1: 15.625 / 42 = 372,02 | 373

                Nível 2: 373 / 42 = 8,88 | 9

                Nível 3: 9 / 42 = 0,21 | 1

                Número de blocos necessários: 373 + 9 + 1 | 383 blocos necessários

                Espaço total gasto: 383 x 2048 = 784.384 bytes

                Numero de acessos a blocos: 3 + 1 = 4

        Índice Secundário (CodFilme):

                Tamanho do registro: 16 + 16 = 32 bytes

                Blocagem: 2048 / 32 = 64 | 64 registros por bloco

                Espaço desperdiçado por bloco: 32 x 64 = 2048 2048 - 2048 = 0 bytes desperdiçados por bloco

                Número de blocos necessários: 1.000.000 / 64 = 15625 | 15625 blocos necessários

                Espaço total gasto: 15625 x 2048 = 32.000.000 bytes

                Numero de acessos a blocos: log na base 2 de 15625 = 13.9 | 14 + 1 = 15

        Índice Secundário (CodAtor):

                Tamanho do registro: 16 + 16 = 32 bytes

                Blocagem: 2048 / 32 = 64 | 64 registros por bloco

                Espaço desperdiçado por bloco: 32 x 64 = 2048 2048 - 2048 = 0 bytes desperdiçados por bloco

                Número de blocos necessários: 1.000.000 / 64 = 15625 | 15625 blocos necessários

                Espaço total gasto: 15625 x 2048 = 32.000.000 bytes

                Numero de acessos a blocos: log na base 2 de 15625 = 13.9 | 14 + 1 = 15

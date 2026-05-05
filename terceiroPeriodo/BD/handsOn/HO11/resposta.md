1. Atores

        Índice Primário:

                Tamanho do registro: 16 + 16 = 32 bytes

                Blocagem: 2048 / 32 = 64 | 64 registros por bloco

                Nível 1: 910 / 64 = 14,21 | 15

                Nível 2: 15 / 64 = 0,23 | 1 

                Número de blocos necessários: 15 + 1 | 16 blocos necessários

                Espaço total gasto: 16 x 2048 = 32.768 bytes

                Numero de acessos a blocos: 2 + 1 = 3 

2. Funcionarios:

        Índice Primário:

                Tamanho do registro: 11 + 16 = 32 bytes

                Blocagem: 2048 / 27 = 75,85 | 75 registros por bloco

                Nível 1: 319 / 75 = 4,25 | 5

                Nível 2: 5 / 75 = 0,06 | 1 

                Número de blocos necessários: 5 + 1 | 6 blocos necessários

                Espaço total gasto: 6 x 2048 = 12.288 bytes

                Numero de acessos a blocos: 2 + 1 = 3 

        Índice Secundário:

                Tamanho do registro: 11 + 16 = 27 bytes

                Blocagem: 2048 / 27 = 75,85 | 75 registros por bloco

                Espaço desperdiçado por bloco: 27 x 75 = 2025 2048 - 2025 = 23 bytes desperdiçados por bloco

                Número de blocos necessários: 3500 / 75 = 46,66 | 47 blocos necessários

                Espaço total gasto: 47 x 2048 = 96256 bytes

                Numero de acessos a blocos: log na base 2 de 47 = 5.5 | 6 + 1 = 7

3. Midias:

        Índice Primário:

                Tamanho do registro: 24 + 16 = 40 bytes

                Blocagem: 2048 / 40 = 51,2 | 51 registros por bloco

                Espaço desperdiçado por bloco: 40 x 51 = 2040 2048 - 2040 = 8 bytes desperdiçados por bloco

                Número de blocos necessários: 357.143 / 51 = 7002,80 | 7003 blocos necessários

                Espaço total gasto: 7003 x 2048 = 14342144 bytes

                Numero de acessos a blocos: log na base 2 de 7003 = 12.77 | 13 + 1 = 14

        Índice Secundário:

                Tamanho do registro: 16 + 16 = 32 bytes

                Blocagem: 2048 / 32 = 64 | 64 registros por bloco

                Espaço desperdiçado por bloco: 32 x 64 = 2048 2048 - 2048 = 0 bytes desperdiçados por bloco

                Número de blocos necessários: 10.000.000 / 64 = 156250 | 156250 blocos necessários

                Espaço total gasto: 156250 x 2048 = 320000000 bytes

                Numero de acessos a blocos: log na base 2 de 156250 = 18 | 18 + 1 = 19

4. Aluguel:

        Índice Primário:

                Tamanho do registro: 47 + 16 = 63 bytes

                Blocagem: 2048 / 63 = 32,5 | 32 registros por bloco

                Espaço desperdiçado por bloco: 63 x 32 = 2016 2048 - 2016 = 32 bytes desperdiçados por bloco

                Número de blocos necessários: 909.091 / 32 = 28409,09 | 28.410 blocos necessários

                Espaço total gasto: 28.410 x 2048 = 58.183.680 bytes

                Numero de acessos a blocos: log na base 2 de 28.410 = 14.7 | 15 + 1 = 16

        Índice Secundário (CPF_Cliente):

                Tamanho do registro: 11 + 16 = 27 bytes

                Blocagem: 2048 / 27 = 75,85 | 75 registros por bloco

                Espaço desperdiçado por bloco: 27 x 75 = 2025 2048 - 2025 = 23 bytes desperdiçados por bloco

                Número de blocos necessários: 20.000.000 / 75 = 266666,66 | 266.667 blocos necessários

                Espaço total gasto: 266.667 x 2048 = 546.134.016 bytes

                Numero de acessos a blocos: log na base 2 de 266.667 = 18.02 | 19 + 1 = 20

        Índice Secundário (ID_Midia):

                Tamanho do registro: 24 + 16 = 40 bytes

                Blocagem: 2048 / 40 = 51,2 | 51 registros por bloco

                Espaço desperdiçado por bloco: 40 x 51 = 2040 2048 - 2040 = 8 bytes desperdiçados por bloco

                Número de blocos necessários: 20.000.000 / 51 = 392156,86 | 392.157 blocos necessários

                Espaço total gasto: 392.157 x 2048 = 803.137.536 bytes

                Numero de acessos a blocos: log na base 2 de 392.157 = 18.58 | 19 + 1 = 20

        Índice Secundário (CPF_Funcionario):

                Tamanho do registro: 11 + 16 = 27 bytes

                Blocagem: 2048 / 27 = 75,85 | 75 registros por bloco

                Espaço desperdiçado por bloco: 27 x 75 = 2025 2048 - 2025 = 23 bytes desperdiçados por bloco

                Número de blocos necessários: 20.000.000 / 75 = 266666,66 | 266.667 blocos necessários

                Espaço total gasto: 266.667 x 2048 = 546.134.016 bytes

                Numero de acessos a blocos: log na base 2 de 266.667 = 18.02 | 19 + 1 = 20

5. Cliente:

        Índice Primário:

                Tamanho do registro: 11 + 16 = 27 bytes

                Blocagem: 2048 / 27 = 75,85 | 75 registros por bloco

                Espaço desperdiçado por bloco: 27 x 75 = 2025 2048 - 2025 = 23 bytes desperdiçados por bloco

                Número de blocos necessários: 20000 / 75 = 266,66 | 267 blocos necessários

                Espaço total gasto: 267 x 2048 = 546.816 bytes

                Numero de acessos a blocos: log na base 2 de 267 = 8.06 | 9 + 1 = 10

6. Filmes:

        Índice Primário:

                Tamanho do registro: 16 + 16 = 32 bytes

                Blocagem: 2048 / 32 = 64 | 64 registros por bloco

                Espaço desperdiçado por bloco: 32 x 64 = 2048 2048 - 2048 = 0 bytes desperdiçados por bloco

                Número de blocos necessários: 250.000 / 64 = 3906,25 | 3907 blocos necessários

                Espaço total gasto: 3907 x 2048 = 8.001.536 bytes

                Numero de acessos a blocos: log na base 2 de 3907 = 11.9 | 12 + 1 = 13

7. Pagamentos:

        Índice Primário:

                Tamanho do registro: 48 + 16 = 64 bytes

                Blocagem: 2048 / 64 = 32 | 32 registros por bloco

                Espaço desperdiçado por bloco: 64 x 32 = 2048 2048 - 2048 = 0 bytes desperdiçados por bloco

                Número de blocos necessários: 3.333.334 / 32 = 104.166,68 | 104.167 blocos necessários

                Espaço total gasto: 104167 x 2048 = 213.334.016 bytes

                Numero de acessos a blocos: log na base 2 de 104167 = 16.67 | 17 + 1 = 18

        Índice Secundário:

                Tamanho do registro: 11 + 24 + 12 + 16 = 63 bytes

                Blocagem: 2048 / 63 = 32,2 | 32 registros por bloco

                Espaço desperdiçado por bloco: 32 x 63 = 2016 2048 - 2016 = 32 bytes desperdiçados por bloco

                Número de blocos necessários: 50.000.000 / 32 = 1.562.500 | 1.562.500 blocos necessários

                Espaço total gasto: 1.562.500 x 2048 = 3.200.000.000 bytes

                Numero de acessos a blocos: log na base 2 de 1.562.500 = 20,57 | 21 + 1 = 22

8. AtoresEmFilmes:

        Índice Primário:

                Tamanho do registro: 32 + 16 = 48 bytes

                Blocagem: 2048 / 48 = 42,66 | 42 registros por bloco

                Espaço desperdiçado por bloco: 42 x 48 = 2016 2048 - 2016 = 32 bytes desperdiçados por bloco

                Número de blocos necessários: 15.625 / 42 = 372,02 | 373 blocos necessários

                Espaço total gasto: 373 x 2048 = 763.904 bytes

                Numero de acessos a blocos: log na base 2 de 373 = 8.5 | 9 + 1 = 10

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

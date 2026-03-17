## 10/03/2026 - 6.5-6.6
* Vetor: Coleção homogênea de elementos os quais são identificados por seu indice/posição (relativa à do 1)
* Elementos são referenciados por meio de um mecanismo sintático de dois níveis
    * 1: Nome do vetor
    * 2: Seletor/Índice composto por 1 ou + itens 

        nome_vetor (seletor)-> elemento
* Se as referências do seletor são constantes, então é estático. Senão, é dinâmico
* Categorias 
    * Estática: Tamanho e alocação
    
            char * msg = "Ola Mundo";
    * Fixo e dinâmico em pilha: Tamanho estático Alocação dinâmica 
```c
            char s[1024]; // em uma função
```
* Fixo e dinâmico em heap: Requisitado pelo usuário e feito em tempo de execução 
```c
| int *v = malloc(n * sizeof(int));
```
* Dinâmico em heap: A amarração é feita em tempo de execução e pode alterar durante a eecução
```c#
| List <String> s = new List<String>;
```
* Operações: Atribuição, Concatenação, Comparação e slices
* Retangular: Vetor multidimensional de tamanho regular
* Irregular: Vetor multidimensional cujo tamanho das linhas é diferente
* Slice: Sub estrutura do vetor. Não é um novo tipo mas uma referência 


* Multidimensionais p/ unidimensionais 
    * Row major order e Column major order

            location(a[i, j]) = &(a[raw_lb, col_lb]) - (((row_lb * n) + col_lb) * elem-size) + ((i * n) + j) + elem-size
    | Campo do Descritor ||
    | :--- | :--- |
    | **Mult. Array** |
    | **Elem. Type** |
    | **Index Type** |
    | **# Dimensions** |
    | **Index 0** |
    | **Index 1** |
    | **...** |
    | **Endereço** |
* Vetor associado: Coleção não ordenada de elementos indexados por valores chamado.
```c
| int *cpfs;
| float *notas;
| char **nome;
```
## 12/03 - Cap 6.7-6.10
* Registro: Coleção de dados no qual elementos individuais são referenciados por nomes e acessados via offset

        C: struct Aluno {
                int cpf;
                float nota;
                char *nome
           };
* Elementos não precisam ser do mesmo tipo e/ou tamanho

        |void **obj; // Não é registro
* No registro, os elementos ESTÂO contígidos na memória

        Aluno *a = new Aluno();
        // a ->cpf; a.cpf; Campo
* Fully qualified: Refefência a um campo explicitando todos os nomes intermediários

        | cout << curso[c].aluno[a].disciplica[d].nota[p1];
* Elliptical: O campo é nomeado, mas os nomes intermediários podem ser omitidos.

        | Disciplina *d = &(curso[c].aluno[a].disciplina[d]);
        | cout << d->nota[p1]; // NÃO É ELIPTICO
* 
    | Registro ||
    | :--- | :--- |
    | **Nome** |
    | **Tipo** |
    | **Offset** |
    | **Nome** |
    | **Tipo** |
    | **Offset** |
    | **...** |
    | **Endereço** |
* Tuplas: Similar à um registro, mas seus elementos não são nomeados

        | par = (100, 'maçã') # imutável
* Lista: 

        | lista = [3, 5.8, 'uva']

* List comprehension: Deriva da teoria de conjuntos uma função é aplicada a cada elementos, construindo um novo conjunto

```python
| [x * x for x in range(12) if x % 3 == 0]
| # [0,9,36,81]
```
* Union (Registro Variável): Tipos cujas variáveis podem ter valores de tipos de diferentes durante a execução do código

```c
| union pixel {
|        char b;
|        int i;
|        float f;
| };
| pixel p; p*b = 'A'; p.i = 1024;
| print("%c", p.b); // '\0'
```
* Free union: Programadores estão "livres" da verificaçao de tipos
* Discriminated union: Requer que cada registro variante inclua um tipo indicador (tag)

## 17/03 - Cap 6.11

* Ponteiros: Tipo cujos valores possíveis são endereços de memória ou um valor especial (Nulo)
* Endereçamento indireto e gerenciamento de memória dinâmica (heap)
* Variáveis anônimas: Variáveis não nomeadas
```c++ 
| int *v = new int[n];
| // Variável heap dinâmica
``` 
* Aumenta a redigibilidade
* Atribuição e Deferenciamento: 

1. Armazena o endereço de uma variável;
1. Referencia ao valor do endereço contido no ponteiro
```c
| //malloc e new; free e delete
| //&
| int &p, q; /* int p, q; */
| p = q; /* p = &q; */
```
* Ponteiro pendente: Contém o denreço de uma variável heap dinâmica já desalocada
```c++
| int *p1, *p2;
| p1 = new int[100];
| p2 = p1;
| delete[] p1;
```
* Vazamento de memória: Variável heap dinâmica que não é acessada pelo programa 
```c 
| int *p = malloc(sizeof(int));
| p = malloc(sizeof(int));
| void qsort(void* v, size_t n, size_t b, int(void*, void*)*f);
```
* Referência: Similar a ponteiro, mas referência um objeto ou valor na memória
```c++
| int r = 0;
| int &q = r;
| q = 100;
```
```c
void f(int &v){ v*=v;}
void f(int *v){*(v) *= (*v);}
//
f(x);
f(&x);
```

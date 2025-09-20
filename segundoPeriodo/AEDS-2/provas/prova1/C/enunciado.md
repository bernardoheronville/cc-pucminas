# Placas de Carros

As placas usadas nos carros em circulação no Brasil possuem dois padrões com formatos diferentes: algumas placas estão no antigo padrão Brasileiro, enquanto outras estão no novo padrão Mercosul.

O antigo padrão Brasileiro é sempre formado por 8 caracteres:

os três primeiros caracteres são letras maiúsculas (de A a Z);
o quarto caractere é um hífen (-);
os últimos quatro caracteres são dígitos (de 0 a 9).

Por exemplo, OBI-2024 é uma placa válida no antigo padrão Brasileiro.

O novo padrão Mercosul, por sua vez, é sempre formado por 7 caracteres:
os três primeiros caracteres são letras maiúsculas;
o quarto caractere é um dígito;
o quinto caractere é uma letra maiúscula;
os últimos dois caracteres são dígitos.

Assim, OBI2P24 é uma placa válida no novo padrão Mercosul.

Há também um grande contigente de carros em situação irregular – carros com placas falsificadas que não estão nem no antigo padrão Brasileiro, nem no novo padrão Mercosul. Por exemplo, um carro com a placa OBI-24 está em situação irregular, pois a placa não é válida em nenhum dos dois padrões.

O Departamento Nacional de Trânsito identificou que seus funcionários gastam muito tempo verificando manualmente quais placas estão em qual padrão e quais são falsificadas.

Por isso, eles pediram sua ajuda para automatizar o processo: dada uma placa formada por uma sequência de letras maiúsculas, dígitos e hífens, determine se a placa está no antigo padrão Brasileiro, está no novo padrão Mercosul, ou é uma placa falsificada.

## Entrada
A entrada é composta de uma única linha, contendo uma sequência de caracteres representando a placa a ser analisada.


## Saída
Seu programa deverá imprimir uma linha contendo um único número inteiro:

1, se a placa está no antigo padrão Brasileiro;
2, se a placa está no novo padrão Mercosul;
0, se a placa é falsificada.
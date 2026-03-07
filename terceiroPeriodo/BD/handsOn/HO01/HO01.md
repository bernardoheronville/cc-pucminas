## Responder as seguintes perguntas:
### 1. O que é um sistema de banco de dados (SBD)?
* SBD referem-se ao conjunto de dados relacionados e sua respectiva forma de acesso e organização.
### 2. Do que um SBD é composto?
* Os SBD são compostos por uma coleção de dados organizados, uma estrutura lógica determinando a forma como os dados são armazenados, organizados e manipulados.
### 3. Como usuários e aplicações interagem com um SBD?
* Usuários e aplicações interagem com o sistema submetendo consultas, consultas são interpretadas pelo sistema, que realiza otimizações necessárias para sua correta execução. O próprio sistema decide quais dados são necessários para responder uma consulta e se encarrega de recuperá-los a partir dos repositórios sob seu controle.
### 4. O que é um banco de dados (BD)? Cite um exemplo de um BD, indicando o link onde seja possível encontrá-lo.
* BD é uma coleção de dados organizados. Ex. Cadastro Nacional da Pessoa Jurídica (CNPJ) Link: basedosdados.org
### 5. Quais são as propriedades de um BD?
* Finalidade: construídos com um propósito específico.
* Realidade: representam o mundo real.
* Coerência: mantêm a coerência lõgica da coleção.
* Compartilhamento: provêm compartilhamento de dados.
### 6. Quais são as etapas de um projeto de BD?
* Modelos, etapas de implementação e sempre sendo revisado.
### 7. O que é um sistema gerenciador de banco de dados (SGBD)?
* Coleção de programas que permitem aos usuários criar e manter BDs.
    * Definir: especificar tipos, estruturas e restrições armazenadas sob forma de metadados no catálogo do sistema.
    * Construir: armazenar dados em meio controlado pelo SGBD.
    * Manipular: inserir, remover, modificar e recuperar dados.
    * Compartilhar: prover acesso simultâneo a múltiplos usuários.
### 8. Quais são as propriedades de um SGBD?
* Flexibilidade
* Múltiplas interfaces
* Economia de escala
* Garantia de padrões 
* Restrições de acesso
* Backup e recuperação
* Disponibilidade elevada
* Restrições de integridade
* Tempo de desenvolvimento
* Relacionamentos complexos
### 9. Indique situações em que o uso de SGBD pode se mostrar inadequado.
* Monousuário: acesso por múltiplos usuários não requerido.
* Baixa complexidade: aplicações muito simples e bem definidas.
* Requisitos rigorosos: aplicações de tempo real, de alta escalabilidade e sistemas embarcados com capacidade de armazenamento limitada.
* Alta especialização: aplicações que demandam recursos que a generalidade oferecida pelo SGBD para definição e processamentos de dados não suporta.
* Custo proibitivo: impossibilidade de investimento inicial significativo em hardware, software e treinamento.
### 10. O que é um modelo de dados?
* Estrutura lógica que determina a forma como os dados são armazenados, organizados e manipulados
    * Coleção de conceitos que descrevem a estrutura do BD.
    * Incorpora operações para especificar atualização e recuperação de dados.
    * Define o comportamento de uma determinada aplicação.
### 11. Em relação ao nível de abstração, quais são os tipos de modelos de dados?
* Conceitual: alto nível de abstração
    * Representa a estrutura como os usuários a percebem
    * Conceitos: entidade, atributo e relacionamento
* Representativo: nível intermediário de abstração
    * Também conhecido como modelo de implementação
    * Representa a estrutura detalhando aspectos de implementação
    * Oculta detalhes de armazenamento físico
    * Conceitos: objetos, relação, tupla e coluna
* Físico: baixo nível de abstração
    * Representa a estrutura detalhando aspectos de armazenamento físico
    * Conceitos: arquivo, registro, campo e índice
### 12. O que é um Esquema de BD?
* Descrição do banco de dados
    * Especificado no projeto e não muda com frequência
    * Existem convenções para se representar esquemas usando diagramas
    * Diagrama de esquema
    * Construtor de esquema
### 13. O que é uma Instância de BD?
* Conjunto de dados armazenados em determinado momento
    * Estado vazio: esquema especificado, mas nenhum dado armazenado
    * Estado inicial: BD carregado com dados iniciais
    * Estado se altera ao se inserir, remover ou modificar o valor de um item
### 14. Quais as vantagens de se adotar uma Arquitetura de Três Esquemas para implementar um BD?
* Abordagem que permite visualização do esquema em diferentes níveis
    * Autodescrição: metadados descritivos e diferentes níveis de abstração, de acordo com características estruturais
    * Suporte a múltiplas visões: usuários e aplicações têm acesso restrito a porções do BD suficintes para atender suas necessidades
    * Independência de aplicação: estrutura do BD armazenada separadamente de aplicações, garantindo que alterações na estrutura não necessariamente levem a mudanças em aplicações
### 15. Quais níveis existem em uma Arquitetura de Três Esquemas?
* Nível externo
* Nível conceitual
* Nível interno
### 16. O que é Mapeamento em uma Arquitetura de Três Esquemas?
* Transformação de requisições e resultados entre níveis
### 17. O que é Independência de Dados e qual sua importância para um SBD?
* Capacidade de se alterar o esquema em um nível sem precisar alterar o esquema no nível adjacente superior
### 18. O que é uma Linguagem de Consulta?
* Linguagem de consulta são as linguagens de alto nível não procedural, por ser usada de maneira interativa
### 19. Cite as linguagens incorporadas na linguagem SQL.
* VDL, DDL, SDL, DML

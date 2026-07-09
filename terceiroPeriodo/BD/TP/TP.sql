CREATE DATABASE bd_basilica_doacoes;
USE bd_basilica_doacoes;

CREATE TABLE INSTITUICAO (
    Codigo INT PRIMARY KEY,
    Nome VARCHAR(100) NOT NULL,
    Endereco VARCHAR(200) NOT NULL,
    Telefone VARCHAR(20)
);

CREATE TABLE DOADOR (
    Documento VARCHAR(20) PRIMARY KEY,
    Nome VARCHAR(100) NOT NULL,
    Telefone VARCHAR(20)
);

CREATE TABLE RECEPTOR (
    CPF VARCHAR(14) PRIMARY KEY,
    Nome VARCHAR(100) NOT NULL,
    Vulnerabilidade TEXT
);

CREATE TABLE CATEGORIA (
    Codigo INT PRIMARY KEY,
    Nome VARCHAR(50) NOT NULL
);

CREATE TABLE ITEM (
    Codigo INT PRIMARY KEY,
    Descricao VARCHAR(100) NOT NULL,
    Categoria_Codigo INT NOT NULL,
    FOREIGN KEY (Categoria_Codigo) REFERENCES CATEGORIA(Codigo)
);

CREATE TABLE DOACAO (
    Num_Registro INT PRIMARY KEY,
    Data DATE NOT NULL,
    Doador_Doc VARCHAR(20) NOT NULL,
    Inst_Codigo INT NOT NULL,
    FOREIGN KEY (Doador_Doc) REFERENCES DOADOR(Documento),
    FOREIGN KEY (Inst_Codigo) REFERENCES INSTITUICAO(Codigo)
);

CREATE TABLE DISTRIBUICAO (
    Numero INT PRIMARY KEY,
    Data_Entrega DATE NOT NULL,
    Inst_Codigo INT NOT NULL,
    Receptor_CPF VARCHAR(14) NOT NULL,
    FOREIGN KEY (Inst_Codigo) REFERENCES INSTITUICAO(Codigo),
    FOREIGN KEY (Receptor_CPF) REFERENCES RECEPTOR(CPF)
);

CREATE TABLE ITEM_DOACAO (
    Num_Registro_Doacao INT NOT NULL,
    Codigo_Item INT NOT NULL,
    Quantidade INT NOT NULL,
    PRIMARY KEY (Num_Registro_Doacao, Codigo_Item),
    FOREIGN KEY (Num_Registro_Doacao) REFERENCES DOACAO(Num_Registro),
    FOREIGN KEY (Codigo_Item) REFERENCES ITEM(Codigo)
);

CREATE TABLE ITEM_DISTRIBUICAO (
    Numero_Distribuicao INT NOT NULL,
    Codigo_Item INT NOT NULL,
    Quantidade INT NOT NULL,
    PRIMARY KEY (Numero_Distribuicao, Codigo_Item),
    FOREIGN KEY (Numero_Distribuicao) REFERENCES DISTRIBUICAO(Numero),
    FOREIGN KEY (Codigo_Item) REFERENCES ITEM(Codigo)
);

USE bd_basilica_doacoes;

INSERT INTO INSTITUICAO (Codigo, Nome, Endereco, Telefone) VALUES 
(1, 'Basílica do Santo Cura D''Ars - Matriz', 'R. Cura D''Ars, 485 - Prado, Belo Horizonte - MG', '(31) 3332-2824'),
(2, 'Polo de Apoio Solidário - Prado', 'Av. Francisco Sá, 1205 - Prado, Belo Horizonte - MG', '(31) 3334-1590'),
(3, 'Polo de Arrecadação - Centro', 'Av. Amazonas, 810 - Centro, Belo Horizonte - MG', '(31) 3222-4011'),
(4, 'Polo Comunitário - Barreiro', 'Av. Sinfrônio Brochado, 420 - Barreiro, Belo Horizonte - MG', '(31) 3381-1900'),
(5, 'Centro de Triagem - Venda Nova', 'R. Padre Pedro Pinto, 1055 - Venda Nova, Belo Horizonte - MG', '(31) 3451-2244'),
(6, 'Polo de Apoio - Pampulha', 'Av. Antônio Carlos, 6627 - Pampulha, Belo Horizonte - MG', '(31) 3409-5000'),
(7, 'Casa de Acolhimento - Floresta', 'R. Itajubá, 312 - Floresta, Belo Horizonte - MG', '(31) 3224-8899'),
(8, 'Polo Solidário - Santa Tereza', 'R. Mármore, 150 - Santa Tereza, Belo Horizonte - MG', '(31) 3461-4522'),
(9, 'Centro de Doações - Sion', 'Av. Nossa Sra. do Carmo, 1800 - Sion, Belo Horizonte - MG', '(31) 3281-7766'),
(10, 'Armazém Solidário - Buritis', 'Av. Mário Werneck, 1240 - Buritis, Belo Horizonte - MG', '(31) 3378-5511');

INSERT INTO DOADOR (Documento, Nome, Telefone) VALUES 
('142.583.924-11', 'Carlos Mendes Oliveira', '(31) 98451-2266'),
('284.195.373-85', 'Ana Souza Guimarães', '(31) 99122-4488'),
('395.728.144-02', 'Roberto Carlos Ramos', '(31) 98711-3355'),
('412.839.574-91', 'Fernanda Lima Costa', '(31) 99655-1122'),
('523.940.685-33', 'Marcos Paulo Antunes', '(31) 98844-7799'),
('634.051.796-44', 'Juliana Paes Rezende', '(31) 99233-6611'),
('745.162.807-55', 'Pedro Silva Vasconcelos', '(31) 98122-5544'),
('17.283.940/0001-85', 'Supermercados BH Ltda', '(31) 3419-1000'),
('23.849.501/0001-12', 'Padaria Pão Nosso S/A', '(31) 3332-9988'),
('45.612.378/0001-90', 'Confecções Minas Uniformes', '(31) 3201-4455');

INSERT INTO RECEPTOR (CPF, Nome, Vulnerabilidade) VALUES 
('054.123.843-92', 'Dona Maria da Silva', 'Mãe solteira, desempregada, moradora de comunidade, 3 filhos pequenos.'),
('129.843.910-45', 'José Antônio dos Santos', 'Idoso em situação de rua crônica, necessita de cobertores e refeições.'),
('083.452.193-10', 'Cláudia Regina Peixoto', 'Família em abrigo temporário após desabamento de encosta na Vila Paraíso.'),
('094.732.185-54', 'Mário Fernandes Lima', 'Trabalhador autônomo afastado por problemas crônicos de saúde, sem benefício.'),
('118.349.502-81', 'Sílvia Santos Fagundes', 'Idosa, viúva, sem renda ou suporte familiar, reside em habitação precária.'),
('062.843.195-73', 'Paulo Ricardo Moreira', 'Trabalhador informal que sofreu acidente de trânsito, impossibilitado de prover renda.'),
('039.715.428-11', 'Luciana Borges Duarte', 'Família de baixa renda com 5 integrantes vivendo em situação de insegurança alimentar.'),
('104.932.815-02', 'Antônio Marcos Vieira', 'Idoso com quadro de vulnerabilidade social severa e abandono familiar.'),
('076.419.532-88', 'Renata Vasconcelos Melo', 'Mãe de família, desempregada, residindo em ocupação urbana sem saneamento.'),
('145.293.810-67', 'João Batista Ferreira', 'Jovem sem referência familiar, em situação de vulnerabilidade e desabrigo temporário.');

INSERT INTO CATEGORIA (Codigo, Nome) VALUES 
(10, 'Alimentação Básica'), 
(20, 'Vestuário Adulto'), 
(30, 'Vestuário Infantil'), 
(40, 'Cama e Banho'),
(50, 'Higiene Pessoal'),
(60, 'Limpeza Doméstica'),
(70, 'Brinquedos e Lazer'),
(80, 'Material Escolar'),
(90, 'Calçados'),
(100, 'Móveis e Utensílios');

INSERT INTO ITEM (Codigo, Descricao, Categoria_Codigo) VALUES 
(101, 'Saco de Arroz 5kg', 10),
(102, 'Pacote de Feijão 1kg', 10),
(201, 'Casaco de Lã Masculino G', 20),
(301, 'Kit Roupas Infantis (Inverno)', 30),
(401, 'Cobertor Térmico Casal', 40),
(501, 'Kit Higiene (Sabonete/Creme Dental)', 50),
(601, 'Cesta de Produtos de Limpeza', 60),
(701, 'Urso de Pelúcia Grande', 70),
(801, 'Kit Escolar (Cadernos e Lápis)', 80),
(901, 'Par de Tênis Caminhada Tam 40', 90);

INSERT INTO DOACAO (Num_Registro, Data, Doador_Doc, Inst_Codigo) VALUES 
(1001, '2026-05-01', '142.583.924-11', 1),
(1002, '2026-05-02', '17.283.940/0001-85', 2),
(1003, '2026-05-03', '284.195.373-85', 3),
(1004, '2026-05-04', '23.849.501/0001-12', 4),
(1005, '2026-05-05', '395.728.144-02', 5),
(1006, '2026-05-06', '45.612.378/0001-90', 6),
(1007, '2026-05-07', '412.839.574-91', 7),
(1008, '2026-05-08', '523.940.685-33', 8),
(1009, '2026-05-09', '634.051.796-44', 9),
(1010, '2026-05-10', '745.162.807-55', 10);

INSERT INTO ITEM_DOACAO (Num_Registro_Doacao, Codigo_Item, Quantidade) VALUES 
(1001, 201, 5),   
(1001, 401, 3),   
(1002, 101, 100), 
(1002, 102, 100), 
(1003, 301, 10),  
(1004, 501, 50),  
(1005, 901, 2),   
(1006, 201, 20),  
(1007, 701, 5),   
(1008, 801, 15),  
(1009, 401, 4),   
(1010, 601, 10);  

INSERT INTO DISTRIBUICAO (Numero, Data_Entrega, Inst_Codigo, Receptor_CPF) VALUES 
(5001, '2026-06-01', 1, '054.123.843-92'),
(5002, '2026-06-02', 2, '129.843.910-45'),
(5003, '2026-06-03', 3, '083.452.193-10'),
(5004, '2026-06-04', 4, '094.732.185-54'),
(5005, '2026-06-05', 5, '118.349.502-81'),
(5006, '2026-06-06', 6, '062.843.195-73'),
(5007, '2026-06-07', 7, '039.715.428-11'),
(5008, '2026-06-08', 8, '104.932.815-02'),
(5009, '2026-06-09', 9, '076.419.532-88'),
(5010, '2026-06-10', 10, '145.293.810-67');

INSERT INTO ITEM_DISTRIBUICAO (Numero_Distribuicao, Codigo_Item, Quantidade) VALUES 
(5001, 101, 2),  
(5001, 102, 2),  
(5002, 201, 1),  
(5002, 401, 1),  
(5003, 301, 2),  
(5004, 101, 1),  
(5005, 501, 2),  
(5006, 901, 1),  
(5007, 102, 3),  
(5008, 401, 1),  
(5009, 801, 3),  
(5010, 201, 1);
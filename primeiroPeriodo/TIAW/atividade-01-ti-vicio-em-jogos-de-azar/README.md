[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19032816&assignment_repo_type=AssignmentRepo)

# Projeto Jogo Limpo

O objetivo deste projeto voltado para o **vício em jogos de azar** é oferecer suporte, conscientização e tratamento às pessoas que enfrentam esse tipo de dependência. A iniciativa busca:

- Identificar comportamentos compulsivos relacionados a apostas
- Promover educação sobre os riscos envolvidos
- Desenvolver estratégias de prevenção e intervenção eficazes

Além disso, o projeto visa criar um ambiente de acolhimento, com acesso a grupos de apoio e recursos terapêuticos, ajudando o indivíduo a recuperar o controle sobre sua vida e reduzir os danos sociais, financeiros e emocionais causados pelo vício.

---

## 👨‍💻 Alunos integrantes da equipe

- Bernardo Barbosa Heronville  
- Janielly Lorene Talini dos Santos  

## 👩‍🏫 Professores responsáveis

- Ilo Amy Saldanha Rivero

---

## ⚙️ Instruções de utilização

### ✅ Pré-requisitos

- **Node.js** instalado na máquina
- **npm** (gerenciador de pacotes do Node)
- **JSON Server** como dependência do projeto (instalado via `npm install json-server`)

---

### 🚀 Passos para rodar localmente

1. **Clone o repositório:**

```bash
git clone https://github.com/ICEI-PUC-Minas-PPLCC-TI/atividade-01-ti-vicio-em-jogos-de-azar.git
cd atividade-01-ti-vicio-em-jogos-de-azar
```

2. **Instale as dependências:**

```bash
npm install json-server
```

3. **Inicie o servidor com JSON Server:**

```bash
npm run json:server
```
> Isso iniciará o backend em:
> - API REST JSON Server:  
>  [http://localhost:3000/usuarios](http://localhost:3000/usuarios)  
>  [http://localhost:3000/posts](http://localhost:3000/posts)  
>  [http://localhost:3000/progresso](http://localhost:3000/progresso)  
>  [http://localhost:3000/conquistas](http://localhost:3000/conquistas)  
>  [http://localhost:3000/atividadesDisponiveis](http://localhost:3000/atividadesDisponiveis)  
>  [http://localhost:3000/avatares](http://localhost:3000/avatares)

> - Frontend: http://localhost:3000

4. **Acesse a interface no navegador:**

Acesse `http://localhost:3000` e navegue pelas páginas do sistema.  
Ou abra diretamente o arquivo `codigo/public/index.html` no navegador.

---

### 🧪 Testando funcionalidades

- Faça cadastro ou login de usuários
> ![Cadastro](/docs/images/Interface/cadastro.png)  
- Acesse a aba de comunidade e visualize ou interaja com os posts
> ![Comunidade](/docs/images/Interface/Comunidade.png)  
- Teste a mecânica de conquistas e dias sem jogar
> ![Conquistas](/docs/images/Interface/Conquistas.png)  
- Explore as funcionalidades da conta do usuário
> ![Conta](/docs/images/Interface/perfil.png)  
---

## 🗂 Estrutura resumida do projeto

```
atividade-01-ti-vicio-em-jogos-de-azar/
│
├── codigo/
│   ├── db/
│   │   └── db.json              → Banco de dados local (JSON Server)
│   └── public/
│       ├── admin_controle/...    → Página de cadastro de atividades e conquistas
│       ├── assets/...            → Outros arquivos HTML/CSS/JS
│       ├── login/...             → Arquivos de login e pagina do usuario
│       ├── index.html             → Página inicial
│       └── ...                   → Outras paginas 
│    
│       
│      
│       
├── docs/
│   └── README.md                → Documentação do projeto
│ 
├── index.js                     → Servidor Express + JSON Server
├── package.json                 → Scripts e dependências do projeto
└── README.md                    → Este arquivo
```

---

## 📦 Scripts disponíveis (`package.json`)

```json
{
  "name": "meu-projeto",
  "version": "1.0.0",
  "description": "",
  "main": "index.js",
  "scripts": {
    "json:server": "json-server --watch codigo/db/db.json --port 3000 --static codigo/public",
    "start": "node index.js"
  },
  "keywords": [],
  "author": "",
  "license": "ISC",
  "dependencies": {
    "json-server": "^0.17.4"
  }
}
```
## 🛠 Tecnologias Utilizadas

O projeto **Jogo Limpo** foi desenvolvido com as seguintes tecnologias:

- **HTML5** – Estrutura das páginas;
- **CSS3** (com uso de variáveis CSS) – Estilização responsiva e moderna;
- **JavaScript Puro** – Lógica da aplicação no frontend;
- **JSON Server** – Backend simulado com uma API REST para persistência de dados;
- **Node.js** – Ambiente para rodar o servidor local;

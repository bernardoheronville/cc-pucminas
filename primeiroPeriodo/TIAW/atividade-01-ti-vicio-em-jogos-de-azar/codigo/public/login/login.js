const LOGIN_URL = "login.html";
let RETURN_URL = "pagina_usuario.html";
const API_URL = "/usuarios";

let db_usuarios = [];
let usuarioCorrente = {};

// Gera um ID string
function gerarIdUnico() {
  return "user_" + Date.now();
}

function carregarUsuarios(callback) {
  fetch(API_URL)
    .then((res) => res.json())
    .then((data) => {
      db_usuarios = data;
      console.log("Usuários carregados:", db_usuarios);
      if (callback) callback();
    })
    .catch((err) => {
      console.error("Erro ao carregar usuários:", err);
    });
}

function loginUser(login, senha) {
  console.log("Tentando login:", login, senha);
  for (let usuario of db_usuarios) {
    if (login === usuario.login && senha === usuario.senha) {
      usuarioCorrente = { ...usuario };
      sessionStorage.setItem("usuarioCorrente", JSON.stringify(usuarioCorrente));
      return true;
    }
  }
  return false;
}

function logoutUser() {
  sessionStorage.removeItem("usuarioCorrente");
  window.location.href = LOGIN_URL;
}

function addUser(nome, login, senha, email) {
  let usuario = {
    id: gerarIdUnico(),
    nome,
    login,
    senha,
    email,
    conquistas: [], 
    atividades: [],
    avatarDesbloqueado: "https://cdn-icons-png.flaticon.com/512/149/149071.png"
  };

  fetch(API_URL, {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(usuario),
  })
    .then((res) => res.json())
    .then((dataUsuario) => {
      db_usuarios.push(dataUsuario);
      alert("Usuário registrado com sucesso!");

      // Cria o progresso para esse novo usuário
      const progressoInicial = {
        usuario_id: dataUsuario.id,
        meta_dias: "5",
        dias_sem_jogar: 0,
        datas_confirmadas: []
      };

      fetch("/progresso", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(progressoInicial),
      })
        .then(res => res.json())
        .then(() => {
          console.log("Progresso inicial criado para o usuário", dataUsuario.id);
          window.location.href = LOGIN_URL;
        })
        .catch(err => {
          console.error("Erro ao criar progresso inicial:", err);
          window.location.href = LOGIN_URL;
        });
    })
    .catch((err) => {
      console.error("Erro ao registrar usuário:", err);
      alert("Erro ao registrar usuário.");
    });
}

// Eventos de formulário
document.addEventListener("DOMContentLoaded", () => {
  carregarUsuarios();

  document.getElementById("form-login").addEventListener("submit", function (e) {
    e.preventDefault();
    let login = document.getElementById("username").value;
    let senha = document.getElementById("password").value;
    if (loginUser(login, senha)) {
      alert("Login realizado com sucesso!");
      window.location.href = RETURN_URL;
    } else {
      alert("Usuário ou senha incorretos.");
    }
  });

  document.getElementById("form-cadastro").addEventListener("submit", function (e) {
    e.preventDefault();
    let nome = document.getElementById("txt_nome").value;
    let login = document.getElementById("txt_login").value;
    let email = document.getElementById("txt_email").value;
    let senha = document.getElementById("txt_senha").value;
    let senha2 = document.getElementById("txt_senha2").value;

    if (senha !== senha2) {
      alert("As senhas não coincidem.");
      return;
    }

    addUser(nome, login, senha, email);
    this.reset();
  });
});

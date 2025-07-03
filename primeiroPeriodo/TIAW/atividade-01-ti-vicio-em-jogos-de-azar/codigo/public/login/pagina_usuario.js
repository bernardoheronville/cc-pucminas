const LOGIN_URL = "login.html";

const mensagens = [
  "Não é porque as coisas são difíceis que não ousamos, é porque não ousamos que elas são difíceis. – Sêneca",
  "O homem que venceu a si mesmo é mais forte do que aquele que conquistou mil batalhas. – Buda",
  "A felicidade da sua vida depende da qualidade dos seus pensamentos. – Marco Aurélio",
  "Torne-se quem você é. – Nietzsche",
  "Não espere por uma crise para descobrir o que é importante em sua vida. – Platão",
  "A maior vitória é a vitória sobre si mesmo. – Aristóteles",
  "O sofrimento deixa de ser sofrimento no momento em que encontra um sentido. – Viktor Frankl",
  "Não é o que acontece com você, mas como você reage que importa. – Epicteto",
  "Conhece-te a ti mesmo. – Sócrates",
  "A liberdade está em sermos donos de nossa própria vida. – Cícero"
];


let atividadesDisponiveisGlobal = []; 


function mensagemDoDia() {
  const dia = new Date().getDate();
  const index = dia % mensagens.length;
  const mensagem = mensagens[index];
  exibirMensagem(mensagem);
}

function exibirMensagem(msg) {
  const elementoMensagem = document.getElementById("mensagem");
  if (elementoMensagem) {
    elementoMensagem.textContent = msg;
  } else {
    console.warn("Elemento com id='mensagem' não encontrado.");
  }
}

async function carregarAtividadesDisponiveis() {
  try {
    const res = await fetch("/atividadesDisponiveis");
    if (!res.ok) throw new Error("Erro ao carregar atividades disponíveis");
    const atividades = await res.json();
    atividadesDisponiveisGlobal = atividades;  
  } catch (error) {
    console.error(error);
  }
}

async function mostrarUsuario() {
  const usuarioJSON = sessionStorage.getItem("usuarioCorrente");
  if (!usuarioJSON) {
    window.location.href = LOGIN_URL;
    return null;
  }

  const usuario = JSON.parse(usuarioJSON);

  // Dados básicos
  document.getElementById("nomeUsuario").textContent = usuario.nome;
  document.getElementById("loginUsuario").textContent = usuario.login;
  document.getElementById("emailUsuario").textContent = usuario.email;

  // Avatar desbloqueado
  const avatarEl = document.getElementById("avatarDesbloqueado");
  if (avatarEl) {
    avatarEl.src = usuario.avatarDesbloqueado || 'https://cdn-icons-png.flaticon.com/512/149/149071.png';
    avatarEl.alt = "Avatar desbloqueado";
  }

  // Atividades registradas
  const atividadesLista = document.getElementById('atividadesLista');
  if (atividadesLista) {
    atividadesLista.innerHTML = '';

    if (usuario.atividades && usuario.atividades.length > 0) {

      // Filtra as atividades válidas (existem em atividadesDisponiveisGlobal)
      const atividadesValidas = usuario.atividades.filter(atividade => {
        return atividadesDisponiveisGlobal.some(a => a.descricao === atividade.descricao);
      });

      // Se atividades inválidas foram removidas, atualiza backend e sessionStorage
      if (atividadesValidas.length !== usuario.atividades.length) {
        usuario.atividades = atividadesValidas;

        try {
          const salvar = await fetch(`/usuarios/${usuario.id}`, {
            method: "PATCH",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ atividades: usuario.atividades })
          });
          if (!salvar.ok) throw new Error("Erro ao salvar atividades no servidor");

          // Atualiza sessionStorage com a versão corrigida
          sessionStorage.setItem("usuarioCorrente", JSON.stringify(usuario));
        } catch (error) {
          console.error("Erro ao atualizar atividades do usuário:", error);
        }
      }

      if (atividadesValidas.length === 0) {
        atividadesLista.innerHTML = "<li>Nenhuma atividade registrada.</li>";
      } else {
        atividadesValidas.forEach(atividade => {
          const li = document.createElement('li');
          const dataFormatada = new Date(atividade.data).toLocaleDateString('pt-BR');

          const atividadeDisponivel = atividadesDisponiveisGlobal.find(a => a.descricao === atividade.descricao);
          const icone = atividadeDisponivel ? atividadeDisponivel.icone : '✅';

          li.innerHTML = `${icone} <strong>${atividade.descricao}</strong><br><small>${dataFormatada}</small>`;
          atividadesLista.appendChild(li);
        });
      }
    } else {
      atividadesLista.innerHTML = "<li>Nenhuma atividade registrada.</li>";
    }
  }

  return usuario; // importante retornar para usar externamente
}

async function carregarAtividadesDisponiveisParaFormulario(usuario) {
  try {
    const res = await fetch("/atividadesDisponiveis");
    if (!res.ok) throw new Error("Erro ao carregar atividades disponíveis");
    const atividades = await res.json();

    const container = document.getElementById("listaAtividadesDisponiveis");
    if (!container) return;

    container.innerHTML = "";

    // Filtra as atividades que o usuário já registrou (compara pela descrição)
    const atividadesRegistradasDescricoes = usuario.atividades ? usuario.atividades.map(a => a.descricao) : [];

    const atividadesDisponiveisParaRegistrar = atividades.filter(a => !atividadesRegistradasDescricoes.includes(a.descricao));

    if (atividadesDisponiveisParaRegistrar.length === 0) {
      container.innerHTML = "<p>Você já registrou todas as atividades disponíveis.</p>";
      return;
    }

    atividadesDisponiveisParaRegistrar.forEach(atividade => {
      const card = document.createElement("div");
      card.className = "atividade-card";

      const checkbox = document.createElement("input");
      checkbox.type = "checkbox";
      checkbox.id = `atividade_${atividade.id}`;
      checkbox.name = "atividades";
      checkbox.value = atividade.id;
      checkbox.className = "atividade-checkbox";

      const label = document.createElement("label");
      label.htmlFor = checkbox.id;
      label.textContent = `${atividade.icone} ${atividade.descricao}`; // Mostra o ícone junto na label
      label.className = "atividade-label";

      card.appendChild(checkbox);
      card.appendChild(label);
      container.appendChild(card);
    });
  } catch (error) {
    console.error(error);
    alert("Erro ao carregar atividades disponíveis.");
  }
}

// Escuta o submit do formulário para registrar atividades concluídas
function registrarAtividadesConcluidas(usuario) {
  const form = document.getElementById("formAtividadesDisponiveis");
  if (!form) return;

  form.addEventListener("submit", async (e) => {
    e.preventDefault();

    const checkboxes = form.querySelectorAll('input[name="atividades"]:checked');
    if (checkboxes.length === 0) {
      alert("Selecione ao menos uma atividade para registrar.");
      return;
    }

    if (!usuario) return alert("Usuário não logado.");

    if (!usuario.atividades) usuario.atividades = [];

    try {
      const res = await fetch("/atividadesDisponiveis");
      if (!res.ok) throw new Error("Erro ao carregar atividades disponíveis");
      const atividadesDisponiveis = await res.json();

      checkboxes.forEach(checkbox => {
        const idAtividade = checkbox.value;
        const atividadeInfo = atividadesDisponiveis.find(a => a.id === idAtividade);
        if (atividadeInfo) {
          const jaRegistrada = usuario.atividades.some(a => a.descricao === atividadeInfo.descricao);
          if (!jaRegistrada) {
            usuario.atividades.push({
              descricao: atividadeInfo.descricao,
              data: new Date().toISOString()
            });
          }
        }
      });

      // Salva no backend
      const salvar = await fetch(`/usuarios/${usuario.id}`, {
        method: "PATCH",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ atividades: usuario.atividades })
      });

      if (!salvar.ok) throw new Error("Erro ao salvar atividades no servidor");

      const progresso = await carregarProgresso(usuario.id);

      // Atualiza sessionStorage e UI
      sessionStorage.setItem("usuarioCorrente", JSON.stringify(usuario));
      mostrarUsuario();
      carregarAtividadesDisponiveisParaFormulario(usuario);
      form.reset();

      alert("Atividades registradas com sucesso!");

    } catch (error) {
      console.error(error);
      alert("Erro ao registrar atividades. Tente novamente.");
    }
  });
}

async function carregarProgresso(usuarioId) {
  const res = await fetch(`/progresso?usuario_id=${usuarioId}`);
  const progresso = await res.json();
  return progresso[0];
}

async function salvarProgresso(progresso) {
  await fetch(`/progresso/${progresso.id}`, {
    method: "PATCH",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(progresso)
  });
}
async function atualizarAvatar(usuario, progresso) {
  try {
    const res = await fetch("/avatares");
    const avatares = await res.json();

    const dias = progresso.dias_sem_jogar || 0;

    // Pega o avatar com o maior limite que o usuário atingiu
    const avatarDesbloqueado = avatares
      .filter(a => dias >= a.limiteMinimoDias)
      .sort((a, b) => b.limiteMinimoDias - a.limiteMinimoDias)[0];

    if (avatarDesbloqueado && usuario.avatarDesbloqueado !== avatarDesbloqueado.img) {
      usuario.avatarDesbloqueado = avatarDesbloqueado.img;

      // Atualiza backend e sessionStorage
      await fetch(`/usuarios/${usuario.id}`, {
        method: "PATCH",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ avatarDesbloqueado: avatarDesbloqueado.img })
      });

      sessionStorage.setItem("usuarioCorrente", JSON.stringify(usuario));
    }
  } catch (error) {
    console.error("Erro ao atualizar avatar:", error);
  }
}

async function iniciarAreaMeta(usuario) {
  const progresso = await carregarProgresso(usuario.id);

  const diasEl = document.getElementById("diasSemJogar");
  const metaEl = document.getElementById("metaDias");
  const formMeta = document.getElementById("formMetaDias");
  const btnHoje = document.getElementById("btnNaoJogueiHoje");
  const btnResetar = document.getElementById("btnResetarProgresso");

  if (!progresso) return;

  diasEl.textContent = progresso.dias_sem_jogar || 0;
  metaEl.textContent = progresso.meta_dias || "?";

  formMeta.addEventListener("submit", async (e) => {
    e.preventDefault();

    const novaMetaStr = document.getElementById("metaInput").value.trim();
    const novaMeta = parseInt(novaMetaStr, 10);
    const diasSemJogar = progresso.dias_sem_jogar || 0;

    if (isNaN(novaMeta) || novaMeta < 1) {
      alert("Por favor, insira um número válido para a meta (mínimo 1).");
      return;
    }

    if (novaMeta < diasSemJogar) {
      alert(`A meta não pode ser menor que os dias já registrados (${diasSemJogar}).`);
      return;
    }

    progresso.meta_dias = novaMeta;
    await salvarProgresso(progresso);
    metaEl.textContent = novaMeta;
    alert("Meta atualizada!");
  });

  btnHoje.addEventListener("click", async () => {
    const hoje = new Date().toISOString().slice(0, 10);
    if (progresso.datas_confirmadas.includes(hoje)) {
      alert("Você já marcou hoje.");
      return;
    }
    progresso.datas_confirmadas.push(hoje);
    progresso.dias_sem_jogar += 1;
    await salvarProgresso(progresso);
    diasEl.textContent = progresso.dias_sem_jogar;
    await atualizarAvatar(usuario, progresso); 
    alert("Progresso registrado com sucesso!");
  });

  // ⬇️ Lógica do botão de resetar
  btnResetar?.addEventListener("click", async () => {
    if (!confirm("Tem certeza que deseja resetar os dias sem jogar? Isso apagará o histórico atual.")) return;

    progresso.dias_sem_jogar = 0;
    progresso.datas_confirmadas = [];
    await salvarProgresso(progresso);

    diasEl.textContent = "0";
    alert("Progresso resetado.");
  });
}

function logoutUser() {
  sessionStorage.removeItem("usuarioCorrente");
  window.location.href = "../index.html";
}

window.addEventListener("DOMContentLoaded", async () => {
  await carregarAtividadesDisponiveis();

  const usuario = await mostrarUsuario();
  mensagemDoDia();

  if (usuario) {
    carregarAtividadesDisponiveisParaFormulario(usuario);
    registrarAtividadesConcluidas(usuario);
    iniciarAreaMeta(usuario);
  }

  const logoutBtnNav = document.getElementById("btn_logout_nav");
  if (logoutBtnNav) {
    logoutBtnNav.addEventListener("click", logoutUser);
  }
});



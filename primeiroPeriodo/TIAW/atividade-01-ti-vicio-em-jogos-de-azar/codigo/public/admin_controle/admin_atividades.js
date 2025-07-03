const API_ATIVIDADES = "/atividadesDisponiveis";
const API_CONQUISTAS = "/conquistas";

const form = document.getElementById("formAtividade");
const lista = document.getElementById("listaAtividades");

const formConquista = document.getElementById("formConquista");
const listaConquistas = document.getElementById("listaConquistas");

let editandoId = null;
let editandoConquistaId = null;

// ---------- ATIVIDADES ----------
function carregarAtividades() {
  fetch(API_ATIVIDADES)
    .then(res => res.json())
    .then(atividades => {
      lista.innerHTML = "";
      atividades.forEach(({ id, descricao, icone }) => {
        const li = document.createElement("li");
        li.className = "list-group-item d-flex justify-content-between align-items-center";
        li.innerHTML = `
          <span>${icone} ${descricao}</span>
          <div>
            <button class="btn btn-sm btn-warning me-2" onclick="editarAtividade('${id}', \`${descricao}\`, \`${icone}\`)">Editar</button>
            <button class="btn btn-sm btn-danger" onclick="excluirAtividade('${id}')">Excluir</button>
          </div>
        `;
        lista.appendChild(li);
      });
    });
}

form.addEventListener("submit", e => {
  e.preventDefault();
  const descricao = document.getElementById("descricao").value.trim();
  const icone = document.getElementById("icone").value.trim();

  if (!descricao || !icone) return alert("Preencha todos os campos da atividade.");

  const atividade = { descricao, icone };
  const method = editandoId ? "PUT" : "POST";
  const url = editandoId ? `${API_ATIVIDADES}/${editandoId}` : API_ATIVIDADES;

  fetch(url, {
    method,
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(atividade),
  }).then(() => {
    form.reset();
    editandoId = null;
    carregarAtividades();
  });
});

window.editarAtividade = function (id, descricao, icone) {
  document.getElementById("descricao").value = descricao;
  document.getElementById("icone").value = icone;
  editandoId = id;
};

window.excluirAtividade = function (id) {
  if (confirm("Tem certeza que deseja excluir esta atividade?")) {
    fetch(`${API_ATIVIDADES}/${id}`, { method: "DELETE" })
      .then(() => carregarAtividades());
  }
};

// ---------- CONQUISTAS ----------
function carregarConquistas() {
  fetch(API_CONQUISTAS)
    .then(res => res.json())
    .then(conquistas => {
      listaConquistas.innerHTML = "";
      conquistas.forEach(({ id, nome, descricao, tipo, meta, icone }) => {
        const li = document.createElement("li");
        li.className = "list-group-item d-flex justify-content-between align-items-center";
        li.innerHTML = `
          <div>
            <strong>${icone || "🏅"} ${nome}</strong><br/>
            <small>${descricao}</small><br/>
            <small>Tipo: ${tipo} | Meta: ${meta}</small>
          </div>
          <div>
            <button class="btn btn-sm btn-warning me-2" 
              onclick="editarConquista('${id}', \`${nome}\`, \`${descricao}\`, '${tipo}', ${meta}, \`${icone || ''}\`)">Editar</button>
            <button class="btn btn-sm btn-danger" onclick="excluirConquista('${id}')">Excluir</button>
          </div>
        `;
        listaConquistas.appendChild(li);
      });
    });
}

formConquista.addEventListener("submit", e => {
  e.preventDefault();

  const nome = document.getElementById("conquistaNome").value.trim();
  const descricao = document.getElementById("conquistaDescricao").value.trim();
  const tipo = document.getElementById("conquistaTipo").value;
  const meta = Number(document.getElementById("conquistaMeta").value);
  const icone = document.getElementById("conquistaIcone").value.trim();

  if (!nome || !descricao || !tipo || !meta) {
    return alert("Preencha todos os campos obrigatórios");
  }

  const conquista = { nome, descricao, tipo, meta, icone };
  const method = editandoConquistaId ? "PUT" : "POST";
  const url = editandoConquistaId ? `${API_CONQUISTAS}/${editandoConquistaId}` : API_CONQUISTAS;

  fetch(url, {
    method,
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(conquista),
  })
    .then(() => {
      formConquista.reset();
      editandoConquistaId = null;
      carregarConquistas();
    })
    .catch(err => {
      console.error("Erro ao salvar conquista:", err);
      alert("Erro ao salvar conquista");
    });
});

window.editarConquista = function (id, nome, descricao, tipo, meta, icone) {
  document.getElementById("conquistaNome").value = nome;
  document.getElementById("conquistaDescricao").value = descricao;
  document.getElementById("conquistaTipo").value = tipo;
  document.getElementById("conquistaMeta").value = meta;
  document.getElementById("conquistaIcone").value = icone || "";
  editandoConquistaId = id;
};

window.excluirConquista = function (id) {
  if (confirm("Tem certeza que deseja excluir esta conquista?")) {
    fetch(`${API_CONQUISTAS}/${id}`, { method: "DELETE" })
      .then(() => carregarConquistas())
      .catch(err => {
        console.error("Erro ao excluir conquista:", err);
        alert("Erro ao excluir conquista");
      });
  }
};

// Inicialização
carregarAtividades();
carregarConquistas();

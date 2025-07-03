// Seleciona todos os itens do dropdown (dias da semana)
const items = document.querySelectorAll(".dropdown-item");

// Variável para armazenar o dia selecionado
let diaSelecionado = null;

// Referência ao botão do dropdown que mostra o dia atual
const dropdownButton = document.querySelector(".dropdown-toggle");

// Objeto que armazena os itens adicionados para cada dia da semana
const diaDaSemana = {
  Segunda: [],
  Terça: [],
  Quarta: [],
  Quinta: [],
  Sexta: [],
  Sábado: [],
  Domingo: []
};

// Clona o botão original de "+" para poder restaurá-lo depois
const btn1 = document.getElementById("btn1"); // botão de adicionar musculação
const originalPlusButton = btn1.cloneNode(true); // salva uma cópia do botão original

const btn2 = document.getElementById("btn2"); // botão de adicionar leitura
const originalPlusButton2 = btn2.cloneNode(true); // salva uma cópia do botão original

// Adiciona eventos de clique a cada item do dropdown
items.forEach((item) => {
  item.addEventListener("click", function (e) {
    e.preventDefault(); // impede comportamento padrão do link

    diaSelecionado = this.getAttribute("data-value"); // pega o valor do atributo data-value (ex: Segunda)
    dropdownButton.textContent = diaSelecionado; // exibe o nome do dia no botão dropdown

    const hasMusculacao = diaDaSemana[diaSelecionado].includes("Musculação"); // verifica se já foi adicionada Musculação para o dia
    const hasLeitura = diaDaSemana[diaSelecionado].includes("Leitura"); // verifica se já foi adicionada Leitura para o dia

    // Restaurar ou substituir botão de Musculação
    const currentBtn1 = document.querySelector("#btn1, .fa-check.text-success[data-btn='1']"); // seleciona o botão de musculação ou o ícone de check
    if (currentBtn1) {
      if (hasMusculacao) {
        // se já foi adicionada, mostra ícone de check verde
        const checkIcon1 = document.createElement("i");
        checkIcon1.className = "fa fa-check text-success";
        checkIcon1.setAttribute("aria-hidden", "true");
        checkIcon1.setAttribute("data-btn", "1"); 
        currentBtn1.replaceWith(checkIcon1); 
      } else {
        // se não foi adicionada, restaura o botão original "+"
        currentBtn1.replaceWith(originalPlusButton.cloneNode(true));
      }
    }

    // Restaurar ou substituir botão de Leitura
    const currentBtn2 = document.querySelector("#btn2, .fa-check.text-success[data-btn='2']"); // seleciona o botão de leitura ou ícone de check
    if (currentBtn2) {
      if (hasLeitura) {
        // se já foi adicionada, mostra ícone de check verde
        const checkIcon2 = document.createElement("i");
        checkIcon2.className = "fa fa-check text-success";
        checkIcon2.setAttribute("aria-hidden", "true");
        checkIcon2.setAttribute("data-btn", "2"); 
        currentBtn2.replaceWith(checkIcon2); 
      } else {
        // se não foi adicionada, restaura o botão original "+"
        currentBtn2.replaceWith(originalPlusButton2.cloneNode(true));
      }
    }
  });
});

// Função chamada ao clicar no botão "+" de musculação
const adicionado = () => {
  if (!diaSelecionado) {
    alert("Por favor, selecione um dia da semana antes de adicionar.");
    return;
  }

  const conteudo = "Musculação";
  if (!diaDaSemana[diaSelecionado].includes(conteudo)) {
    // adiciona a atividade ao dia correspondente se ainda não estiver
    diaDaSemana[diaSelecionado].push(conteudo);
  }

  const plusButton = document.getElementById("btn1"); // pega o botão "+"
  const addedIcon = document.createElement("i"); // cria o ícone de check
  addedIcon.className = "fa fa-check text-success";
  addedIcon.setAttribute("aria-hidden", "true");
  addedIcon.setAttribute("data-btn", "1"); 
  plusButton.replaceWith(addedIcon); 
};

// Função chamada ao clicar no botão "+" de leitura
const adicionadoLeitura = () => {
  if (!diaSelecionado) {
    alert("Por favor, selecione um dia da semana antes de adicionar.");
    return;
  }

  const conteudo = "Leitura";
  if (!diaDaSemana[diaSelecionado].includes(conteudo)) {
    // adiciona a atividade ao dia correspondente se ainda não estiver
    diaDaSemana[diaSelecionado].push(conteudo);
  }

  const plusButton = document.getElementById("btn2"); // pega o botão "+"
  const addedIcon = document.createElement("i"); // cria o ícone de check
  addedIcon.className = "fa fa-check text-success";
  addedIcon.setAttribute("aria-hidden", "true");
  addedIcon.setAttribute("data-btn", "2"); // marca que é do botão 2
  plusButton.replaceWith(addedIcon); // substitui o botão pelo ícone
};

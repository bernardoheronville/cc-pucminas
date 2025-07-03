document.getElementById("formulario").addEventListener("submit", function (e) {
    e.preventDefault();

    const nome = document.getElementById("nome").value;
    const idade = document.getElementById("idade").value;
    const respostas = [
        document.getElementById("q1").value,
        document.getElementById("q2").value,
        document.getElementById("q3").value,
        document.getElementById("q4").value,
        document.getElementById("q5").value
    ];

    const positivos = respostas.filter(r => r === "Sim").length;
    let mensagem = `<strong>Nome:</strong> ${nome}<br><strong>Idade:</strong> ${idade}<br><br>`;
    mensagem += `<strong>Respostas:</strong><br>`;
    respostas.forEach((r, i) => {
        mensagem += `Pergunta ${i + 1}: ${r}<br>`;
    });

    if (positivos >= 3) {
        mensagem += `<br><strong style="color:red;">Atenção:</strong> Suas respostas indicam sinais de comportamento compulsivo com jogos de azar.`;
    } else {
        mensagem += `<br><strong style="color:green;">Você está bem!</strong>`;
    }

    const resultadoDiv = document.getElementById("resultado");
    resultadoDiv.innerHTML = mensagem;
    resultadoDiv.style.display = "block";

    fetch("/respostas", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify({
            nome,
            idade,
            respostas,
            positivos
        })
    })
    .then(res => res.json())
    .then(data => {
        console.log("Dados salvos:", data);
    })
    .catch(err => {
        console.error("Erro ao salvar:", err);
    });
});

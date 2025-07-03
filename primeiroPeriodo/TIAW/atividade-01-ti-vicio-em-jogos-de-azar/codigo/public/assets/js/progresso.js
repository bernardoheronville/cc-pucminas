async function carregarEPopularDadosUsuario() {
    try {
        // Obter usuário logado
        const usuarioCorrente = JSON.parse(sessionStorage.getItem("usuarioCorrente"));
        if (!usuarioCorrente || !usuarioCorrente.id) {
            alert("Usuário não autenticado. Redirecionando...");
            window.location.href = "../login/login.html";
            return;
        }
        const usuarioId = usuarioCorrente.id;

        // Requisições paralelas para agilizar
        const [resProgresso, resUsuario, resConquistas, resPosts] = await Promise.all([
            fetch(`/progresso?usuario_id=${usuarioId}`),
            fetch(`/usuarios/${usuarioId}`),
            fetch("/conquistas"),
            fetch("/posts")
        ]);

        if (!resProgresso.ok) throw new Error("Erro ao buscar progresso.");
        if (!resUsuario.ok) throw new Error("Erro ao buscar dados do usuário.");
        if (!resConquistas.ok) throw new Error("Erro ao buscar conquistas.");
        if (!resPosts.ok) throw new Error("Erro ao buscar posts.");

        const progressoArray = await resProgresso.json();
        const dadosProgresso = progressoArray[0];
        if (!dadosProgresso) throw new Error("Progresso não encontrado para o usuário logado.");

        const dadosUsuario = await resUsuario.json();
        const todasConquistas = await resConquistas.json();
        const todosPosts = await resPosts.json();

        // Atualiza dados básicos no DOM
        document.getElementById('userName').textContent = dadosUsuario.nome;
        document.getElementById('diasSemJogar').textContent = `${dadosProgresso.dias_sem_jogar} / ${dadosProgresso.meta_dias}`;
        document.getElementById('dataInicio').textContent = dadosProgresso.datas_confirmadas[0] || "-";
        document.getElementById('metaDias').textContent = dadosProgresso.meta_dias;

        // Barra de progresso e status
        const progresso = dadosProgresso.dias_sem_jogar / dadosProgresso.meta_dias;
        const progressoBarra = document.getElementById('progressoBarra');
        progressoBarra.style.width = `${Math.min(progresso, 1) * 100}%`;

        const statusEl = document.getElementById('statusJornada');
        statusEl.classList.remove('text-blue-600', 'text-green-600');
        progressoBarra.classList.remove('bg-green-500', 'bg-gold');

        if (progresso >= 1) {
            statusEl.textContent = '🏁 Completo';
            statusEl.classList.add('text-blue-600');
            progressoBarra.classList.add('bg-gold');
        } else {
            statusEl.textContent = '✔ Em Progresso';
            statusEl.classList.add('text-green-600');
            progressoBarra.classList.add('bg-green-500');
        }

        // Lista de conquistas formatada - últimas 3 conquistas
        const listaRecompensas = document.getElementById('listaRecompensas');
        listaRecompensas.innerHTML = '';

        const ultimasConquistasIds = (dadosUsuario.conquistas || []).slice(-3).reverse();

        ultimasConquistasIds.forEach(id => {
            const conquista = todasConquistas.find(c => c.id === id);
            if (!conquista) return;

            const card = document.createElement('div');
            card.className = "bg-white p-4 rounded-xl shadow-md flex items-start space-x-3 hover:shadow-lg transition-shadow";

            const icon = document.createElement('div');
            icon.className = "text-yellow-400 text-3xl flex-shrink-0";
            icon.textContent = conquista.icone || "🏆";

            const conteudo = document.createElement('div');

            const nome = document.createElement('h3');
            nome.className = "font-bold text-lg text-gray-800";
            nome.textContent = conquista.nome;

            const descricao = document.createElement('p');
            descricao.className = "text-gray-600 text-sm mt-1";
            descricao.textContent = conquista.descricao;

            conteudo.appendChild(nome);
            conteudo.appendChild(descricao);

            card.appendChild(icon);
            card.appendChild(conteudo);

            listaRecompensas.appendChild(card);
        });

        // Comunidade: tenta exibir dados já presentes no usuário
        if (dadosUsuario.comunidade) {
            document.getElementById('postagens').textContent = dadosUsuario.comunidade.postagens || 0;
            document.getElementById('comentarios').textContent = dadosUsuario.comunidade.comentarios || 0;
            document.getElementById('curtidas').textContent = dadosUsuario.comunidade.curtidas_recebidas || 0;
        } else {
            // Caso comunidade não exista, calcula a partir dos posts
            const postsUsuario = todosPosts.filter(post => post.userId === usuarioId);
            const totalPostagens = postsUsuario.length;

            let totalComentarios = 0;
            todosPosts.forEach(post => {
                if (post.comments && Array.isArray(post.comments)) {
                    totalComentarios += post.comments.filter(c => c.authorId === usuarioId).length;
                }
            });

            let totalCurtidasRecebidas = 0;
            postsUsuario.forEach(post => {
                totalCurtidasRecebidas += post.likesCount || 0;
            });

            document.getElementById('postagens').textContent = totalPostagens;
            document.getElementById('comentarios').textContent = totalComentarios;
            document.getElementById('curtidas').textContent = totalCurtidasRecebidas;
        }

    } catch (error) {
        console.error("Falha ao carregar ou processar dados do usuário:", error);
    }
}

document.addEventListener('DOMContentLoaded', carregarEPopularDadosUsuario);

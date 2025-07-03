const usuarioCorrente = JSON.parse(sessionStorage.getItem("usuarioCorrente"));

if (!usuarioCorrente || !usuarioCorrente.id) {
  alert("Usuário não autenticado. Redirecionando para login.");
  window.location.href = "../public/login/login.html";
} else {
  carregarConquistas(usuarioCorrente.id);
}

async function salvarConquistasNoBackend(usuarioId, novasConquistas) {
  try {
    const res = await fetch(`/usuarios/${usuarioId}`, {
      method: 'PATCH',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ conquistas: novasConquistas }),
    });
    if (!res.ok) throw new Error('Erro ao salvar conquistas no backend');
    return true;
  } catch (e) {
    console.error(e);
    return false;
  }
}

async function carregarConquistas(usuarioLogadoId) {
  const container = document.getElementById('conquistasContainer');
  container.innerHTML = 'Carregando...';

  try {
    // Busca usuário
    const resUsuario = await fetch(`/usuarios/${usuarioLogadoId}`);
    if (!resUsuario.ok) throw new Error('Falha ao carregar usuário');
    const usuario = await resUsuario.json();

    // Busca progresso do usuário
    const resProgresso = await fetch(`/progresso?usuario_id=${usuarioLogadoId}`);
    if (!resProgresso.ok) throw new Error('Falha ao carregar progresso');
    const progressoArray = await resProgresso.json();
    const progresso = progressoArray[0] || { dias_sem_jogar: 0 };

    // Busca todas conquistas possíveis
    const resConquistas = await fetch(`/conquistas`);
    if (!resConquistas.ok) throw new Error('Falha ao carregar conquistas');
    const conquistasTodas = await resConquistas.json();

    const diasSemJogar = Number(progresso.dias_sem_jogar) || 0;
    const totalAtividades = (usuario.atividades && usuario.atividades.length) || 0;
    const conquistasUsuarioSet = new Set(usuario.conquistas || []);

    let atualizou = false;

    // Verificar conquistas novas para desbloquear
    conquistasTodas.forEach(c => {
      if (!conquistasUsuarioSet.has(c.id)) {
        const meta = Number(c.meta);
        if (c.tipo === 'dias_sem_jogar' && diasSemJogar >= meta) {
          conquistasUsuarioSet.add(c.id);
          atualizou = true;
        }
        if (c.tipo === 'atividades' && totalAtividades >= meta) {
          conquistasUsuarioSet.add(c.id);
          atualizou = true;
        }
      }
    });

    // Se tiver conquistas novas, salvar no backend
    if (atualizou) {
      const sucesso = await salvarConquistasNoBackend(usuarioLogadoId, Array.from(conquistasUsuarioSet));
      if (!sucesso) {
        console.warn('Conquistas atualizadas localmente, mas falha ao salvar no backend');
      } else {
        console.log('Conquistas atualizadas e salvas no backend');
      }
    }

    // Renderizar conquistas
    container.innerHTML = '';
    conquistasTodas.forEach(c => {
      const desbloqueada = conquistasUsuarioSet.has(c.id);
      const card = document.createElement('div');
      card.className = `p-4 border rounded-lg flex items-center space-x-4 ${desbloqueada ? 'bg-green-100 border-green-500' : 'bg-gray-200 border-gray-400 opacity-60'}`;

      card.innerHTML = `
        <div class="text-3xl">${c.icone || '🏅'}</div>
        <div>
          <h2 class="text-xl font-semibold">${c.nome}</h2>
          <p>${c.descricao}</p>
          <p class="mt-2 text-sm ${desbloqueada ? 'text-green-600' : 'text-gray-600'}">
            ${desbloqueada ? '✅ Desbloqueada' : `🔒 Requer ${c.meta} ${c.tipo === 'dias_sem_jogar' ? 'dias sem jogar' : 'atividades'}`}
          </p>
        </div>
      `;

      container.appendChild(card);
    });

  } catch (error) {
    container.innerHTML = `<p class="text-red-600 text-center">${error.message}</p>`;
    console.error(error);
  }
}


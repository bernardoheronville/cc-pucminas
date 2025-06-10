function logout() {
      localStorage.removeItem('user');
      window.location.href = 'login.html';
    }

    async function carregarDetalhes() {
      const params = new URLSearchParams(window.location.search);
      const id = params.get('id');
      const res = await fetch(`http://localhost:3000/filmes/${id}`);
      const item = await res.json();

      const secao = document.getElementById('detalhesItem');
      secao.innerHTML = `
        <h2>${item.titulo}</h2>
        <p>${item.descricao}</p>
        <img src="${item.imagem}" alt="${item.titulo}" class="img-detalhe">
        <button onclick="toggleFavorito(${item.id}, ${item.favorito})">
          ${item.favorito ? '❤️' : '🤍'}
        </button>
      `;

      const galeria = document.getElementById('galeriaFotos');
      for (let i = 0; i < 5; i++) {
        const img = document.createElement('img');
        img.src = item.imagem;
        img.alt = `Foto ${i + 1}`;
        galeria.appendChild(img);
      }
    }

    async function toggleFavorito(id, favoritoAtual) {
      await fetch(`http://localhost:3000/filmes/${id}`, {
        method: 'PATCH',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ favorito: !favoritoAtual })
      });
      carregarDetalhes();
    }

    carregarDetalhes();
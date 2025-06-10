function logout() {
      localStorage.removeItem('user');
      window.location.href = 'login.html';
    }

    async function carregarFavoritos() {
      const response = await fetch('http://localhost:3000/filmes');
      const filmes = await response.json();
      const container = document.getElementById('favoritosContainer');

      container.innerHTML = '';
      filmes.filter(f => f.favorito).forEach(filme => {
        const card = document.createElement('div');
        card.className = 'card-item';

        card.onclick = () => {
          window.location.href = `detalhes.html?id=${filme.id}`;
        };

        card.innerHTML = `
          <img src="${filme.imagem}" alt="${filme.titulo}">
          <h3>${filme.titulo}</h3>
        `;
        container.appendChild(card);
      });
    }

    carregarFavoritos();
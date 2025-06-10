function logout() {
    localStorage.removeItem('user');
    window.location.href = 'login.html';
}

async function carregarItens() {
    try {
        const res = await fetch('http://localhost:3000/filmes');
        const dados = await res.json();
        const container = document.getElementById('gridItens');
        container.innerHTML = '';
        dados.forEach(item => {
            const card = document.createElement('div');
            card.className = 'card-item';

            card.innerHTML = `
              <img src="${item.imagem}" alt="${item.titulo}">
              <h3>${item.titulo}</h3>
              <p>${item.descricao}</p>
              <button onclick="toggleFavorito(event, '${item.id}')">
                ${item.favorito ? '❤️' : '🤍'}
              </button>
            `;

            card.onclick = () => {
                window.location.href = `detalhes.html?id=${item.id}`;
            };
            
            container.appendChild(card);
        });
    } catch (error) {
        console.error('Erro ao carregar itens:', error);
    }
}

async function toggleFavorito(event, id) {
    event.stopPropagation(); 

    try {
        const res = await fetch(`http://localhost:3000/filmes/${id}`);
        const item = await res.json();
        await fetch(`http://localhost:3000/filmes/${id}`, {
            method: 'PATCH',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ favorito: !item.favorito })
        });
        carregarItens(); 
    } catch (error) {
        console.error('Erro ao favoritar:', error);
    }
}

async function carregarDestaques() {
    try {
        const res = await fetch('http://localhost:3000/filmes');
        const filmes = await res.json();
        const carrossel = document.getElementById('carrossel');
        
        if (!carrossel) return;
        carrossel.innerHTML = '';

        filmes.slice(0, 8).forEach(filme => {
            const link = document.createElement('a');
            link.href = `detalhes.html?id=${filme.id}`;
            const img = document.createElement('img');
            img.src = filme.imagem;
            img.alt = filme.titulo;
            link.appendChild(img);
            carrossel.appendChild(link);
        });
    } catch (error) {
        console.error('Erro ao carregar destaques:', error);
    }
}

async function carregarGraficoFilmes() {
    const ctx = document.getElementById('myChart');
    if (!ctx) return;

    try {
        const response = await fetch('http://localhost:3000/filmes');
        if (!response.ok) throw new Error(`Erro HTTP: ${response.status}`);
        
        const filmes = await response.json();
        
        if (filmes.length === 0) {
            new Chart(ctx, { type: 'bar', data: { labels: ['Sem dados'], datasets: [{ label: 'Nenhum filme cadastrado', data: [0] }] }});
            return;
        }

        const labels = filmes.map(filme => filme.titulo);
        
        const dataPoints = filmes.map(() => Math.floor(Math.random() * 91) + 10); 

        const backgroundColors = filmes.map(() => `rgba(${Math.floor(Math.random() * 200 + 55)}, ${Math.floor(Math.random() * 200 + 55)}, ${Math.floor(Math.random() * 200 + 55)}, 0.6)`);
        
        new Chart(ctx, {
            type: 'bar',
            data: { 
                labels: labels, 
                datasets: [{ 
                    label: 'Popularidade', 
                    data: dataPoints, 
                    backgroundColor: backgroundColors, 
                    borderWidth: 1 
                }] 
            },
            options: { 
                responsive: true, 
                maintainAspectRatio: true, 
                scales: { 
                    y: { beginAtZero: true, ticks: { precision: 0 } }, 
                    x: { ticks: { autoSkip: false, maxRotation: 45, minRotation: 45 } } 
                }, 
                plugins: { 
                    legend: { display: true, position: 'top' }, 
                    title: { display: true, text: 'Gráfico de Popularidade de Filmes' } 
                } 
            }
        });

    } catch (error) {
        console.error('Falha ao carregar dados para o gráfico:', error);
    }
}

document.addEventListener('DOMContentLoaded', () => {
    const carrossel = document.getElementById('carrossel');
    const btnAnterior = document.querySelector('.btn-anterior');
    const btnProximo = document.querySelector('.btn-proximo');

    if (btnAnterior && carrossel) {
        btnAnterior.onclick = () => {
            carrossel.scrollLeft -= 400; 
        };
    }
    
    if (btnProximo && carrossel) {
        btnProximo.onclick = () => {
            carrossel.scrollLeft += 400;
        };
    }
    
    carregarItens();
    carregarDestaques();
    carregarGraficoFilmes();
});
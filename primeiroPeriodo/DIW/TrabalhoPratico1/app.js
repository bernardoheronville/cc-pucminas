const filmes = [
    {
        id: 1,
        titulo: "Um Filme Minecraft",
        dataLancamento: "2025-04-03",
        nomeOriginal: "A Minecraft Movie",
        categoria: "Aventura, Comédia, Familia",
        descricao: "Nessa aventura inédita, quatro indivíduos desajustados são subitamente transportados para o Overworld, um mundo cúbico e bizarro onde a imaginação reina. Após passarem por um portal misterioso, eles terão que dominar este novo ambiente com a ajuda de um construtor imprevisível.",
        imagem: "imagens/FotosFilmes/Minecraft logo.webp"
    },
    {
        id: 2,
        titulo: "Branca de Neve",
        dataLancamento: "2025-03-20",
        nomeOriginal: "Disney's Snow White",
        categoria: "Aventura, Fantasia, Comédia Musical",
        descricao: "A princesa Branca de Neve (Rachel Zegler) foge do reino após sua madrasta, a Rainha Má (Gal Gadot), ordenar sua morte por inveja. Na floresta, ela encontra sete anões que a acolhem, mas o perigo persiste, pois a vilã planeja envenená-la com uma maçã.",
        imagem: "imagens/FotosFilmes/Branca de neve Logo.jpg"
    },
    {
        id: 3,
        titulo: "Operação Vingança",
        dataLancamento: "2025-04-10",
        nomeOriginal: "The Amateur",
        categoria: "Drama, Suspense",
        descricao: "Após a trágica morte de sua esposa em um ataque terrorista em Londres, Charles Heller (Rami Malek), um criptógrafo altamente capacitado da CIA, completamente desesperado por justiça e com a dor da perda a consumi-lo, Heller toma uma decisão radical.",
        imagem: "imagens/FotosFilmes/Operacao Vinganca logo.webp"
    },
];

document.addEventListener('DOMContentLoaded', () => {
    const filmesContainer = document.getElementById('filmes-container');

    filmes.forEach(filme => {
        const link = document.createElement('a');
        link.href = `detalhes.html?id=${filme.id}`;
        link.style.textDecoration = 'none'; 

        const article = document.createElement('article');
        article.classList.add('caixa-filme');

        const img = document.createElement('img');
        img.src = filme.imagem;
        img.alt = `Imagem do filme ${filme.titulo}`;

        const tituloH3 = document.createElement('h3');
        tituloH3.classList.add('titulo');
        tituloH3.textContent = filme.titulo;

        const subtituloH4 = document.createElement('h4');
        subtituloH4.classList.add('subtitulo');
        subtituloH4.innerHTML = `
            <span>${new Date(filme.dataLancamento).toLocaleDateString()}</span> -
            <span>${filme.nomeOriginal}</span> -
            <span>${filme.categoria}</span>
        `;

        const textoP = document.createElement('p');
        textoP.classList.add('texto');
        textoP.textContent = filme.descricao;

        article.appendChild(img);
        article.appendChild(tituloH3);
        article.appendChild(subtituloH4);
        article.appendChild(textoP);

        link.appendChild(article); 
        filmesContainer.appendChild(link);
    });
});

document.addEventListener('DOMContentLoaded', () => {
    const detalhesContainer = document.getElementById('detalhes-container');
    const urlParams = new URLSearchParams(window.location.search);
    const filmeId = parseInt(urlParams.get('id'));

    if (filmeId) {
        const filme = filmes.find(f => f.id === filmeId);

        if (filme) {
            const article = document.createElement('article');
            article.classList.add('detalhes-filme');

            const img = document.createElement('img');
            img.src = filme.imagem;
            img.alt = `Imagem do filme ${filme.titulo}`;

            const tituloH1 = document.createElement('h1');
            tituloH1.textContent = filme.titulo;

            const nomeOriginalH2 = document.createElement('h2');
            nomeOriginalH2.textContent = filme.nomeOriginal;

            const dataLancamentoP = document.createElement('p');
            dataLancamentoP.textContent = `Data de Lançamento: ${new Date(filme.dataLancamento).toLocaleDateString()}`;

            const categoriaP = document.createElement('p');
            categoriaP.textContent = `Categoria: ${filme.categoria}`;

            const descricaoP = document.createElement('p');
            descricaoP.textContent = filme.descricao;

            article.appendChild(img);
            article.appendChild(tituloH1);
            article.appendChild(nomeOriginalH2);
            article.appendChild(dataLancamentoP);
            article.appendChild(categoriaP);
            article.appendChild(descricaoP);

            detalhesContainer.appendChild(article);
        } else {
            detalhesContainer.innerHTML = '<p>Filme não encontrado.</p>';
        }
    } else {
        detalhesContainer.innerHTML = '<p>ID do filme não especificado.</p>';
    }
});
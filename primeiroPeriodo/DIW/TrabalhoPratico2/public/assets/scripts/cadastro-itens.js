const url = 'http://localhost:3000/filmes';

    function logout() {
      localStorage.removeItem('user');
      window.location.href = 'login.html';
    }

    async function carregarItens() {
      const res = await fetch(url);
      const dados = await res.json();
      const tabela = document.getElementById('tabelaItens');
      tabela.innerHTML = '';
      dados.forEach(item => {
        const linha = `<tr>
          <td>${item.id}</td>
          <td>${item.titulo}</td>
          <td>${item.descricao}</td>
          <td>
            <button onclick='editar(${JSON.stringify(item)})'>Editar</button>
            <button onclick='deletar(${item.id})'>Excluir</button>
          </td>
        </tr>`;
        tabela.innerHTML += linha;
      });
    }

    document.getElementById('formCadastro').addEventListener('submit', async function(e) {
      e.preventDefault();
      const novoItem = {
        titulo: titulo.value,
        descricao: descricao.value,
        imagem: imagem.value,
        favorito: false
      };
      await fetch(url, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(novoItem)
      });
      this.reset();
      carregarItens();
    });

    function editar(item) {
      itemId.value = item.id;
      titulo.value = item.titulo;
      descricao.value = item.descricao;
      imagem.value = item.imagem;
    }

    async function alterarItem() {
      if (!itemId.value) return alert('Selecione um item para alterar.');
      await fetch(`${url}/${itemId.value}`, {
        method: 'PUT',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          titulo: titulo.value,
          descricao: descricao.value,
          imagem: imagem.value,
          favorito: false
        })
      });
      formCadastro.reset();
      carregarItens();
    }

    async function deletar(id) {
      await fetch(`${url}/${id}`, { method: 'DELETE' });
      carregarItens();
    }

    function excluirItem() {
      if (!itemId.value) return alert('Selecione um item para excluir.');
      deletar(itemId.value);
      formCadastro.reset();
    }

    carregarItens();
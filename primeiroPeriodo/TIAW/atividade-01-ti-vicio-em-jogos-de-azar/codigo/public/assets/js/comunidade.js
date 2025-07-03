let posts = [];

// Carregar usuário logado
const usuarioCorrente = JSON.parse(sessionStorage.getItem("usuarioCorrente"));

function formatDate(dateStr) {
  const options = { year: 'numeric', month: 'long', day: 'numeric' };
  const dateObj = new Date(dateStr);
  return dateObj.toLocaleDateString('pt-BR', options);
}

function formatTimestamp(timestampStr) {
  const d = new Date(timestampStr);
  if (isNaN(d)) return timestampStr;
  return d.toLocaleString('pt-BR', {
    day: '2-digit', month: '2-digit', year: 'numeric',
    hour: '2-digit', minute: '2-digit'
  }).replace(',', '');
}

 function createHeartIcon(filled) {
      const ns = "http://www.w3.org/2000/svg";
      const svg = document.createElementNS(ns, "svg");
      svg.setAttribute("viewBox", "0 0 24 24");
      svg.setAttribute("aria-hidden", "true");
      svg.setAttribute("focusable", "false");
      svg.setAttribute("width", "18");
      svg.setAttribute("height", "18");
      const path = document.createElementNS(ns, "path");
      path.setAttribute("fill-rule", "evenodd");
      path.setAttribute("clip-rule", "evenodd");
      path.setAttribute("fill", "currentColor");
      if (filled) {
        path.setAttribute("d", "M12 21.35l-1.45-1.32C5.4 15.36 2 12.28 2 8.5 2 5.42 4.42 3 7.5 3c1.74 0 3.41 1.01 4.5 2.09A6.56 6.56 0 0 1 16.5 3 5.5 5.5 0 0 1 22 8.5c0 3.78-3.4 6.86-8.55 11.54L12 21.35z");
      } else {
        path.setAttribute("d", "M16.5 3c-1.74 0-3.41 1.01-4.5 2.09A6.56 6.56 0 0 0 7.5 3 5.5 5.5 0 0 0 2 8.5c0 3.78 3.4 6.86 8.55 11.54L12 21.35l1.45-1.32C18.6 15.36 22 12.28 22 8.5A5.5 5.5 0 0 0 16.5 3zm-4.4 15.55l-.1.1-.1-.1C7.14 14.24 4 11.39 4 8.5A3.5 3.5 0 0 1 7.5 5c1.54 0 3.04.99 3.57 2.36h1.87C13.46 5.99 14.96 5 16.5 5A3.5 3.5 0 0 1 20 8.5c0 2.89-3.14 5.74-7.9 10.05z");
      }
      path.setAttribute("fill", "currentColor");
      svg.appendChild(path);
      return svg;
    }


    function createCommentIcon() {
      const ns = "http://www.w3.org/2000/svg";
      const svg = document.createElementNS(ns, "svg");
      svg.setAttribute("viewBox", "0 0 24 24");
      svg.setAttribute("aria-hidden", "true");
      svg.setAttribute("focusable", "false");
      svg.setAttribute("width", "18");
      svg.setAttribute("height", "18");
      const path = document.createElementNS(ns, "path");
      path.setAttribute("d", "M20 2H4c-1.1 0-2 .9-2 2v14l4-4h14c1.1 0 2-.9 2-2V4c0-1.1-.9-2-2-2z");
      path.setAttribute("fill-rule", "evenodd");
      svg.appendChild(path);
      return svg;
    }





function createCommentIcon() {
  const ns = "http://www.w3.org/2000/svg";
  const svg = document.createElementNS(ns, "svg");
  svg.setAttribute("viewBox", "0 0 24 24");
  svg.setAttribute("aria-hidden", "true");
  svg.setAttribute("focusable", "false");
  svg.setAttribute("width", "18");
  svg.setAttribute("height", "18");
  const path = document.createElementNS(ns, "path");
  path.setAttribute("d", "M20 2H4c-1.1 0-2 .9-2 2v14l4-4h14c1.1 0 2-.9 2-2V4c0-1.1-.9-2-2-2z");
  path.setAttribute("fill-rule", "evenodd");
  svg.appendChild(path);
  return svg;
}

function renderCommentItem(comment) {
  const li = document.createElement('li');
  li.className = 'comment-item';
  const strong = document.createElement('strong');
  strong.textContent = comment.author;
  const date = document.createElement('time');
  date.textContent = formatTimestamp(comment.date);
  const text = document.createElement('p');
  text.textContent = comment.text;
  li.append(strong, date, text);
  return li;
}

function createPostCard(post) {
  const article = document.createElement('article');
  article.className = 'post-card';
  article.tabIndex = 0;

  const postTitle = document.createElement('h2');
  postTitle.className = 'post-title';
  postTitle.textContent = post.title;

  const postMeta = document.createElement('div');
  postMeta.className = 'post-meta';
  postMeta.textContent = `Por ${post.authorName} • ${formatDate(post.date)}`;

  const postContent = document.createElement('p');
  postContent.className = 'post-content';
  postContent.textContent = post.content;

  const actions = document.createElement('div');
  actions.className = 'post-actions';

  const likeButton = document.createElement('button');
  likeButton.type = 'button';
  likeButton.className = 'like-button';
  if (post.liked) likeButton.classList.add('liked');
  likeButton.setAttribute('aria-pressed', post.liked ? 'true' : 'false');

  const likeIcon = createHeartIcon(post.liked);
  likeButton.appendChild(likeIcon);

  const likeCountSpan = document.createElement('span');
  likeCountSpan.textContent = post.likesCount;
  likeButton.appendChild(likeCountSpan);
  actions.appendChild(likeButton);

  const commentToggleButton = document.createElement('button');
  commentToggleButton.type = 'button';
  commentToggleButton.className = 'comment-toggle-button';

  const commentIcon = createCommentIcon();
  commentToggleButton.appendChild(commentIcon);
  const commentTextSpan = document.createElement('span');
  commentTextSpan.textContent = 'Comentários';
  commentToggleButton.appendChild(commentTextSpan);
  actions.appendChild(commentToggleButton);

  const commentsSection = document.createElement('section');
  commentsSection.className = 'comments-section';

  const commentList = document.createElement('ul');
  commentList.className = 'comment-list';
  post.comments.forEach(c => commentList.appendChild(renderCommentItem(c)));

  const commentForm = document.createElement('form');
  commentForm.className = 'comment-form';

  const textarea = document.createElement('textarea');
  textarea.name = 'comment';
  textarea.placeholder = 'Escreva seu comentário...';
  commentForm.appendChild(textarea);

  const submitButton = document.createElement('button');
  submitButton.type = 'submit';
  submitButton.textContent = 'Enviar';
  commentForm.appendChild(submitButton);

  commentsSection.appendChild(commentList);
  commentsSection.appendChild(commentForm);

  article.appendChild(postTitle);
  article.appendChild(postMeta);
  article.appendChild(postContent);
  article.appendChild(actions);
  article.appendChild(commentsSection);

  likeButton.addEventListener('click', () => {
    event.preventDefault(); 
    if (!usuarioCorrente) {
      alert("Você precisa estar logado para curtir.");
      return;
    }

    // Verifica se usuário atual já curtiu
    const userIdIndex = post.likedBy ? post.likedBy.indexOf(usuarioCorrente.id) : -1;

    if (userIdIndex === -1) {
      // Usuário ainda não curtiu -> adiciona
      if (!post.likedBy) post.likedBy = [];
      post.likedBy.push(usuarioCorrente.id);
    } else {
      // Usuário já curtiu -> remove
      post.likedBy.splice(userIdIndex, 1);
    }

    // Atualiza likesCount e liked para refletir estado atual
    post.likesCount = post.likedBy.length;
    post.liked = post.likedBy.includes(usuarioCorrente.id);

    // Atualiza interface
    likeCountSpan.textContent = post.likesCount;
    likeButton.classList.toggle('liked', post.liked);
    likeButton.setAttribute('aria-pressed', post.liked ? 'true' : 'false');
    const newIcon = createHeartIcon(post.liked);
    likeButton.replaceChild(newIcon, likeButton.firstChild);

    // Salva no backend
    fetch(`/posts/${post.id}`, {
      method: "PATCH",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        likedBy: post.likedBy,
        likesCount: post.likesCount
      })
    })
      .then(res => {
        if (!res.ok) throw new Error(`Erro ao salvar like: ${res.status}`);
        return res.json();
      })
      .catch(err => {
        console.error("Erro ao salvar like:", err);
        alert("Não foi possível salvar o like.");


        if (post.liked) {

          post.likedBy = post.likedBy.filter(id => id !== usuarioCorrente.id);
        } else {

          if (!post.likedBy) post.likedBy = [];
          post.likedBy.push(usuarioCorrente.id);
        }
        post.likesCount = post.likedBy.length;
        post.liked = post.likedBy.includes(usuarioCorrente.id);

        likeCountSpan.textContent = post.likesCount;
        likeButton.classList.toggle('liked', post.liked);
        likeButton.setAttribute('aria-pressed', post.liked ? 'true' : 'false');
        likeButton.replaceChild(createHeartIcon(post.liked), likeIcon);
      });
  });


  commentToggleButton.addEventListener('click', () => {
    commentsSection.classList.toggle('active');
    textarea.focus();
  });

  commentForm.addEventListener('submit', e => {
    e.preventDefault();
    const text = textarea.value.trim();
    if (!text || !usuarioCorrente) {
      alert('Você precisa estar logado para comentar.');
      return;
    }

    const newComment = {
      authorId: usuarioCorrente.id,
      author: usuarioCorrente.nome,
      text,
      date: new Date().toISOString()
    };

    fetch(`/posts/${post.id}`, {
      method: "PATCH",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ comments: [...post.comments, newComment] })
    })
      .then(res => {
        if (!res.ok) throw new Error(`Erro: ${res.status}`);
        return res.json();
      })
      .then(updatedPost => {
        post.comments = updatedPost.comments; // Atualiza localmente
        commentList.appendChild(renderCommentItem(newComment));
        textarea.value = '';
      })
      .catch(err => {
        console.error("Erro ao salvar comentário:", err);
        alert("Não foi possível salvar o comentário.");
      });
  });

  return article;
}

function renderPosts(container, posts) {
  container.innerHTML = '';
  posts.forEach(post => container.appendChild(createPostCard(post)));
}

const modalBackdrop = document.getElementById('modal-backdrop');
const newPostButton = document.getElementById('new-post-button');
const modalForm = document.getElementById('new-post-form');
const cancelButton = document.getElementById('cancel-button');

function openModal() {
  modalBackdrop.classList.add('active');
  document.body.style.overflow = 'hidden';
}

function closeModal() {
  modalBackdrop.classList.remove('active');
  modalForm.reset();
  document.body.style.overflow = '';
}

// Abrir modal para novo post
newPostButton.addEventListener('click', () => {
  if (!usuarioCorrente) {
    alert('Você precisa estar logado para criar um post.');
    return;
  }
  openModal();
});

// Cancelar criação de post
cancelButton.addEventListener('click', () => closeModal());

// Criar novo post
modalForm.addEventListener('submit', e => {
  e.preventDefault();
  if (!usuarioCorrente) {
    alert('Você precisa estar logado para criar um post.');
    return;
  }

  const titleInput = modalForm.elements['title'];
  const contentInput = modalForm.elements['content'];
  if (!titleInput.value.trim() || !contentInput.value.trim()) {
    alert('Título e conteúdo são obrigatórios.');
    return;
  }

  const newPost = {
    id: String(Date.now()), // id como string
    title: titleInput.value.trim(),
    authorName: usuarioCorrente.nome,
    userId: usuarioCorrente.id,
    date: new Date().toISOString(),
    content: contentInput.value.trim(),
    liked: false,
    likesCount: 0,
    comments: []
  };

  fetch("/posts", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(newPost)
  })
    .then(res => {
      if (!res.ok) throw new Error(`Erro: ${res.status}`);
      return res.json();
    })
    .then(savedPost => {
      posts.unshift(savedPost);
      renderPosts(document.querySelector("main"), posts);
      closeModal();
    })
    .catch(err => {
      console.error("Erro ao salvar o post:", err);
      alert("Erro ao salvar o post. Tente novamente.");
    });
});

// Carregar posts ao iniciar
document.addEventListener('DOMContentLoaded', () => {
  fetch("/posts")
    .then(res => {
      if (!res.ok) throw new Error(`Erro: ${res.status}`);
      return res.json();
    })
    .then(data => {
      posts = data;

      posts.forEach(post => {
        post.liked = post.likedBy && usuarioCorrente
          ? post.likedBy.includes(usuarioCorrente.id)
          : false;
      });

      renderPosts(document.querySelector('main'), posts);
    })
    .catch(err => {
      console.error("Erro ao carregar posts:", err);
    });
});


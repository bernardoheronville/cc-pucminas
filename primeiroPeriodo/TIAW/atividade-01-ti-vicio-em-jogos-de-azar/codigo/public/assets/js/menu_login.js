
document.addEventListener("DOMContentLoaded", () => {
  const usuarioJSON = sessionStorage.getItem("usuarioCorrente");
  const menu = document.getElementById("menu-links");
  const loginLink = document.getElementById("login-link");

  if (usuarioJSON) {
    // Usuário logado
    if (loginLink) {
      loginLink.textContent = "Perfil";
      loginLink.href = "login/pagina_usuario.html"; 
    }

    if (!document.getElementById("btnSair")) {
      const liSair = document.createElement("li");
      liSair.classList.add("nav-item");

      const btnSair = document.createElement("button");
      btnSair.id = "btnSair";
      btnSair.textContent = "Sair";
      btnSair.classList.add("btn", "btn-danger", "ms-3"); 

      btnSair.addEventListener("click", () => {
        sessionStorage.removeItem("usuarioCorrente");
        window.location.href = "index.html"; 
      });

      liSair.appendChild(btnSair);
      menu.appendChild(liSair);
    }
  } else {
   
  }
});

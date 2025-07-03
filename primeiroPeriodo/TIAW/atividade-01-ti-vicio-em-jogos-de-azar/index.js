const express = require('express');
const jsonServer = require('json-server');
const path = require('path');

const app = express();
const router = jsonServer.router(path.join(__dirname, 'codigo', 'db', 'db.json'));
const middlewares = jsonServer.defaults();

// Middleware padrão do JSON Server
app.use(middlewares);

// Rotas da API ficam sob o prefixo /api
app.use('/api', router);

// Frontend (HTML/CSS/JS)
const frontendPath = path.join(__dirname, 'codigo', 'public');
app.use(express.static(frontendPath));

// SPA fallback (sempre retorna index.html)
app.get('*', (req, res) => {
  res.sendFile(path.join(frontendPath, 'index.html'));
});

// Inicia o servidor
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Servidor rodando em http://localhost:${PORT}`);
});

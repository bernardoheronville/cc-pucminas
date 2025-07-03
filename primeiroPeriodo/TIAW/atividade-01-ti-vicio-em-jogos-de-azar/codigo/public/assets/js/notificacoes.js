const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');
const path = require('path');

const app = express();
const PORT = 3000;

let notifications = [
  { id: 1, type: 'motivacional', message: 'Você está há 5 dias sem jogar! Incrível!', read: false },
  { id: 2, type: 'alerta', message: 'Evite acessar sites de apostas hoje.', read: false },
  { id: 3, type: 'progresso', message: 'Seu progresso está sendo salvo automaticamente.', read: true }
];

app.use(cors());
app.use(bodyParser.json());

app.use(express.static(path.join(__dirname, 'public')));

app.get('/api/notifications', (req, res) => {
  res.json(notifications);
});

app.post('/api/notifications', (req, res) => {
  const { type, message } = req.body;
  const newNotification = {
    id: notifications.length + 1,
    type,
    message,
    read: false
  };
  notifications.unshift(newNotification);
  res.status(201).json(newNotification);
});

app.patch('/api/notifications/:id/read', (req, res) => {
  const id = parseInt(req.params.id);
  const index = notifications.findIndex(n => n.id === id);
  if (index !== -1) {
    notifications[index].read = true;
    res.json(notifications[index]);
  } else {
    res.status(404).json({ error: 'Notificação não encontrada' });
  }
});

app.listen(PORT, () => {
  console.log(`✅ Servidor rodando: http://localhost:${PORT}`);
});
const express = require("express");
const cors = require("cors");
const path = require("path");

let lastData = { temperature: null, humidity: null, device: null, time: null };

const app = express();
app.use(cors());
app.use(express.json());

// SERVE A PASTA PUBLIC (que está no mesmo nível do server.js)
app.use(express.static(path.join(__dirname, "public")));

// ABRE O DASHBOARD NA ROTA PRINCIPAL "/"
app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "public/dashboard.html"));
});

app.post("/data", (req, res) => {
  lastData = {
    temperature: req.body.temperature,
    humidity: req.body.humidity,
    device: req.body.device,
    time: new Date().toLocaleTimeString()
  };

  console.log("Recebido:", lastData);
  res.json({ ok: true });
});

app.get("/data", (req, res) => {
  res.json(lastData);
});

app.listen(3000, () => {
  console.log("API rodando em http://localhost:3000");
});

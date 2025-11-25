# Projeto-A3
Projeto A3 IoT
🚀 Sobre o Projeto

Este projeto é um sistema IoT completo composto por:

Backend (Node.js + Express)

Banco de dados (SQLite)

Frontend Web

Dashboard para visualização dos dados

Integração com ESP32 (via API)

O objetivo é criar um ambiente onde um dispositivo IoT envia dados para o servidor, que armazena e exibe essas informações de forma visual.

# 📁 Estrutura do Projeto
A3/
 ├── server/        → Backend (Node.js)
 │    ├── index.js
 │    ├── database.db
 │    ├── package.json
 │    └── .gitignore
 │
 ├── frontend/      → Página Web
 │    ├── index.html
 │    ├── style.css
 │    └── script.js
 │
 ├── esp32/         → Código do ESP32
 │    └── esp32.ino
 │
 └── README.md

# ⚙️ Como Rodar o Projeto
# 🔧 1. Pré-requisitos

Você precisa ter instalado:

Node.js (versão LTS)

Git (opcional, mas recomendado)

VS Code ou outro editor

# 🖥️ 2. Configurar o Backend (server/)
👉 Entre na pasta do servidor:
cd server

👉 Instale as dependências:
npm install


Caso apareça erro no better-sqlite3, use:

npm install --build-from-source

👉 Rode o servidor:
npm start


Ou:

node index.js

🔥 O servidor irá iniciar em:
http://localhost:3000

# 🌐 3. Rodar o Frontend (frontend/)

Não precisa instalar nada.

Basta abrir o arquivo:

frontend/index.html


ou usar uma extensão como Live Server do VS Code.

# 📡 4. Conectar o ESP32

No código do ESP32 você precisa configurar:

const char* serverUrl = "http://SEU_IP:3000/sensor";


⚠️ Se estiver no Wokwi, use o IP indicado no console (geralmente 10.0.0.0/24).

Depois, o ESP32 irá enviar dados para o endpoint:

POST /sensor

# 📊 5. Dashboard

Acesse:

http://localhost:3000/dashboard


# Aqui você vê:

Temperatura

Umidade

Última leitura

Histórico

Gráfico das medições

🔒 .gitignore (importante)

No server/, certifique-se de ter:

node_modules/
database.db


Para evitar subir arquivos pesados no GitHub.

# 🧪 Testar a API
Listar dados:
GET /data

Enviar dados (exemplo usando Postman):

POST:

http://localhost:3000/sensor


Body (JSON):

{
  "temperatura": 25,
  "umidade": 60
}

# 📦 Como subir o projeto no GitHub
1️⃣ Vá na pasta raiz A3:
cd A3

2️⃣ Inicialize o repositório:
git init

3️⃣ Adicione tudo:
git add .

4️⃣ Commit:
git commit -m "Primeiro commit"

5️⃣ Conecte ao GitHub:
git remote add origin https://github.com/SEU_USER/SEU_REPO.git

6️⃣ Envie:
git push -u origin main

# 🧩 Tecnologias Usadas

Node.js

Express

SQLite

HTML + CSS + JS

ESP32

Wokwi (simulação)

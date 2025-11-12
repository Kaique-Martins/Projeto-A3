#include <WiFi.h>
#include <WebServer.h>

// ===============================
// CONFIGURAÇÕES DE REDE
// ===============================
const char* ssid = "Wokwi-GUEST";   // Rede padrão do Wokwi
const char* password = "";           // Sem senha por enquanto no Wokwi

// ===============================
// SERVIDOR WEB
// ===============================
WebServer server(80);

// ===============================
// FUNÇÃO: Gera HTML principal
// ===============================
String generateHTML(float temperature) {
  String html = R"rawliteral(
  <!DOCTYPE html>
  <html lang='pt-BR'>
  <head>
    <meta charset='UTF-8'>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <title>Monitor de Temperatura - ESP32</title>
    <style>
      body {
        background-color: #0f0f0f;
        color: #e0e0e0;
        font-family: "Segoe UI", sans-serif;
        text-align: center;
        padding: 40px;
      }
      h1 {
        color: #00bfa5;
      }
      .card {
        background: #1f1f1f;
        border-radius: 20px;
        box-shadow: 0 0 15px rgba(0, 191, 165, 0.3);
        display: inline-block;
        padding: 40px;
        margin-top: 40px;
      }
      .temp {
        font-size: 4em;
        font-weight: bold;
        color: #00e676;
      }
      footer {
        margin-top: 50px;
        color: #888;
        font-size: 0.9em;
      }
    </style>
    <script>
      async function updateTemp() {
        const res = await fetch('/temp');
        const data = await res.text();
        document.getElementById('tempValue').innerText = data + ' °C';
      }
      setInterval(updateTemp, 2000); // Atualiza a cada 2s
    </script>
  </head>
  <body>
    <h1>Monitor de Temperatura - ESP32</h1>
    <div class='card'>
      <div id='tempValue' class='temp'>)rawliteral";

  html += String(temperature, 2);
  html += R"rawliteral( °C</div>
    </div>
    <footer>Servidor Web ESP32 • Atualização Automática</footer>
  </body>
  </html>)rawliteral";

  return html;
}

// ===============================
// HANDLERS DAS ROTAS
// ===============================
void handleRoot() {
  float temperature = temperatureRead();
  server.send(200, "text/html", generateHTML(temperature));
}

void handleTemp() {
  float temperature = temperatureRead();
  server.send(200, "text/plain", String(temperature, 2));
}

// ===============================
//  Inicialização
// ===============================
void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("🌐 Iniciando conexão Wi-Fi...");
  WiFi.begin(ssid, password);

  int retry = 0;
  while (WiFi.status() != WL_CONNECTED && retry < 30) {
    delay(500);
    Serial.print(".");
    retry++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println();
    Serial.println("✅ Wi-Fi conectado com sucesso!");
    Serial.print("🔗 Endereço IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println();
    Serial.println("❌ Falha na conexão Wi-Fi. Reinicie o dispositivo.");
    return;
  }

  // Configuração das rotas
  server.on("/", handleRoot);
  server.on("/temp", handleTemp);
  server.begin();

  Serial.println("🔥 Servidor HTTP iniciado!");
}

// ===============================
// 🔁 LOOP PRINCIPAL
// ===============================
void loop() {
  server.handleClient();
}

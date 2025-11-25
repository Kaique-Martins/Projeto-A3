const axios = require("axios");

async function sendData() {
  const temp = (20 + Math.random() * 8).toFixed(2);
  const hum  = (40 + Math.random() * 20).toFixed(2);

  console.log(`Enviando -> Temp: ${temp}°C | Hum: ${hum}%`);

  await axios.post("http://localhost:3000/data", {
    temperature: temp,
    humidity: hum,
    device: "Simulated-ESP32"
  });
}

setInterval(sendData, 3000);

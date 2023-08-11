#include <WiFi.h>
#include <WebServer.h>

#include "src/som/som.h"
#include "src/bpm/batimentoCardiaco.h"
#include "src/gps/gps.h"
#include "src/acc/acelerometro.h"

const char* ssid = "";
const char* password = "";

WebServer server(80);
String info = "";

Som som(35);
BatimentoCardiaco bpm(34);
Gps gps(16, 17);
Acelerometro acc(21, 22);

int valorBpm;
int valorSom;
float latitude, longitude;
float x, y, z;

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  WifiInfo();

  iniciaServer();

  som.inicializar();
  bpm.inicializar();
  gps.inicializar();
  acc.inicializar();

  delay(2000);
}

void loop() {
  server.handleClient();
}

void iniciaServer() {
  server.on("/pulso", sensorBPM);
  server.on("/som", sensorSom);
  server.on("/acelerometro", acelerometro);
  server.on("/gps", moduloGPS);
  server.begin();
}

void WifiInfo() {
  Serial.println("");
  Serial.println("WiFi conectada.");
  Serial.println("Endereço de IP: ");
  Serial.println(WiFi.localIP());
}

void sensorSom() {
  som.lerNivelSom(valorSom);
  info = "Som = " + String(valorSom);
  server.send(200, "text/plain", info);
}

void sensorBPM() {
  bpm.lerBatimentoCardiaco(valorBpm);
  info = "Pulso = " + String(valorBpm);
  server.send(200, "text/plain", info);
}

void moduloGPS() {

  if (gps.lerDadoGPS(latitude, longitude)) {
    info = "Latitude: " + String(latitude, 6) + "\nLongitude: " + String(longitude, 6);
  } else {
    info = "Não foi detectada a localização";
  }

  server.send(200, "text/plain", info);
}

void acelerometro() {

  acc.lerDadoAcelerometro(x, y, z);
  info = "X: " + String(x, 6) + "\ny:" + String(y, 6) + "\nz:" + String(z, 6);
  server.send(200, "text/plain", info);
}
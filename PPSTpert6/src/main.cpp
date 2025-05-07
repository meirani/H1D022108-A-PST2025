// LED IOT

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "Mei's S23 FE";
const char *password = "chenjijichen";

ESP8266WebServer server(80);
String webpage;

void setup()
{
  Serial.begin(9600);
  delay(10);

  pinMode(D2, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D6, OUTPUT);

  // Connect to WiFi network
  Serial.println();
  Serial.print("Konfigurasi akses poin...");

  // Mengatur WiFi
  WiFi.mode(WIFI_AP);
  WiFi.begin(ssid, password);

  // Cek status koneksi
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());

  // Isi webpage
  webpage += "<h1> Web Control ESP8266</h1>";
  webpage += "<h2> Nabila Meirani</h2>";
  webpage += "<p>LED 1: </p>";
  webpage += "<p><a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  webpage += "<p>LED 2: </p>";
  webpage += "<p><a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  webpage += "<p>LED 3: </p>";
  webpage += "<p><a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p><br>";

  // Membuat tampilan Webpage
  server.on("/", []()
            { server.send(200, "text/html", webpage); });

  // Bagian ini untuk merespon perintah yang masuk
  server.on("/LED1ON", []()
            {
              server.send(200, "text/html", webpage);
              digitalWrite(D2, HIGH);
              delay(1000); });
  server.on("/LED2ON", []()
            {
              server.send(200, "text/html", webpage);
              digitalWrite(D4, HIGH);
              delay(1000); });
  server.on("/LED3ON", []()
            {
              server.send(200, "text/html", webpage);
              digitalWrite(D6, HIGH);
              delay(1000); });

  server.on("/LED1OFF", []()
            {
              server.send(200, "text/html", webpage);
              digitalWrite(D2, LOW);
              delay(1000); });
  server.on("/LED2OFF", []()
            {
              server.send(200, "text/html", webpage);
              digitalWrite(D4, LOW);
              delay(1000); });
  server.on("/LED3OFF", []()
            {
              server.send(200, "text/html", webpage);
              digitalWrite(D6, LOW);
              delay(1000); });

  server.begin();
  Serial.println("Webserver dijalankan");
}

void loop()
{
  server.handleClient();
}

#include <Arduino.h>

int LED1 = D0; // initalisasi, knp int isinya bisa string? karena udh di setting
int LED2 = D4;
int LED3 = D6;

void setup()
{
  pinMode(LED1, OUTPUT); // led nya mengeluarkan tegangan
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop()
{
  digitalWrite(LED1, HIGH); // alurin daya listrik tinggi, jadinya nyala
  delay(100);               // selama 5 second (5000 itu dalam ms)
  digitalWrite(LED1, LOW);  // matiin lednya alias atur daya nya jadi low
  digitalWrite(LED2, HIGH);
  delay(100);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(100);
  digitalWrite(LED3, LOW);
}
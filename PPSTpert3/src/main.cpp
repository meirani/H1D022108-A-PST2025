#include <Arduino.h>

// deklarasi variabel
int echoPin = D6;
int trigPin = D5;
int ledPin1 = D3;

// deklarasi variabel waktu dan jarak
long duration;
int distance;

void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // untuk menghitung waktu sinyal diterima
  duration = pulseIn(echoPin, HIGH);

  // menghitung jarak
  distance = duration * 0.034 / 2;

  // display serial monitor
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");

  // set LED berdasarkan kondisi
  if (distance >= 10)
  {
    digitalWrite(ledPin1, HIGH);
  }
  else
  {
    digitalWrite(ledPin1, LOW);
  }

  delay(1000);
}

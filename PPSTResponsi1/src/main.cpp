#include <Arduino.h>
#include <Servo.h>

// deklarasi variabel
int echoPin = D3;
int trigPin = D4;

Servo myservo;

// Variabel jarak
long duration;
int distance;

void setup()
{
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myservo.attach(D6);
  myservo.write(0);
}

void loop()
{
  // kirim sinyal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // menghitung waktu sinyal diterima
  duration = pulseIn(echoPin, HIGH);

  // menghitung jarak
  distance = duration * 0.034 / 2;

  // display serial monitor
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance > 0 && distance <= 15)
  {
    // Jika ada kendaraan mendekat
    myservo.write(90); // Buka palang
    delay(3000);       // Tunggu kendaraannya lewat
  }
  else
  {
    myservo.write(0); // Tutup palang
  }

  delay(1000);
}
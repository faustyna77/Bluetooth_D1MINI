#include <Arduino.h>

#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

const char* ssid = "----";
const char* password = "------";
SoftwareSerial bluetooth(D7, D8); // RX, TX
int ledPin = D6;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    char receivedChar = bluetooth.read();
    int receiver=bluetooth.read();
    if (receivedChar == '2') {
      analogWrite(ledPin,receiver);
    }
    if(receivedChar=='3')
    {
      digitalWrite(ledPin,LOW);
    }
  }
}
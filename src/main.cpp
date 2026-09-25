#include <Arduino.h>
const int SENSOR_PIN = 6; // Пін підключення дільника з фоторезистором (GPIO In)
const int RELAY_PIN = 4;  // Пін керування транзистором реле (GPIO Out)


const int THRESHOLD_DARK = 2200; 
const int THRESHOLD_LIGHT = 2900;

int lightValue = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(RELAY_PIN, OUTPUT);
  
  digitalWrite(RELAY_PIN, LOW); 
  
  // встановлення роздільної здатності АЦП (12 біт = 0...4095)
  analogReadResolution(12);
}

void loop() {
  lightValue = analogRead(SENSOR_PIN);
  
  Serial.printf("Light Level - %d \n", lightValue);

  if (lightValue < THRESHOLD_DARK) {
    digitalWrite(RELAY_PIN, HIGH); 
  } else if(lightValue > THRESHOLD_LIGHT) {
    digitalWrite(RELAY_PIN, LOW);  
  }

  delay(100);
}
//PROJETO - FARM DE MORANGO - MONITORAMENTO DE TEMPERATURA E UMIDADE
#include "DHT.h"
#include <Wire.h> //Inclusão da biblioteca wire
#include <Adafruit_SSD1306.h> //Inclusão da biblioteca Adafruit_SSD1306.h
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Adafruit_ST7789.h>

//Sensor de Humidade e Temperatura
#define DHTPIN A1 // Entrada analógica A1
#define DHTTYPE DHT11 // Tipo de Sensor: DHT11
DHT dht(DHTPIN, DHTTYPE);

// Display SSD1306
Adafruit_SSD1306 displayLED; 

void setup() {
  Wire.begin(); 
  displayLED.begin(); 
  displayLED.clearDisplay(); 
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!µm 
  float umidade = dht.readHumidity(true);
  float graus_celsius = dht.readTemperature(false);
  Serial.print("Umidade: " + String(umidade, 1) + " C");
  Serial.print("Temp: " + String(graus_celsius, 1) + " C");

  displayLED.setTextColor(WHITE); 
  displayLED.setTextSize(1); 
  displayLED.setCursor(0, 0); 
  displayLED.print("# Morango Farm #");
  displayLED.println("");
  displayLED.println("Temp: " + String(graus_celsius, 1) + " C");
  displayLED.println("Umidade: " + String(umidade, 1)  + " %");
    if (isnan(umidade) || isnan(graus_celsius)) {
      displayLED.setTextColor(INVERSE);
      displayLED.println("Status: ERROR ");
    }else{
      displayLED.setTextColor(INVERSE);
      displayLED.println("Status: OFFLINE");
    }
  displayLED.display();
  displayLED.clearDisplay();
  delay(800);
}
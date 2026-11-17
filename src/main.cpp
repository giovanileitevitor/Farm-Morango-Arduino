// Example testing sketch for various DHT humidity/temperature sensors
// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
//#include <DHT.h>
#include "DHT.h"
#include <Wire.h> //Inclusão da biblioteca wire
#include <Adafruit_SSD1306.h> //Inclusão da biblioteca Adafruit_SSD1306.h
#include <Adafruit_GFX.h>
#include <SPI.h>
//#include <Adafruit_ST7789.h>
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 displayLED; //Criação do objeto displayLED, que será chamado para realizar as intruções da biblioteca Adafruit_SSD1306.h
bool inicio = true;

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
  digitalWrite(LED_BUILTIN, HIGH);
  //digitalWrite(LED_BUILTIN, LOW);
  //delay(800);  
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
  // displayLED.clearDisplay();
  delay(800);
}
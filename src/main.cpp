// Example testing sketch for various DHT humidity/temperature sensors
// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
//#include <DHT.h>
#include "DHT.h"
#include <Wire.h> //Inclusão da biblioteca wire
#include <Adafruit_SSD1306.h> //Inclusão da biblioteca Adafruit_SSD1306.h
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
  float umidade = dht.readHumidity();
  float graus_celsius = dht.readTemperature();
  //float graus_farenheit = dht.computeHeatIndex(graus_celsius);
  

  displayLED.setTextColor(WHITE); //Define a cor das letras, mas no nosso exemplo o display é Azul, então independente da cor que for colocada neste campo as letras ficarão azul. Por padrão deixe WHITE.
  displayLED.setTextSize(1); //Define o tamanho da letra
  displayLED.setCursor(0, 0); //Define o local(Horizontal e vertical), de onde irá aparecer a mensagem no display.
  displayLED.print("# Morango Farm #");
  displayLED.println("");
  displayLED.println("Temp: " + String(graus_celsius, 1) + " C");
  displayLED.println("Umidade: " + String(umidade, 1)  + " %");
  displayLED.println("Status: OFFLINE ");
  displayLED.display();
  digitalWrite(LED_BUILTIN, LOW);
  delay(800);  
  displayLED.clearDisplay();
}
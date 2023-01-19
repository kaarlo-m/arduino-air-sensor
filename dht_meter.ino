
#include "DHT.h"
#include <SoftwareSerial.h>
#include <String.h>
#define DHTPIN 8
#define RX 2
#define TX 3
#define DHTTYPE DHT22


SoftwareSerial hc05(RX, TX); // RX, TX
DHT dht(DHTPIN, DHTTYPE);
char c = ' ';

void setup() {
  Serial.begin(38400);
  dht.begin();
  hc05.begin(38400);
  Serial.println(F("DHTxx test!"));
  initHC05();

}

void delayAndRead()
{
  delay(50);
  while(hc05.available())
  {
    c = hc05.read();
  }
  delay(1500);
}

void initHC05()
{

    Serial.println("ENTER AT Commands:");
}

void loop() {
  
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  hc05.print(F("Humidity: "));
  hc05.print(h);
  hc05.print(F("%  Temperature: "));
  hc05.print(t);
  hc05.println(F("°C "));
}

#include <Adafruit_Sensor.h> 
#include <DHT.h>            

#define DHTPIN 23

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT11 Test on ESP32!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements (DHT11 should not be read more often than every 2 seconds)
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  // Check if any reads failed and exit early (to try again)
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  |  "));
 
  // Read temperature as Celsius
  Serial.print(F("Temperature: "));
  // Serial.print(t);
  // Serial.println(F(" °C"));

  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  Serial.print(F("Fahrenheit: "));
  Serial.println(f);
}
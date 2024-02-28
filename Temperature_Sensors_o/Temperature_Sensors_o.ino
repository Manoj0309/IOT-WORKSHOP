#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7     // Digital pin connected to the DHT sensor 
#define DHTTYPE DHT11 // DHT 11

DHT_Unified dht(DHTPIN, DHTTYPE);

const int buzzerPin = 6; // Define the pin for the piezo buzzer
float temperatureThreshold = 30.0; // Define the temperature threshold in Celsius

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  delay(2000); // Delay between sensor readings

  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (!isnan(event.temperature)) {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" °C");

    // Check if the temperature exceeds the threshold
    if (event.temperature > temperatureThreshold) {
      // If the temperature exceeds the threshold, sound the buzzer
      tone(buzzerPin, 1000); // Sound a tone with frequency 1000 Hz
      delay(1000); // Sound duration
      noTone(buzzerPin); // Stop the buzzer
    }
  } else {
    Serial.println("Error reading temperature!");
  }

  delay(1000); // Delay between measurements
}
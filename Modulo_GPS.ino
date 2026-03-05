#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Pinos para comunicação com o GPS
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// Instâncias
SoftwareSerial gpsSerial(RXPin, TXPin);
TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(GPSBaud);
  Serial.println("Iniciando GPS NEO-6M...");
}

void loop() {
  // Lê dados do GPS
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
    
    if (gps.location.isUpdated()) {
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng(), 6);
      Serial.print("Satélites: ");
      Serial.println(gps.satellites.value());
      Serial.print("Altitude: ");
      Serial.println(gps.altitude.meters());
      Serial.println("----------------------");
    }
  }
}

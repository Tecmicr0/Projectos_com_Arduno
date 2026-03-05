int sensorPin = A0;   // pino conectado ao OUT do sensor
int Sensor = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  valorSensor = analogRead(sensorPin); // lê valor entre 0 e 1023
  Serial.println(Sensor);         // envia para o PC
  delay(1000);                         // espera 1 segundo

}

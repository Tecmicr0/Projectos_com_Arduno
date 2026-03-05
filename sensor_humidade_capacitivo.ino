int sensorPin = A0;   // pino conectado ao OUT do sensor
int valorSensor = 0;

void setup() {
  Serial.begin(9600); // inicia comunicação serial
}

void loop() {
  valorSensor = analogRead(sensorPin); // lê valor entre 0 e 1023
  Serial.println(valorSensor);         // envia para o PC
  delay(1000);                         // espera 1 segundo
}
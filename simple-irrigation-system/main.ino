const int RELE_PIN = 2;
const int SENSOR_PIN = A5;
int humidityLvl = 0;

void setup() {
  Serial.begin(115200);
  pinMode(RELE_PIN, OUTPUT);
}

void loop() {
  humidityLvl = analogRead(SENSOR_PIN);

  Serial.print("Humidity: ");
  Serial.println(humidityLvl);

  if (humidityLvl > 425) {
    Serial.println("Watering...");
    digitalWrite(RELE_PIN, LOW);
  } else {
    Serial.println("Stopped watering");
    digitalWrite(RELE_PIN, HIGH);
  }

  delay(1000);
}

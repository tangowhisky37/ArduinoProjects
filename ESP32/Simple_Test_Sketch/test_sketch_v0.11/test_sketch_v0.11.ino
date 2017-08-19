
void setup() {
  Serial.begin(115200);
  delay(200);
}
void loop() {
  Serial.write("Hello, this is just our first test program on the ESP32!!!!\n");
  delay(1000);
}

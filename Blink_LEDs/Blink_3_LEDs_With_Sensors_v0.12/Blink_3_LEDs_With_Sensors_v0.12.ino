
int out_pin1 = A0;
int out_pin2 = A1;
int out_pin3 = A2;
String LDRSensor;
String SoilMoistureSensor;
String AlcoholSensor;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);       // Initializing the comms 
  Serial.println("!!! Reading from the Sensors and Displaying values !!!");
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second

// Code for reading the Keyes LDR starts here
  LDRSensor = "LDR Sensor Reading - ";
  Serial.print(LDRSensor);
  Serial.print(analogRead(out_pin1));
  Serial.println(" ");
  Serial.println(" ");
  delay(2000);              // wait for a second
  SoilMoistureSensor = "Soil Moisture sensor reading - ";
  Serial.print(SoilMoistureSensor);
  Serial.print(analogRead(out_pin2));
  Serial.println(" ");
  Serial.println(" ");
   delay(2000);              // wait for a second
  AlcoholSensor = "Alcohol sensor reading - ";
  Serial.print(AlcoholSensor);
  Serial.print(analogRead(out_pin3));
  Serial.println(" ");
  Serial.println(" ");
  delay(5000);
}

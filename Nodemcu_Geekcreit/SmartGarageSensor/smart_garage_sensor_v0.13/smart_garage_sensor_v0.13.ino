
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <ThingSpeak.h>
#include <Ethernet.h>
#define VOLTAGE_MAX 1.0
#define VOLTAGE_MAXCOUNTS 1023.0
#define D2 4
#define D0 16

const int trigPin = 12;
const int echoPin = 13;

//Enter your Wifi details here - 
const char *ssid = "PracticalPerformanceAnalyst";
const char *password = "xxx";

ESP8266WebServer server ( 80 );
const int led = 13;
int status = WL_IDLE_STATUS;
WiFiClient  client;

//WiFiServer server(80);

//ThingSpeak Settings
unsigned long myChannelNumber = 175500;
const char * myWriteAPIKey = "xxx";
String API = "xxx";

void setup ( void ) {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(57600);

  //Find my MAC address
  //String MyMacAddress = WiFi.macAddress();
  //Serial.print(MyMacAddress); 
  WiFi.begin(ssid, password);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  Serial.println("Initiating Wifi connection..." );
  Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  Serial.println(" ");
  
  // Wait for connection
  while ( WiFi.status() != WL_CONNECTED ) {
    delay (1000);
    Serial.print( ".." );
  }
  Serial.println(" ");
  Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  Serial.println("Connected to : ");
  Serial.println(ssid);
  Serial.println(" ");
  Serial.println("IP address : ");
  Serial.print(WiFi.localIP());
  Serial.println(" ");
  Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  Serial.println(" ");
  
  if ( MDNS.begin ( "esp8266" ) ) {
    Serial.println ( "MDNS responder started" );
  }
  ThingSpeak.begin(client);
}


void loop() {
  //Blinking LED First time
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level 
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(500);                      // Wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(500);  

 //Blinking LED Second time
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level 
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(500);                      // Wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(500);  

 //Blinking LED Third time
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level 
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(500);                      // Wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(500);  

  
  long duration, distance;
   // send the pulse
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(10); // low for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20); // high for 10 microseconds
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // measure the time to the echo
  distance = (duration/2) / 29.1;  // calculate the distance in cm
  if (distance >= 200 || distance <= 1){
    Serial.println("Out of range; reading invalid");
  }
  else {
    Serial.print("The distance measured outside the loop is - ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(6000); 

  //Performing the check five times before sending out the notification
  if (distance >= 20) {
   int count = 0;
   while (count <= 5){
    count ++;
    long duration1, distance1;
    // send the pulse
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(10); // low for 2 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(20); // high for 10 microseconds
    digitalWrite(trigPin, LOW);
    duration1 = pulseIn(echoPin, HIGH); // measure the time to the echo
    distance1 = (duration1/2) / 29.1;  // calculate the distance in cm
     if (distance1 >= 20){
      Serial.println("Keep counting, the door is really open.");
      //Tweet code
      Serial.println(count);
      delay(3000); 
      } else {
      Serial.println("The door seems to have closed again.");
      break;
      }
    }
  } 
  

} //End of the program


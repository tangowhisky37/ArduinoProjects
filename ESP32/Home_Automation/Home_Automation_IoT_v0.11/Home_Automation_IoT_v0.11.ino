
// To do - Include email notification, twitter notification, include humidity/temp sensor

//#include <WiFiClient.h>
//#include <WiFiServer.h>
//#include <ThingSpeak.h>
//#include <SPI.h>
//#include <Ethernet.h>
#include <WiFi.h>
#include <stdio.h>
#include "Gsender.h"
#define VOLTAGE_MAX 1.0
#define VOLTAGE_MAXCOUNTS 1023.0
#define D2 4
#define D0 16

const int trigPin = 12;
const int echoPin = 13;

//Enter your Wifi details here - 
const char *ssid = "PracticalPerformanceAnalyst";
const char *password = "xxxxxxxx";

const int led = 13;
int status = WL_IDLE_STATUS;
WiFiClient  client;

//ThingSpeak Settings
unsigned long myChannelNumber = 175500;
const char * myWriteAPIKey = "xxxxxxx";
String API = "xxxxxx";

void setup ( void ) {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(115200);

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
  
  //if ( MDNS.begin ( "esp8266" ) ) {
  //  Serial.println ( "MDNS responder started" );
  //}
  //ThingSpeak.begin(client);
}


void loop() {
  //Blinking LED First time
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level 
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(500);                       // Wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(500);  

  //Blinking LED Second time
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level 
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(500);                       // Wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(500);  

  //Blinking LED Third time
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level 
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(500);                       // Wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(500);  
      
  //Tweet and mail code block   
  int count = 0;
  if (count >= 20){
   Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
   String subject = "!!! Alert - Garage Door Open - Alert !!!";
   if(gsender->Subject(subject)->Send("trevor@practicalperformanceanalyst.com", "!!! Alert - Garage Door Open - Alert !!!")) {
    Serial.println("Message send.");
   } else {
    Serial.print("Error sending message: ");
    Serial.println(gsender->getError());
   }
  }

  // Connecting to Thingspeak to send out a tweet with current status
  // if connection to thingspeak.com is successful, send your tweet!!!
  //if (client.connect("api.thingspeak.com", 80))
  //{
  //client.print("GET /apps/thingtweet/1/statuses/update?key=" + API + "&status=!!! Alert - Garage Door Open - Alert !!! " + "HTTP/1.1\r\n");
  //client.print("Host: api.thingspeak.com\r\n"); 
  //client.print("Accept: */*\r\n"); 
  //client.print("User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n");
  //client.print("\r\n");  
  //}
  //Tweet and mail code block
      
  delay(10000); //Keep in mind that Thingspeak only accepts updates every 15secs 

} //End of the program


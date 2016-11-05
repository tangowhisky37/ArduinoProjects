
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <ThingSpeak.h>
#include <Ethernet.h>
#define VOLTAGE_MAX 1.0
#define VOLTAGE_MAXCOUNTS 1023.0

const char *ssid = "PracticalPerformanceAnalyst";
const char *password = "xxxxxx";
ESP8266WebServer server ( 80 );
const int led = 13;
int status = WL_IDLE_STATUS;
WiFiClient  client;

//WiFiServer server(80);

//ThingSpeak Settings
unsigned long myChannelNumber = 175500;
const char * myWriteAPIKey = "xxxxxxx";

void setup ( void ) {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  Serial.println("Initiating Wifi connection..." );
  Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  
  // Wait for connection
  while ( WiFi.status() != WL_CONNECTED ) {
    delay (500);
    Serial.print( ".." );
  }

  Serial.println("!!!!!!!!!!");
  Serial.println("Connected to ");
  Serial.print(ssid);
  Serial.println("IP address: ");
  Serial.print(WiFi.localIP());

  //printWifiStatus();

  //if ( MDNS.begin ( "esp8266" ) ) {
  //  Serial.println ( "MDNS responder started" );
  //}

  ThingSpeak.begin(client);
}

void loop ( void ) {
 
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level 
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(1000);                      // Wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);  

 // read the input on analog pin 0:
  int sensorValueA0 = analogRead(A0);
  // Convert the analog reading 
  // On Uno,Mega,YunArduino:  0 - 1023 maps to 0 - 5 volts
  // On ESP8266:  0 - 1023 maps to 0 - 1 volts
  // On MKR1000,Due: 0 - 4095 maps to 0 - 3.3 volts
  //float voltage = sensorValue * (VOLTAGE_MAX / VOLTAGE_MAXCOUNTS);

  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to field 1.
  //ThingSpeak.writeField(myChannelNumber, 1, voltage, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 1, sensorValueA0, myWriteAPIKey);
  delay(60000); // ThingSpeak will only accept updates every 15 seconds.

}


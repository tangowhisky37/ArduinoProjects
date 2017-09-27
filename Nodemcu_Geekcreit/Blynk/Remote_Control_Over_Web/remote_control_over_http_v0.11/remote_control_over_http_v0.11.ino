/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <Ethernet.h>
#define VOLTAGE_MAX 1.0
#define VOLTAGE_MAXCOUNTS 1023.0
#define D2 4
#define D0 16
#include <SimpleDHT.h>

MDNSResponder mdns;

// Replace with your network details
const char *ssid = "PracticalPerformanceAnalyst";
const char *password = "xxxxx";

// Web Server on port 80
ESP8266WebServer server(80);
const int led = 13;
int status = WL_IDLE_STATUS;
WiFiClient  client;

//Declaring variable to store webpage
String webPage = "";

//Declaring pins for use
int gpio0_pin = 5;
int gpio2_pin = 4;

// only runs once on boot
void setup() {

  // Initialize the LED_BUILTIN pin as an output
  pinMode(LED_BUILTIN, OUTPUT);     
  pinMode(led, OUTPUT);
  pinMode(D2, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(57600);

  //Find my MAC address
  String MyMacAddress = WiFi.macAddress();
  Serial.println(" ");
  Serial.println("My MAC Address is -  ");
  Serial.print(MyMacAddress); 
  Serial.println(" ");

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
  Serial.println("I am currently connected to wireless network :   ");
  Serial.println(ssid);
  Serial.println(" ");
  Serial.println("My current IP address is : ");
  Serial.print(WiFi.localIP());
  Serial.println(" ");
  Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  Serial.println(" ");
  
  if ( MDNS.begin ( "esp8266" ) ) {
    Serial.println ( "MDNS responder started" );
  }

  webPage += "<h1>ESP8266 Web Server + Remote Control</h1><p>Socket #1 <a href=\"socket1On\"><button>ON</button></a>&nbsp;<a href=\"socket1Off\"><button>OFF</button></a></p>";
  webPage += "<p>Socket #2 <a href=\"socket2On\"><button>ON</button></a>&nbsp;<a href=\"socket2Off\"><button>OFF</button></a></p>";

  // preparing GPIOs
  pinMode(gpio0_pin, OUTPUT);
  digitalWrite(gpio0_pin, LOW);
  pinMode(gpio2_pin, OUTPUT);
  digitalWrite(gpio2_pin, LOW);

 //Code for remote control over web sockets
 server.on("/", [](){
    server.send(200, "text/html", webPage);
  });
 server.on("/socket1On", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(gpio0_pin, HIGH);
    delay(1000);
  });
  server.on("/socket1Off", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(gpio0_pin, LOW);
    delay(1000); 
  });
  server.on("/socket2On", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(gpio2_pin, HIGH);
    delay(1000);
  });
  server.on("/socket2Off", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(gpio2_pin, LOW);
    delay(1000); 
  });
  server.begin();
  Serial.println("HTTP server started");
  
}

// runs over and over again
void loop() {
    server.handleClient();
}  

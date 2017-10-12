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
#include <RCSwitch.h>
//#include <Ethernet.h>
#define VOLTAGE_MAX 1.0
#define VOLTAGE_MAXCOUNTS 1023.0

MDNSResponder mdns;
RCSwitch mySwitch = RCSwitch();

// Replace with your network details
const char *ssid = "PracticalPerformanceAnalyst";
const char *password = "xxxx";

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
int d3 = 0;

  // custom function to update webpage on the fly
  void docRoot(){

    int tempnow = 26;
    int humnow = 88;

    webPage = "";
    webPage += "<h1>tangowhisky37 - ESP8266 Web Server & Remote Control</h1><br><br>";
    webPage += "<ul><li>Socket #1 <a href=\"socket1On\"><button>ON</button></a>&nbsp;<a href=\"socket1Off\"><button>OFF</button></a></li>";
    webPage += "<li>Socket #2 <a href=\"socket2On\"><button>ON</button></a>&nbsp;<a href=\"socket2Off\"><button>OFF</button></a></li></ul>";
    webPage += "<br>";
    webPage += "<ul><li> Room temperature ( Degrees Celcius ) is  ";
    webPage += (" %i ", tempnow);
    webPage += "  </li>";
    webPage += "<li> Room Humidity ( % ) is  ";
    webPage += (" %i ", humnow);
    webPage += "</li></ul>";
    webPage += "<br>";
    webPage += "<ul><li><a href=\"http://192.168.1.25\">Click Here To Return Home</a></li></ul>";
    server.send(200, "text/html", webPage);
    Serial.print(webPage);
    
  } //Closing DocRoot Function

// only runs once on boot
void setup() {

  //Initialize Serial interface
  Serial.begin(57600);

  // Transmitter is connected to Arduino Pin #2  
  mySwitch.enableTransmit(0);

  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
    
  // Optional set protocol (default is 1, will work for most outlets)
  //mySwitch.setProtocol(1);
  
  // Optional set number of transmission repetitions.
  //mySwitch.setRepeatTransmit(15);

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

  //webPage += "<h1>ESP8266 Web Server + Remote Control</h1><p>Socket #1 <a href=\"socket1On\"><button>ON</button></a>&nbsp;<a href=\"socket1Off\"><button>OFF</button></a></p>";
  //webPage += "<p>Socket #2 <a href=\"socket2On\"><button>ON</button></a>&nbsp;<a href=\"socket2Off\"><button>OFF</button></a></p>";

  // preparing GPIOs
  pinMode(gpio0_pin, OUTPUT);
  digitalWrite(gpio0_pin, LOW);
  pinMode(gpio2_pin, OUTPUT);
  digitalWrite(gpio2_pin, LOW);
  pinMode(d3, OUTPUT);
  digitalWrite(d3, LOW);

  //Code for remote control over web sockets
  //server.on("/", [](){
  //  server.send(200, "text/html", webPage);
  //});

  server.on("/", docRoot);
  
  server.on("/socket1On", [](){
    server.send(200, "text/html", webPage);
    // These Codes work with ARLEC RC 210
    Serial.println("Arlec RC210 - Switch A - On");
    mySwitch.send("00111111101110010000111110010001");  //observed
    delay(1000);
  });
  server.on("/socket1Off", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Arlec RC210 - Switch A - Off");
    mySwitch.send("00111111101110010000111010010000");  //observed
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

  // Handling incoming connections
  server.handleClient();  
    
}  

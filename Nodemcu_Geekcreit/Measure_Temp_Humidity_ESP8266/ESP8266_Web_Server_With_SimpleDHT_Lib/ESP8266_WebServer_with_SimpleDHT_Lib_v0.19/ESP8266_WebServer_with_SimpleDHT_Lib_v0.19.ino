
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <Ethernet.h>
#include <RCSwitch.h>
#define VOLTAGE_MAX 1.0
#define VOLTAGE_MAXCOUNTS 1023.0
#define D2 4
#define D0 16
#include <SimpleDHT.h>

int pinDHT11 = 16;
SimpleDHT11 dht11;
MDNSResponder mdns;
RCSwitch mySwitch = RCSwitch();

// Uncomment one of the lines below for whatever DHT sensor type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Replace with your network details
const char *ssid = "PracticalPerformanceAnalyst";
const char *password = "xxxxxxxxxxxxxxxxxxx";

// Web Server on port 80
ESP8266WebServer server(80);
const int led = 13;
int status = WL_IDLE_STATUS;
WiFiClient  client;

//Declaring variable to store webpage
String webPage = "";

//Declaring pins for use
int d3 = 0;

  // custom function to update webpage on the fly
  void docRoot(){

    //Declaring variables to store temp, humidity    
    byte temperature = 0;
    byte humidity = 0;  
    int err = SimpleDHTErrSuccess;  
            
    if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);

    //Read value provided by LDR sensor connected to AD0
    int sensorAD0 = analogRead(A0);
    //int farenheit = (temperature*(9/5))+32;
    int temperature = 0; //record 0 and display html rather than failing to put together the web page
    int farenheit = 0; //record 0 and display html rather than failing to put together the web page
    int humidity = 0; //record 0 and display html rather than failing to put together the web page

    
    //Enable to see debug messages
    Serial.print("Error reading DHT 11 !!! : ");
    Serial.print((int)temperature); Serial.print(" *C, "); 
    Serial.print((int)humidity); Serial.println(" H"); 
    Serial.print((int)sensorAD0); Serial.println(" Light Intensity"); 

    webPage = "";
    webPage += "<h3>ESP8266 Web Server & Remote Control</h3>";
    webPage += "<ul><li>Turn On Switch #A - LivingRoom/Porch <a href=\"socket1On\"><button>Switch ON</button></a>&nbsp;&nbsp;&nbsp;<a href=\"socket1Off\"><button>Switch OFF</button></a></li>";
    webPage += "<br>";
    webPage += "<li>Turn On Switch #B ----- Study/Shelflight <a href=\"socket2On\"><button>Switch ON</button></a>&nbsp;&nbsp;&nbsp;<a href=\"socket2Off\"><button>Switch OFF</button></a></li>";
    webPage += "<br>";
    webPage += "<li>Turn On Switch #C ------ Study/DeskLight <a href=\"socket3On\"><button>Switch ON</button></a>&nbsp;&nbsp;&nbsp;<a href=\"socket3Off\"><button>Switch OFF</button></a></li>";
    webPage += "<br>";
    webPage += "<li>Turn On Switch #D ------ LivingRoom/Hall <a href=\"socket4On\"><button>Switch ON</button></a>&nbsp;&nbsp;&nbsp;<a href=\"socket4Off\"><button>Switch OFF</button></a></li>";
    webPage += "<br>";
    webPage += "<li> Room temperature ( Degrees Celcius ) is  ";
    webPage += (" %i ", temperature);
    webPage += "  </li>";
    webPage += "<br>";
    webPage += "<li> Room temperature ( Farenheit ) is  ";
    webPage += (" %i ", farenheit);
    webPage += "  </li>";
    webPage += "<br>";
    webPage += "<li> Room Brightness ( 0 - 1024 ) is  ";
    webPage += (" %i ", sensorAD0);
    webPage += "  </li>";
    webPage += "<br>";
    webPage += "<li> Room Humidity ( % ) is  ";
    webPage += (" %i ", humidity);
    webPage += " </li>";
    webPage += "<br>";
    webPage += "<li>Click here to go Home - <a href=\\><button> Home Page</button></a></li></ul>";
    server.send(200, "text/html", webPage);
    Serial.print(webPage);
    return;
    
    } else {

    //Read value provided by LDR sensor connected to AD0
    int sensorAD0 = analogRead(A0);
    int farenheit = (temperature*(9/5))+32;
    //int temperature = 0; //record 0 and display html rather than failing to put together the web page
    //int farenheit = 0; //record 0 and display html rather than failing to put together the web page
    //int humidity = 0; //record 0 and display html rather than failing to put together the web page

    //Enable to see debug messages
    Serial.print("All good. Read data from DHT11 !!! ");
    Serial.print((int)temperature); Serial.print(" *C, "); 
    Serial.print((int)humidity); Serial.println(" H"); 
    Serial.print((int)sensorAD0); Serial.println(" Light Intensity"); 

    webPage = "";
    webPage += "<h1>ESP8266 Web Server & Remote Control</h1><br><br>";
    webPage += "<ul><li>Turn On Switch #A <a href=\"socket1On\"><button>Switch ON</button></a>&nbsp;&nbsp;&nbsp;<a href=\"socket1Off\"><button>Switch OFF</button></a></li>";
    webPage += "<br>";
    webPage += "<li>Turn On Switch #B <a href=\"socket2On\"><button>Switch ON</button></a>&nbsp;&nbsp;&nbsp;<a href=\"socket2Off\"><button>Switch OFF</button></a></li>";
    webPage += "<br>";
    webPage += "<li>Turn On Switch #C <a href=\"socket3On\"><button>Switch ON</button></a>&nbsp;&nbsp;&nbsp;<a href=\"socket3Off\"><button>Switch OFF</button></a></li>";
    webPage += "<br>";
    webPage += "<li>Turn On Switch #D <a href=\"socket4On\"><button>Switch ON</button></a>&nbsp;&nbsp;&nbsp;<a href=\"socket4Off\"><button>Switch OFF</button></a></li>";
    webPage += "<br>";
    webPage += "<li> Room temperature ( Degrees Celcius ) is  ";
    webPage += (" %i ", temperature);
    webPage += "  </li>";
    webPage += "<br>";
    webPage += "<li> Room temperature ( Farenheit ) is  ";
    webPage += (" %i ", farenheit);
    webPage += "  </li>";
    webPage += "<br>";
    webPage += "<li> Room Brightness ( 0 - 1024 ) is  ";
    webPage += (" %i ", sensorAD0);
    webPage += "  </li>";
    webPage += "<br>";
    webPage += "<li> Room Humidity ( % ) is  ";
    webPage += (" %i ", humidity);
    webPage += " </li>";
    webPage += "<br>";
    webPage += "<li>Click here to go Home - <a href=\\><button> Home Page</button></a></li></ul>";
    server.send(200, "text/html", webPage);
    Serial.print(webPage);
    return;
    
    } //Closing Else in If-Else 
  } //Closing DocRoot Function

// only runs once on boot
void setup() {
  // Initializing serial port for debugging purposes
  Serial.begin(115200);
  delay(1000);

   // Transmitter is connected to Arduino Pin #2  
  mySwitch.enableTransmit(0);

  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
    
  // Optional set protocol (default is 1, will work for most outlets)
  //mySwitch.setProtocol(1);
  
  // Optional set number of transmission repetitions.
  //mySwitch.setRepeatTransmit(15);
  
  //Find my MAC address and connect to Access Point
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

  // preparing GPIOs
  pinMode(d3, OUTPUT);
  digitalWrite(d3, LOW);

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
    // These Codes work with ARLEC RC 210
    Serial.println("Arlec RC210 - Switch B - On");
    mySwitch.send("00111111101110010000110110010010");  //observed
    delay(1000);
  });
  server.on("/socket2Off", [](){
    server.send(200, "text/html", webPage);
    // These Codes work with ARLEC RC 210
    Serial.println("Arlec RC210 - Switch B - Off");
    mySwitch.send("00111111101110010000110010010011");  //observed
    delay(1000); 
  });
  server.on("/socket3On", [](){
    server.send(200, "text/html", webPage);
    // These Codes work with ARLEC RC 210
    Serial.println("Arlec RC210 - Switch C - On");
    mySwitch.send("00111111101110010000101110010110");  //observed
    delay(1000);
  });
  server.on("/socket3Off", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Arlec RC210 - Switch C - Off");
    mySwitch.send("00111111101110010000101010010111");  //observed
    delay(1000); 
  });
  server.on("/socket4On", [](){
    server.send(200, "text/html", webPage);
    // These Codes work with ARLEC RC 210
    Serial.println("Arlec RC210 - Switch D - On");
    mySwitch.send("00111111101110010000011110011110");  //observed
    delay(1000);
  });
  server.on("/socket4Off", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Arlec RC210 - Switch D - Off");
    mySwitch.send("00111111101110010000011010011111");  //observed
    delay(1000); 
  });
  server.begin();
  Serial.println("HTTP server started");
  
  // Starting the web server
  server.begin();
  Serial.println("Web server running. Waiting for the ESP IP...");
  delay(10000);
}

// runs over and over again
void loop() {
  
  // Handling incoming connections
  server.handleClient();  

}  

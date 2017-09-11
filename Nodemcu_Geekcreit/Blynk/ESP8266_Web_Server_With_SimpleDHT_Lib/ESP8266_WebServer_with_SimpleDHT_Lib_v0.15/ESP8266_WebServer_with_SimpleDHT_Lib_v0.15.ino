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

int pinDHT11 = 14;
SimpleDHT11 dht11;

// Uncomment one of the lines below for whatever DHT sensor type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Replace with your network details
const char *ssid = "PracticalPerformanceAnalyst";
const char *password = "xxxxxx";

// Web Server on port 80
WiFiServer server(80);

// only runs once on boot
void setup() {
  // Initializing serial port for debugging purposes
  Serial.begin(57600);
  delay(1000);
  
  // Connecting to WiFi network
  Serial.println();
  Serial.print("Connecting to..........");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Starting the web server
  server.begin();
  Serial.println("Web server running. Waiting for the ESP IP...");
  delay(10000);
  
  // Printing the ESP IP address
  Serial.println(WiFi.localIP());
}

// runs over and over again
void loop() {
  // Listenning for new clients
  WiFiClient client = server.available();
  
  if (client) {
    Serial.println("New client");
    // bolean to locate when the http request ends
    boolean blank_line = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        
        if (c == '\n' && blank_line) {

            //Declaring variables to store temp, humidity    
            byte temperature = 0;
            byte humidity = 0;  
            int err = SimpleDHTErrSuccess;  
            
            if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
             Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
             return;
            } 

            //Read value provided by LDR sensor connected to AD0
            //int sensorAD0 = analogRead(A0);   //No LDR on the Blynk Board
            int farenheit = (temperature*(9/5))+32;

            //Enable to see debug messages
            Serial.print("Sample OK: ");
            Serial.print((int)temperature); Serial.print(" *C, "); 
            Serial.print((int)humidity); Serial.println(" H"); 
            //Serial.print((int)sensorAD0); Serial.println(" Light Intensity");  /No LDR on the Blynk Board

            //Forming content for the browser
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");
            client.println();
            // your actual web page that displays temperature and humidity
            client.println("<!DOCTYPE HTML>");
            client.println("<html>");
            client.println("<head></head><body><h1>ESP8266 @ WarrenStudy - Temperature and Humidity</h1>");
            client.println("<li><ul> Temperature in Celsius: ");
            client.print(temperature);
            client.print(" *Celsius </ul>");
            client.println("<ul> Temperature in Fahrenheit: ");
            client.print(farenheit);
            client.print(" *F </ul>");
            client.println("<ul> Humidity: ");
            client.print(humidity);
            client.print(" % </ul>");
            //client.println("<ul> Light Intensity");
            //client.print(sensorAD0);
            //client.print(" (0 - 1024)</ul></li>");
            client.print("</li>");
            client.println("</body></html>");     
            break;
        }
        if (c == '\n') {
          // when starts reading a new line
          blank_line = true;
        }
        else if (c != '\r') {
          // when finds a character on the current line
          blank_line = false;
        }
      }
    }  
    // closing the client connection
    delay(1);
    client.stop();
    Serial.println("Client disconnected.");
  }
}  

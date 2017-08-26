
//You will need to download the include file Gsender.h & Gsender.cpp from the following link and drop it 
//in the same directory containing your code - http://www.instructables.com/id/ESP8266-GMail-Sender/
//
//Once downloaded, place the header files in your local code directory. 
//Open up a browser and please visit base64encode.org to get the encoded values for your gmail email 
//address, gmail password both of which you will need to enter into the downloaded Gsender.h


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <ThingSpeak.h>
#include <Ethernet.h>
#include "Gsender.h"
#define VOLTAGE_MAX 1.0
#define VOLTAGE_MAXCOUNTS 1023.0
#define D2 4

#pragma region Globals
//const char* ssid = "";                           // WIFI network name
//const char* password = "";                       // WIFI network password
const char *ssid = "PracticalPerformanceAnalyst";
const char *password = "xxxxxxxxxxxx";
//const char *ssid = "CCHS-WiFI";
//const char *password = "xxxxxxxx";
uint8_t connection_state = 0;                    // Connected to WIFI or not
uint16_t reconnect_interval = 10000;             // If not connected wait time to try again
#pragma endregion Globals


ESP8266WebServer server ( 80 );
const int led = 13;
int status = WL_IDLE_STATUS;
WiFiClient  client;

//WiFiServer server(80);

//ThingSpeak Settings
unsigned long myChannelNumber = 175500;
const char * myWriteAPIKey = "xxxxx";
String API = "xxxxxxxxx";

uint8_t WiFiConnect(const char* nSSID = nullptr, const char* nPassword = nullptr)
{
    static uint16_t attempt = 0;
    Serial.print("Connecting to ");
    if(nSSID) {
        WiFi.begin(nSSID, nPassword);  
        Serial.println(nSSID);
    } else {
        WiFi.begin(ssid, password);
        Serial.println(ssid);
    }

    uint8_t i = 0;
    while(WiFi.status()!= WL_CONNECTED && i++ < 50)
    {
        delay(200);
        Serial.print(".");
    }
    ++attempt;
    Serial.println("");
    if(i == 51) {
        Serial.print("Connection: TIMEOUT on attempt: ");
        Serial.println(attempt);
        if(attempt % 2 == 0)
            Serial.println("Check if access point available or SSID and Password\r\n");
        return false;
    }
    Serial.println("Connection: ESTABLISHED");
    Serial.print("Got IP address: ");
    Serial.println(WiFi.localIP());
    return true;
}

void Awaits()
{
    uint32_t ts = millis();
    while(!connection_state)
    {
        delay(50);
        if(millis() > (ts + reconnect_interval) && !connection_state){
            connection_state = WiFiConnect();
            ts = millis();
        }
    }
}


void setup ( void ) {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(led, OUTPUT);
  pinMode(D2, OUTPUT);
  digitalWrite(led, 0);
  //Serial.begin(115200);
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

  //connection_state = WiFiConnect();
  //if(!connection_state)  // if not connected to WIFI
  //    Awaits();          // constantly trying to connect
 
}

void loop ( void ) {

 //Blinking LED First time
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level 
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(1000);                      // Wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);  

 //Blinking LED Second time
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level 
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(1000);                      // Wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);  

 //Blinking LED Third time
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level 
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(1000);                      // Wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);  

  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to field 1.
  //ThingSpeak.writeField(myChannelNumber, 1, voltage, myWriteAPIKey);
  
  digitalWrite(D2, LOW);
  delay(5000);
  
  // read the input on analog pin 0:
  int sensorValueA0 = analogRead(A0);
  // Convert the analog reading 
  // On Uno,Mega,YunArduino:  0 - 1023 maps to 0 - 5 volts
  // On ESP8266:  0 - 1023 maps to 0 - 1 volts
  // On MKR1000,Due: 0 - 4095 maps to 0 - 3.3 volts
  //float voltage = sensorValue * (VOLTAGE_MAX / VOLTAGE_MAXCOUNTS);
  
  Serial.println(sensorValueA0);
  String tweet = String(sensorValueA0);
  ThingSpeak.writeField(myChannelNumber, 3, sensorValueA0, myWriteAPIKey);

  if (sensorValueA0<100){
    Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
  String subject = "!!! Plant 4 Low On Water !!!";
  if(gsender->Subject(subject)->Send("trevor@practicalperformanceanalyst.com", "!!! Plant 4 (Living Room, LHS Television) Low On Water !!!")) {
     Serial.println("Message send.");
  } else {
     Serial.print("Error sending message: ");
     Serial.println(gsender->getError());
   }
  }

    if (sensorValueA0<100){
    Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
  String subject = "!!! Plant 4 Low On Water !!!";
  if(gsender->Subject(subject)->Send("viveka.f@gmail.com", "!!! Plant 4 (Living Room, LHS Television) Low On Water !!!")) {
     Serial.println("Message send.");
  } else {
     Serial.print("Error sending message: ");
     Serial.println(gsender->getError());
   }
  }

  // Connecting to Thingspeak to send out a tweet with current status
  // if connection to thingspeak.com is successful, send your tweet!!!
  if (client.connect("api.thingspeak.com", 80))
  {
  client.print("GET /apps/thingtweet/1/statuses/update?key=" + API + "&status=Current Soil Moisture Rdg for Plant 4 (Living Rm, LHS Telv) is " + tweet + " HTTP/1.1\r\n");
  client.print("Host: api.thingspeak.com\r\n"); 
  client.print("Accept: */*\r\n"); 
  client.print("User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n");
  client.print("\r\n");
  }
  digitalWrite(D2, HIGH);
  delay(900000); // ThingSpeak will only accept updates every 15 seconds.
}





#include <EtherCard.h>
#define STATIC 0  // set to 1 to disable DHCP (adjust myip/gwip values below)

#if STATIC
// ethernet interface ip address
static byte myip[] = { 10, 100, 10, 30 };
// gateway ip address
static byte gwip[] = { 10, 100, 10, 2 };
#endif

// ethernet mac address - must be unique on your network
static byte mymac[] = { 0x74, 0x69, 0x69, 0x2D, 0x30, 0x31 };
byte Ethernet::buffer[500]; // tcp/ip send and receive buffer
BufferFiller bfill;
const char page[] PROGMEM =
"HTTP/1.0 200 OK\r\n"
"Content-Type: text/html\r\n"
"Pragma: no-cache\r\n\r\n"
"<html>"
  "<head><title>"
    "Welcome to Arduino Mega 2560 @ PPA"
  "</title></head>"
  "<body>"
    "<h3>Sensor data collected by Arduino Mega 2560.</h3>"
    "<p><em>"
      "This page is work in progress.<br />"
      "Please try again later."
    "</em></p>"
  "</body>"
"</html>";

int out_pin0 = A0;  //Analog sensor connected to pin 0
int out_pin1 = A1;  //Analog sensor connected to pin 1
int out_pin2 = A2;  //Analog sensor connected to pin 2
String LDRSensor;
String SoilMoistureSensor;
String DHT22Temp;
String DHT22Humidity;

void setup(){
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
   
  Serial.begin(57600);
  //Commented out since this code seems to be blocking execution unless serial monitor is open
  //Serial.println("  ");
  //Serial.println("!!! Reading from the Sensors and Displaying values !!!");
  //Serial.println("  ");
  //Serial.println("\n[This page provides values of sensor data collected over HTTP]");
  //Serial.println("  ");
  
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) 
    Serial.println( "Failed to access Ethernet controller");
#if STATIC
  ether.staticSetup(myip, gwip);
#else
  if (!ether.dhcpSetup())
    Serial.println("DHCP failed");
#endif

  //Commented out since this code seems to be blocking execution unless serial monitor is open
  //Serial.println("  ");
  //Serial.println("!!! Here's my network configuration details !!!");
  //Serial.println("  ");
  //ether.printIp("IP:  ", ether.myip);
  //ether.printIp("GW:  ", ether.gwip);  
  //ether.printIp("DNS: ", ether.dnsip);  
}

static word homePage() {
  long t = millis() / 1000;
  word h = t / 3600;
  byte m = (t / 60) % 60;
  byte s = t % 60;
  int A0 = analogRead(out_pin0);
  int A1 = analogRead(out_pin1);
  bfill = ether.tcpOffset();
  bfill.emit_p(PSTR(
    "HTTP/1.0 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Pragma: no-cache\r\n"
    "\r\n"
    "<meta http-equiv='refresh' content='10'/>"
    "<title>Arduno Mega 2560 @ Practical Performance Analyst</title>"
    "\r\n"
    "<br>"
    "<p align=left><h3>Data for sensors hooked up to Arduino Mega 2560.</h3></p>" 
    "<br>"
    "<p>LDR Sensor Reading is $D</p>"
    "<br>"
    "<p>Soil Moisture Sensor Reading is $D</p>"
    "<br><br>"
    "<p align=left>You have been watching this page for $D$D:$D$D:$D$D</p>"),
      A0, A1, h/10, h%10, m/10, m%10, s/10, s%10);
 
  //Checking value of the Analog Sensor A1 - Soil Moisture and changing LED status
  if (m % 2){    // When m is odd, turn all LED's low
   if (A1>600) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    } else if (A1>400) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW); 
    } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);   
    }  
   } else {
   if (A1>600) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    } else if (A1>400) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW); 
    } else {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);   
     } 
    }
 return bfill.position();

}

void loop(){

  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);
  //int A0 = analogRead(out_pin0);
  //int A1 = analogRead(out_pin1);
  
  if (pos) {  // check if valid tcp data is received 
    ether.httpServerReply(homePage()); // send web page data
    } else {
    }

}


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

/*const char page[] PROGMEM =
"HTTP/1.0 200 Service Unavailable\r\n" 
"Content-Type: text/html\r\n"
"Retry-After: 600\r\n"
"\r\n"
"<html>"
  "<head><title>"
    "Service Temporarily Unavailable"
  "</title></head>"
  "<body>"
    "<h3>This service is currently unavailable</h3>"
    "<p><em>"
      "The main server is currently off-line.<br />"
      "Please try again later."
    "</em></p>"
  "</body>"
"</html>"; */

const char page[] PROGMEM =
"HTTP/1.0 200 OK\r\n"
"Content-Type: text/html\r\n"
"Pragma: no-cache\r\n\r\n"
"<html>"
  "<head><title>"
    "Welcome to Arduino Mega 2560 @ PPA"
  "</title></head>"
  "<body>"
    "<h3>Sensor data collected by Arduino Mega 2560 @ 37 Ronald Av.</h3>"
    "<p><em>"
      "This page is work in progress.<br />"
      "Please try again later."
    "</em></p>"
  "</body>"
"</html>";

int out_pin1 = A0;
int out_pin2 = A1;
int out_pin3 = A2;
String LDRSensor;
String SoilMoistureSensor;
String DHT22Temp;
String DHT22Humidity;

void setup(){
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
  Serial.println("  ");
  Serial.println("!!! Reading from the Sensors and Displaying values !!!");
  Serial.println("  ");
  Serial.begin(57600);
  Serial.println("\n[This page provides values of sensor data collected over HTTP]");
  Serial.println("  ");
  
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) 
    Serial.println( "Failed to access Ethernet controller");
#if STATIC
  ether.staticSetup(myip, gwip);
#else
  if (!ether.dhcpSetup())
    Serial.println("DHCP failed");
#endif

  ether.printIp("IP:  ", ether.myip);
  ether.printIp("GW:  ", ether.gwip);  
  ether.printIp("DNS: ", ether.dnsip);  
}

static word homePage() {
  long t = millis() / 1000;
  word h = t / 3600;
  byte m = (t / 60) % 60;
  byte s = t % 60;
  bfill = ether.tcpOffset();
  bfill.emit_p(PSTR(
    "HTTP/1.0 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Pragma: no-cache\r\n"
    "\r\n"
    "<meta http-equiv='refresh' content='1'/>"
    "<title>RBBB server</title>" 
    "<h1>$D$D:$D$D:$D$D</h1>"),
      h/10, h%10, m/10, m%10, s/10, s%10);
  return bfill.position();
}

void loop(){

  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);
  
  if (pos) {  // check if valid tcp data is received 
    ether.httpServerReply(homePage()); // send web page data
    } else {
  // Code for reading the Keyes LDR starts here
  LDRSensor = "LDR Sensor Reading - ";
  Serial.println(" ");
  Serial.println(" ");
  Serial.print(LDRSensor);
  Serial.print(analogRead(out_pin1));
  Serial.println(" ");
  Serial.println(" ");
  delay(1000);              // wait for a second
  SoilMoistureSensor = "Soil Moisture sensor reading - ";
  Serial.print(SoilMoistureSensor);
  Serial.print(analogRead(out_pin2));
  Serial.println(" ");
  Serial.println(" ");
  delay(1000);
   }
    
  // wait for an incoming TCP packet, but ignore its contents
  /*if (ether.packetLoop(ether.packetReceive())) {
    memcpy_P(ether.tcpOffset(), page, sizeof page);
    ether.httpServerReply(sizeof page - 1);
  } else {
  // Code for reading the Keyes LDR starts here
  LDRSensor = "LDR Sensor Reading - ";
  Serial.println(" ");
  Serial.println(" ");
  Serial.print(LDRSensor);
  Serial.print(analogRead(out_pin1));
  Serial.println(" ");
  Serial.println(" ");
  delay(1000);              // wait for a second
  SoilMoistureSensor = "Soil Moisture sensor reading - ";
  Serial.print(SoilMoistureSensor);
  Serial.print(analogRead(out_pin2));
  Serial.println(" ");
  Serial.println(" ");
  delay(1000);
  /*AlcoholSensor = "Alcohol sensor reading - ";
  Serial.print(AlcoholSensor);
  Serial.print(analogRead(out_pin3));
  Serial.println(" ");
  Serial.println(" ");
  delay(5000);*/

  //Turning LEDs on and off
  /*digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second 
  } */
 
}

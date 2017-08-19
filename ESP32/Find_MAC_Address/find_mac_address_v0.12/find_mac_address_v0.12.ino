/*
 * ESP-32 Example, 
 * start WiFi (without ssid and password)
 * and print the MAC address to Serial.
 */

#include <WiFi.h>

byte mac[6];

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Serial.println();
    Serial.println("Let's print out the MAC Address so you can whitelist this device for DHCP on your router...");

    WiFi.begin();
    Serial.println("******************");
    Serial.println("WiFi MAC Address below -");
    WiFi.macAddress(mac);
    
    Serial.print("MAC: ");
    Serial.print(mac[0],HEX);
    Serial.print(":");
    Serial.print(mac[1],HEX);
    Serial.print(":");
    Serial.print(mac[2],HEX);
    Serial.print(":");
    Serial.print(mac[3],HEX);
    Serial.print(":");
    Serial.print(mac[4],HEX);
    Serial.print(":");
    Serial.println(mac[5],HEX);
    Serial.println("******************");
    Serial.println(" ");
    Serial.println(" ");

    Serial.println("******************");
    Serial.println("The entire WiFi MAC - ");
    String MyMac = WiFi.macAddress();
    Serial.println(MyMac);
    Serial.println("******************");

}

void loop() {
  // put your main code here, to run repeatedly:

}

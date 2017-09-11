
/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * Note: This requires ESP8266 support package:
 *   https://github.com/esp8266/Arduino
 *
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include <ESP8266_Lib.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "774ee71d485d4257abedf9699591d54b"; 

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PracticalPerformanceAnalyst";
char pass[] = "xxxxxx";

void setup()
{
 
  Serial.begin(57600);

  //Find my MAC address
  //String MyMacAddress = WiFi.macAddress();
  //Serial.println(" ");
  //Serial.println("My MAC Address is -  ");
  //Serial.print(MyMacAddress); 
  //Serial.println(" ");
  
  Serial.println(" ");
  Blynk.begin(auth, ssid, pass);
  Serial.println(" ");
}

void loop()
{
  Blynk.run();
}


/*
  Example for different sending methods
  
  https://github.com/sui77/rc-switch/
  
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(2);

  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
  //mySwitch.setPulseLength(270);
  
  // Optional set protocol (default is 1, will work for most outlets)
  //mySwitch.setProtocol(1);
  
  // Optional set number of transmission repetitions.
  //mySwitch.setRepeatTransmit(15);
  //mySwitch.setRepeatTransmit();
  
}

void loop() {

  /* See Example: TypeA_WithDIPSwitches */
  //mySwitch.switchOn("11111", "00010");
  //delay(1000);
  //mySwitch.switchOff("11111", "00010");
  //delay(1000);

  /* Same switch as above, but using decimal code */
  //mySwitch.send(5393, 24);
  //delay(1000);  
  //mySwitch.send(5396, 24);
  //delay(1000);  

  /* Same switch as above, but using binary code */
  Serial.println("turn on");
  //mySwitch.send("01000011000010000000111101000011");
  mySwitch.send("00111111101110010000111110010001");  //observed
  delay(10000);
  
  Serial.println("turn off");
  mySwitch.send("00111111101110010000111010010000");  //observed
  delay(10000);  
  
  /* Same switch as above, but tri-state code */ 
  //mySwitch.sendTriState("00000FFF0F0F");
  //delay(1000);  
  //mySwitch.sendTriState("00000FFF0FF0");
  //delay(1000);

  delay(20000);
}


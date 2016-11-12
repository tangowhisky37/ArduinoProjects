# ArduinoProjects
A collection of all my Arduino Projects

Important Links - 
- https://iotbytes.wordpress.com/
- https://learn.sparkfun.com/tutorials/tags/internet-of-things?page=all
- https://blog.adafruit.com/category/iot/
- https://nurdspace.nl/ESP8266
- https://github.com/esp8266/Arduino
- https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/introduction
- http://randomnerdtutorials.com/getting-started-with-esp8266-wifi-transceiver-review/
- https://learn.adafruit.com/adafruit-huzzah-esp8266-breakout/overview
- http://iot-playground.com/component/tags/tag/11-esp8266
- https://www.hackster.io/search?q=ESP8266
- http://hackaday.com/2015/03/18/how-to-directly-program-an-inexpensive-esp8266-wifi-module/

Simple Blink LED's
- This program simply blinks LED's (Blink_LEDs/Blink3LEDs)
- Connections for this circuit include : 
  - Connect the Digital pins on the Arduino to the LED. 
  - On the MEGA 2560, D0 is Rx0 and D1 is Tx0. You will need to use D2 onwards.
  - A sample connection would include - D2 to Anode (Longer leg), 50 Ohm Resistor in line with Anode.
  - Cathode (Shorter leg) connects to the ground rail on the Breadboard.
  - You can use a Male to Male cable to connect the Arduino Ground, to the Ground rail on the Breadboard. 
  - Connect up as many LED's you want to connect. Use different colors. 
- Hardware required includes : 
  - Arduino MEGA 2560 R3 (You can choose your own version of the Arduino)
  - Coloured LED's 
  - Breadboard for building the circuit
  - Dupont Male to Male wires 
  - 50 Ohm Resistors 
- Software required includes : 
  - Arduino Development IDE
  - Links to read up on with regards to programming the Arduino from the Raspberry Pi
    - http://www.instructables.com/id/Program-arduino-from-raspberry-pi/
    - https://www.youtube.com/watch?v=mfIacE-SPvg
    - https://www.youtube.com/watch?v=eYu4vHDxA3I 

Blink LED's while reading data from Analog Sensors (Blink_LEDs/Blink3LEDsWithSensors)
- This program simply blinks LED's and displays data from Analog Sensors on the Serial Monitor
- Connections for this circuit include :
  - Connect the Digital pins on the Arduino to the LED.
  - On the MEGA 2560, D0 is Rx0 and D1 is Tx0. You will need to use D2 onwards.
  - A sample connection would include - D2 to Anode (Longer leg), 50 Ohm Resistor in line with Anode.
  - Cathode (Shorter leg) connects to the ground rail on the Breadboard.
  - You can use a Male to Male cable to connect the Arduino Ground, to the Ground rail on the Breadboard. 
  - Connect up as many LED's you want to connect. Use different colors. 
  - Connect up the Analog sensors you might have. In this case I've used the following sensors - 
  - Soil Moisture Sensor, Alcohol Sensor and LDR Sensor. Follow the connection diagrams for your sensors.
  - Please connect up the relevant Analog sensors to the available Analog ports and change code accordingly. 
- Hardware required includes : 
  - Arduino MEGA 2560 R3 (You can choose your own version of the Arduino)
  - Coloured LED's  
  - Breadboard for building the circuit
  - Dupont Male to Male wires  
  - 50 Ohm Resistors  
  - Analog Alcohol Sensor 
  - Analog LDR or Light Dependant Resistor Sensor (LDR) 
  - Analog Soil Moisture Sensor
- Software required includes : 
  - Arduino Development IDE
  - Links to read up on with regards to programming the Arduino from the Raspberry Pi
    - http://www.instructables.com/id/Program-arduino-from-raspberry-pi/
    - https://www.youtube.com/watch?v=mfIacE-SPvg
    - https://www.youtube.com/watch?v=eYu4vHDxA3I


Display Simple Web Page (ArduinoProjects/Ethernet/DummyWebPage)
- This program uses the Ethernet Addon based on Enc28j60 and displays a web page over ethernet
- I configured my Raspberry Pi as a DHCP server using ISC DHCP and provided the Arduino MEGA 2560 R3 a lease over ethernet. 
- Connections for this circuit include :
  - Connections between the Enc28j60 and Arduino MEGA 2560 R3 are as follows :
    - Enc2860 Ground connected to Ground on the Arduino MEGA 2560 R3
    - Enc2860 3.3 connected to 3.3v on the Arduino MEGA 2560 R3
    - Enc2860 SO connected to D50 (Pin 50) on the Arduino MEGA 2560 R3
    - Enc2860 SI connected to D51 (Pin 51) on the Arduino MEGA 2560 R3
    - Enc2860 SCK connected to D52 (Pin 52) on the Arduino MEGA 2560 R3
    - Enc2860 CS connected to D53 (Pin 53) on the Arduino MEGA 2560 R3
- Diagram -
  - See fritzing diagram here - https://github.com/tangowhisky37/ArduinoProjects/blob/master/Ethernet/Fritzing/Arduino_Mega_2650_with_Enc28j60_v0.21_bb.png
- Hardware required includes : 
  - Arduino MEGA 2560 R3 (You can choose your own version of the Arduino)
  - Addon board based on Enc28j60 (http://www.ebay.com/bhp/enc28j60-module)
  - Breadboard for building the circuit
  - Dupont Male to Male wires
  - Dupont Female to Male wires
- Software required includes :
  - Arduino Development IDE 
  - Ethernet Library to be downloaded from https://github.com/jcw/ethercard/
  - Links to read up on with regards to programming the Arduino from the Raspberry Pi
    - http://www.instructables.com/id/Program-arduino-from-raspberry-pi/
    - https://www.youtube.com/watch?v=mfIacE-SPvg
    - https://www.youtube.com/watch?v=eYu4vHDxA3I
- Articles to read :
  - https://www.youtube.com/watch?v=ahvCyhgXaqc
  - http://en.code-bude.net/2013/06/22/how-to-use-enc28j60-ethernet-shield-with-arduino-mega-2560/ 

Obtain DHCP lease with DNS and accept Web Requests (ArduinoProjects/Ethernet/EthernetDemoUsingDhcpDns/)
- This program uses the Ethernet Addon based on enc28j60 and obtains a DHCP lease over ethernet.
- I configured my Raspberry Pi as a DHCP server using ISC DHCP and provided the Arduino MEGA 2560 R3 a lease over ethernet. 
- Connections for this circuit include :
  - Connections between the Enc28j60 and Arduino MEGA 2560 R3 are as follows :
    - Enc2860 Ground connected to Ground on the Arduino MEGA 2560 R3
    - Enc2860 3.3 connected to 3.3v on the Arduino MEGA 2560 R3
    - Enc2860 SO connected to D50 (Pin 50) on the Arduino MEGA 2560 R3
    - Enc2860 SI connected to D51 (Pin 51) on the Arduino MEGA 2560 R3
    - Enc2860 SCK connected to D52 (Pin 52) on the Arduino MEGA 2560 R3
    - Enc2860 CS connected to D53 (Pin 53) on the Arduino MEGA 2560 R3
- Diagram -
  - See fritzing diagram here - https://github.com/tangowhisky37/ArduinoProjects/blob/master/Ethernet/Fritzing/Arduino_Mega_2650_with_Enc28j60_v0.21_bb.png
- Hardware required includes :
  - Arduino MEGA 2560 R3 (You can choose your own version of the Arduino)
  - Addon board based on Enc28j60 (http://www.ebay.com/bhp/enc28j60-module)
  - Breadboard for building the circuit
  - Dupont Male to Male wires
  - Dupont Female to Male wires
- Software required includes :
  - Arduino Development IDE 
  - Ethernet Library to be downloaded from https://github.com/jcw/ethercard/
  - Links to read up on with regards to programming the Arduino from the Raspberry Pi
    - http://www.instructables.com/id/Program-arduino-from-raspberry-pi/
    - https://www.youtube.com/watch?v=mfIacE-SPvg
    - https://www.youtube.com/watch?v=eYu4vHDxA3I
- Articles to read :
  - https://www.youtube.com/watch?v=ahvCyhgXaqc
  - http://en.code-bude.net/2013/06/22/how-to-use-enc28j60-ethernet-shield-with-arduino-mega-2560/ 


Obtain data from sensors and display on Web Page (ArduinoProjects/Ethernet/WebPageWithSensorData)
- This program uses the Ethernet Addon based on enc28j60, obtains data from on-board sensors and displays values over a web page
- I configured my Raspberry Pi as a DHCP server using ISC DHCP and provided the Arduino MEGA 2560 R3 a lease over ethernet. 
- Connections for this circuit include :
  - Connections between the Enc28j60 and Arduino MEGA 2560 R3 are as follows :
    - Enc2860 Ground connected to Ground on the Arduino MEGA 2560 R3
    - Enc2860 3.3v connected to 3.3v on the Arduino MEGA 2560 R3
    - Enc2860 SO connected to D50 (Pin 50) on the Arduino MEGA 2560 R3 
    - Enc2860 SI connected to D51 (Pin 51) on the Arduino MEGA 2560 R3
    - Enc2860 SCK connected to D52 (Pin 52) on the Arduino MEGA 2560 R3
    - Enc2860 CS connected to D53 (Pin 53) on the Arduino MEGA 2560 R3 
  - Connect the Digital pins on the Arduino to the LED.
  - On the MEGA 2560, D0 is Rx0 and D1 is Tx0. You will need to use D2 onwards.
  - A sample connection would include - D2 to Anode (Longer leg), 50 Ohm Resistor in line with Anode.
  - Cathode (Shorter leg) connects to the ground rail on the Breadboard.
  - You can use a Male to Male cable to connect the Arduino Ground, to the Ground rail on the Breadboard.
  - Connect up as many LED's you want to connect. Use different colors.
  - Connect up the Analog sensors you might have. In this case I've used the following sensors -
  - Soil Moisture Sensor, Alcohol Sensor and LDR Sensor. Follow the connection diagrams for your sensors.
  - Please connect up the relevant Analog sensors to the available Analog ports and change code accordingly.
- Diagram - 
  - See fritzing diagram here - https://github.com/tangowhisky37/ArduinoProjects/blob/master/Ethernet/Fritzing/Arduino_Mega_2650_with_Enc28j60_v0.21_bb.png 
- Hardware required includes :
  - Arduino MEGA 2560 R3 (You can choose your own version of the Arduino)
  - Addon board based on Enc28j60 (http://www.ebay.com/bhp/enc28j60-module)
  - Breadboard for building the circuit
  - 50 Ohm Resistors
  - Dupont Male to Male wires
  - Dupont Female to Male wires
  - Analog Alcohol Sensor
  - Analog LDR or Light Dependant Resistor Sensor (LDR)
  - Analog Soil Moisture Sensor
- Software required includes :
  - Arduino Development IDE 
  - Ethernet Library to be downloaded from https://github.com/jcw/ethercard/
  - Links to read up on with regards to programming the Arduino from the Raspberry Pi
    - http://www.instructables.com/id/Program-arduino-from-raspberry-pi/
    - https://www.youtube.com/watch?v=mfIacE-SPvg
    - https://www.youtube.com/watch?v=eYu4vHDxA3I
- Articles to read :
  - https://www.youtube.com/watch?v=ahvCyhgXaqc
  - http://en.code-bude.net/2013/06/22/how-to-use-enc28j60-ethernet-shield-with-arduino-mega-2560/


Blink lights on the NodeMCU ESP8266 board (Code at  Nodemcu_Geekcreit/BlinkLights/Blink_v0_11/)
- The NodeMCU board is one among the many ESP8266 boards out there but with a bit of a difference. 
- This board is affordable, connects to a USB port of your machine, is breadboard friendly and most importantly works with the Arduino IDE.
- This is the Hello world of embedded electronics. You usually use this when you get started with any new board.
- This simple tutorial includes connecting the NodeMCU board to your machine, setting up the Arduino IDE interface and flashing the board.
- The sketch involved causes the light on the NodeMCU board to blink.
- Connections for this circuit include - 
 - Connecting the NodeMCU board to the USB port of your development machine
- Software required includes - 
 - Arduino IDE
 - ESP8266 libraries packes into the Arduino IDE which include the packages for NodeMCU board
 - Here are some of the links you might want to refer to with regards to configuring the Arduino IDE for ESP8266 development : 
  - https://learn.adafruit.com/adafruit-huzzah-esp8266-breakout/using-arduino-ide
  - https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon
- Hardware required includes :
 - 1 x NodeMCU board
- Links for purchase :
 - http://www.banggood.com/Geekcreit-Doit-NodeMcu-Lua-ESP8266-ESP-12E-WIFI-Development-Board-p-985891.html
 - http://www.nodemcu.com


NodeMCU - Identify MAC Addres, Connect to a wireless network and blinks lights(Code at Nodemcu_Geekcreit/ObtainMACAddress/)
- The NodeMCU board is one among the many ESP8266 boards out there but with a bit of a difference.
- This board is affordable, connects to a USB port of your machine, is breadboard friendly and most importantly works with the Arduino IDE.
- When working with NodeMCU boards one of the initial challenges is configuring your wireless router to allow the NodeMCU board to speak to it.
- Most routers (including mine at home) use whitelisting or a MAC address list to allow a set of endpoints to connect to it. This is more for purposes of security than anything else. 
- If this is the case with you as well, you will need to know the MAC address of the NodeMCU board to be able to configure the Wireless AP (Access Point) to allow your NodeMCU board to connect to it.
- Usually this is something you would only do once when you get started with any new NodeMCU board. This simple tutorial includes connecting the NodeMCU board to your machine, setting up the Arduino IDE interface and flashing the board with the code provided.
- Once you've flashed the board, open up the Serial monitor window in your Arduino IDE. Hit the re-set button on the NodeMCU to get the board to reboot.
- With the board booting up you should now see the MAC address for your new NodeMCU board on the Arduino IDE serial monitor. 
- Now's the opportunity to add the MAC address for the new NodeMCU board onto the whitelist of your wireless router. Once you've done that go back to your NodeMCU.
- Reset the board using the re-set button on the NodeMCU with the Arduino Serial Monitor open. You should now see the NodeMCU obtaining a DHCP lease from your wireless router. 
- The sketch involved causes the light on the NodeMCU board to blink.
- Connections for this circuit include -
 - Connecting the NodeMCU board to the USB port of your development machine
 - Software required includes -
  - Arduino IDE
  - ESP8266 libraries packes into the Arduino IDE which include the packages for NodeMCU board
 - Here are some of the links you might want to refer to with regards to configuring the Arduino IDE for ESP8266 development :
   - https://learn.adafruit.com/adafruit-huzzah-esp8266-breakout/using-arduino-ide
   - https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon
- Hardware required includes :
 - 1 x NodeMCU board
 - Links for purchase :
  - http://www.banggood.com/Geekcreit-Doit-NodeMcu-Lua-ESP8266-ESP-12E-WIFI-Development-Board-p-985891.html
   - http://www.nodemcu.com


IoT (Internet Of Things) Web Server using the NodeMCU ESP8266 board (Code at Nodemcu_Geekcreit/Web_Server/)
- The NodeMCU board is one among the many ESP8266 boards out there but with a bit of a difference.
- This board is affordable, connects to a USB port of your machine, is breadboard friendly and most importantly works with the Arduino IDE.
- This program is a copy of the Web Server program that comes with the NodeMCU tutorials part of the examples in your Arduino IDE for NodeMCU.
- To get this program working you will need the credentials for a local wireless network so that you can connect to it.
- You can hook up all sorts of sensors (Digital or Analog) to your NodeMCU board and have it present values through the web page.
- Connections for this circuit include -
 - Connecting the NodeMCU board to the USB port of your development machine
 - Software required includes -
  - Arduino IDE
  - ESP8266 libraries packes into the Arduino IDE which include the packages for NodeMCU board
  - Here are some of the links you might want to refer to with regards to configuring the Arduino IDE for ESP8266 development :
    - https://learn.adafruit.com/adafruit-huzzah-esp8266-breakout/using-arduino-ide
    - https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon
- Hardware required includes :
 - 1 x NodeMCU board
- Links for purchase :
  - http://www.banggood.com/Geekcreit-Doit-NodeMcu-Lua-ESP8266-ESP-12E-WIFI-Development-Board-p-985891.html
  - http://www.nodemcu.com


IoT (Internet Of Things) Soil Moisture Sensor that Tweets using NodeMCU with ESP8266 (Code at Nodemcu_Geekcreit/ThingSpeakDataUpload)
- The NodeMCU board is one among the many ESP8266 boards out there but with a bit of a difference.
- This board is affordable, connects to a USB port of your machine, is breadboard friendly and most importantly works with the Arduino IDE.
- As part of this program you will connect to the local wireless network, read values from the Soil moisture sensor and tweet the values.
- The code also uses the Thingspeak Arduino library to upload data points to ThingSpeak and view graphically the data being logged. 
- To get this program working you will need the credentials for a local wireless network so that you can connect to it.
- You will need to setup an account at www.thingspeak.com, create a channel and setup it up so that you can write to the channel using your NodeMCU.
- You will also need to setup a Twitter account at www.twitter.com and configure the thingtweet application.
- The thingtweeet application (https://thingspeak.com/apps/thingtweets) requires that you register your Twitter account with Thingspeak.
- Over the coming weeks (or months..as and when i can find time) I will update the code such that it only tweets when certain conditions are met.
- Currently the code tweets every 5 minutes
- Connections for this circuit include -
 - Connecting the NodeMCU board to the USB port of your development machine
  - Software required includes -
   - Arduino IDE
   - ESP8266 libraries packes into the Arduino IDE which include the packages for NodeMCU board
   - Thingspeak IoT libraries which can be installed using the Arduino IDE
   - Here are some of the links you might want to refer to with regards to configuring the Arduino IDE for ESP8266 development :
    - https://learn.adafruit.com/adafruit-huzzah-esp8266-breakout/using-arduino-ide
    - https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon
    - Read up on NodeMCU at http://www.nodemcu.com
    - Twitter account
    - Thingspeak account
    - Configuration of Thingtweet application so that it is integrated with your Twitter account and can publish to it
- Diagram - 
 - View the Fritzing diagram here : https://github.com/tangowhisky37/ArduinoProjects/blob/master/Nodemcu_Geekcreit/ThingSpeakDataUpload/Fritzing/SoilMoistoreSensor_v0.2_bb.png
 - v0.1 of the Fritzing uses a Wemos Pro instead of a NodeMCU since i couldn't find the right template to use. Please refer to v0.2 
- Hardware required includes :
 - 1 x NodeMCU board
- Links for purchase :
 - NodeMCU - http://www.banggood.com/Geekcreit-Doit-NodeMcu-Lua-ESP8266-ESP-12E-WIFI-Development-Board-p-985891.html
 - Soil Moisture Sensor : https://www.sparkfun.com/products/13322
 - NPN 2N2222A : https://www.adafruit.com/product/756
 - 1 x 100 Ohm Resistor
 - 1 x 1K Ohm Resistor
 - Dupont Male to Male breadboard wires
 - Dupont Femal to Male breadboard wires


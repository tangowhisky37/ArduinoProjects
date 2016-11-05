# ArduinoProjects
A collection of all my Arduino Projects

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
    - Enc2860 3.3 connected to 3.3v on the Arduino MEGA 2560 R3
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



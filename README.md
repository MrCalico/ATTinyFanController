# ATTinyFanController
Using an ATTiny Arduino &amp; ESP8266 Wifi module,  IFTTT,  Webhooks, Blynk Cloud and Google Assistant together over the Internet I can change the power, speed and fan directions.

Prototype breadboard using two System-On-Chip processors which communicate together via a binary code.  The first SOC is an ESP8266 Wifi enabled which communicates to the Blynk-Cloud server to allow commands to be sent to it via HTTP (Browser Calls).  The second is an ATTiny85 Arduino which has the Infrared library installed that can send out the IR commands.

ATTinyFanContoller:  The Arduino board code.

ESP8266_Standalone_Blynk:  ESP8266 Code.

Hardware:
http://www.DigiStump.com
https://en.wikipedia.org/wiki/ESP8266

Software & Services:
http://www.IFTTT.com
http://www.Blynk.cc
http://www.Arduino.cc

Software Libraries:
https://github.com/cyborg5/IRLib2
https://github.com/blynkkk/blynk-library/releases/latest

My Code:
https://github.com/mrcalico/ATTinyFanController

The fan in this project did not comform to a standard IR model.  The real tricky part of this build is capturing the IR codes for the fan.  I had to use my dual channel Oscilliscope to match the remote and the output correctly.  I believe there are premium software tools that can help but refused to purchase anything except the few dollars spent on the hardware. 

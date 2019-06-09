/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "1963X32977a347e3b934e85b7X8Xe38X";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ApexMicro";
char pass[] = "wifiPasswordHere";

void pulsePins(byte value) {
  switch (value) {
    case 0:
      digitalWrite(0,LOW);
      digitalWrite(2,LOW);
      break;
    case 1:
      digitalWrite(2,HIGH);
      digitalWrite(0,LOW);
      break;
    case 2:
      digitalWrite(2,LOW);
      digitalWrite(0,HIGH);
    case 3:
      digitalWrite(2,HIGH);
      digitalWrite(0,HIGH);
      break;
  }
  delay(33);
  digitalWrite(0,LOW);
  digitalWrite(2,LOW);
}

// This function will be called every time a Widget
// in Blynk app writes values to the Virtual Pin V1

BLYNK_WRITE(V1)
{
  
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  pulsePins(pinValue);

}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(2,OUTPUT);
  pinMode(0,OUTPUT);
}

void loop()
{
  Blynk.run();
}

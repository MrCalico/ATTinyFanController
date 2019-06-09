//#include <IRLibSendBase.h>    //We need the base code
//#include <IRLib_HashRaw.h>    //Only use raw sender

#include <IRremote.h>
IRsend irsend;

#define BUILT_IN_LED 0
#define BUTTON_FAN_FLOW_PIN 2
#define BUTTON_FAN_POWER_PIN 0

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  
  // pinMode(BUILT_IN_LED, OUTPUT); //LED on Model B
     pinMode(BUTTON_FAN_POWER_PIN, INPUT); 
     pinMode(BUTTON_FAN_FLOW_PIN, INPUT);  //Button Pin
}

#define RAW_DATA_LEN 24
uint16_t rawData[RAW_DATA_LEN]={
  1262, 438, 1242, 434, 402, 1270, 1246, 434, 
  1238, 438, 402, 1270, 402, 1274, 402, 1274, 
  1238, 438, 398, 1274, 406, 1270, 402, 1000};

uint16_t Pwr_rawData[RAW_DATA_LEN]={
  1206, 470, 1206, 474, 366, 1310, 1210, 466, 
  1210, 466, 1238, 442, 366, 1306, 366, 1310, 
  374, 1302, 1206, 470, 1210, 470, 366, 1000};


// the loop routine runs over and over again forever:

int buttonState = 0;
int lastButtonState = 0;

int pwrBtnState = 0;
int lastPwrBtnState = 0;

void loop() {
  
  buttonState = digitalRead(BUTTON_FAN_FLOW_PIN);
  pwrBtnState = digitalRead(BUTTON_FAN_POWER_PIN);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (pwrBtnState == HIGH && lastPwrBtnState == LOW) {
    // Change Fan Speed
    for (int i = 0; i < 4; i++) {
      irsend.sendRaw(Pwr_rawData,RAW_DATA_LEN,36);
      delay(8);
    }
  }
  lastPwrBtnState = buttonState;
    
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Change Fan Flow
    for (int i = 0; i < 4; i++) {
      irsend.sendRaw(rawData,RAW_DATA_LEN,36);
      delay(8);
    }
  }
  lastButtonState = buttonState;
 


}

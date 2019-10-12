#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include "Chaplex.h"
#include "MorseCode.h"


//setup chaplex
byte controlPins[] = {13, 10, 12}; 
#define numControlPins sizeof(controlPins) / sizeof(*controlPins)
Chaplex myCharlie(controlPins, numControlPins); //control instance

charlieLed leds[6] = {
  { 1 , 2 },    // 3 {anode-pin,cathode-pin}
  { 2 , 1 },    // 1 controlled leds in sorted order (when looking at front, from left -> to -> right)
  { 2 , 0 },    // 4 "pin" means here - index in controlPins
  { 0 , 2 },    // 2 every element is one led with
  { 1 , 0 },     // 6
  { 0 , 1 }   // 5 array defined above
};

os_timer_t myTimer;
MorseCode morseCode(myCharlie, leds[0]);
  
void setup() {
  Serial.begin(9600);
  os_timer_setfn(&myTimer, timerCallback, NULL);
  os_timer_arm(&myTimer, 5, true);
}

void loop() {
  morseCode.write("bsideschs2019");
 
}

void timerCallback(void *pArg) {
  myCharlie.outRow();
}

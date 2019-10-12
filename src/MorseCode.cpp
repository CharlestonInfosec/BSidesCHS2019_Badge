/*
 * Author: Cory Nance
 * Version: 0.1
 */

#include "MorseCode.h"

MorseCode::MorseCode(Chaplex& cp, charlieLed cp_led){
  charliePlex = cp;
  led = cp_led;
  dotDelay = 200;
}

void MorseCode::write(char* c){
  int i = 0;
  while (c[i] != NULL){
    write(c[i]);
    i++;
  }
  delay(1000);
}

void MorseCode::write(char c){
  switch(c){
    case 'a':
      dot();
      dash();
      break;
    case 'b':
      dash();
      dot();
      dot();
      dot();
      break;
    case 'c':
      dash();
      dot();
      dash();
      dot();
      break;
    case 'd':
      dash();
      dot();
      dot();
      break;
    case 'e':
      dot();
      break;
    case 'f':
      dot();
      dot();
      dash();
      dot();
      break;
    case 'g':
      dash();
      dash();
      dot();
      break;
    case 'h':
      dot();
      dot();
      dot();
      dot();
      break;
    case 'i':
      dot();
      dot();
      break;
    case 'j':
      dot();
      dash();
      dash();
      dash();
      break;
    case 'k':
      dash();
      dot();
      dash();
      break;
    case 'l':
      dot();
      dash();
      dot();
      dot();
      break;
    case 'm':
      dash();
      dash();
      break;
    case 'n':
      dash();
      dot();
      break;
    case 'o':
      dash();
      dash();
      dash();
      break;
    case 'p':
      dot();
      dash();
      dash();
      dot();
      break;
    case 'q':
      dash();
      dash();
      dot();
      dash();
      break;
    case 'r':
      dot();
      dash();
      dot();
      break;
    case 's':
      dot();
      dot();
      dot();
      break;
    case 't':
      dash();
      break;
    case 'u':
      dot();
      dot();
      dash();
      break;
    case 'v':
      dot();
      dot();
      dot();
      dash();
      break;
    case 'w':
      dot();
      dash();
      dash();
      break;
    case 'x':
      dash();
      dot();
      dot();
      dash();
      break;
    case 'y':
      dash();
      dot();
      dash();
      dash();
      break;
    case 'z':
      dash();
      dash();
      dot();
      dot();
      break;
    case '1':
      dot();
      dash();
      dash();
      dash();
      dash();
      break;
    case '2':
      dot();
      dot();
      dash();
      dash();
      dash();
      break;
    case '3':
      dot();
      dot();
      dot();
      dash();
      dash();
      break;
    case '4':
      dot();
      dot();
      dot();
      dot();
      dash();
      break;
    case '5':
      dot();
      dot();
      dot();
      dot();
      dot();
      break;
    case '6':
      dash();
      dot();
      dot();
      dot();
      dot();
      break;
    case '7':
      dash();
      dash();
      dot();
      dot();
      dot();
      break;
    case '8':
      dash();
      dash();
      dash();
      dot();
      dot();
      break;
    case '9':
      dash();
      dash();
      dash();
      dash();
      dot();
      break;
    case '0':
      dash();
      dash();
      dash();
      dash();
      dash();
      break;
  }
  delay(dotDelay);
}

void MorseCode::dot(){
  charliePlex.ledWrite(led, ON);
  delay(dotDelay);
  charliePlex.ledWrite(led, OFF);
  delay(dotDelay*3);
}

void MorseCode::dash(){
  charliePlex.ledWrite(led, ON);
  delay(dotDelay * 6);
  charliePlex.ledWrite(led, OFF);
  delay(dotDelay*3);
}

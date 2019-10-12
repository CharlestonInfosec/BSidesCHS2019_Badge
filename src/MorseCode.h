/*
 * Author: Cory Nance
 * Version: 0.1
 */
 
#include "Chaplex.h"

class MorseCode {
  public:
    MorseCode(Chaplex& cp, charlieLed cp_led);
    void write(char c);
    void write(char* c);
    void dot();
    void dash();  
  private:

    Chaplex charliePlex;
    charlieLed led;
    int dotDelay;
};

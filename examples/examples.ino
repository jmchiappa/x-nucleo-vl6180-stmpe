#include "vl6180-stmpe.h"

VL6180STMPE expander;
uint16_t cnt=0;
uint32_t t=0;

void setup(void) {
  expander.init();
}

void loop(void) {

  if( (millis()-t)>50 ) {
    cnt++;
    t=millis();
  }
  expander.displayValue(cnt);
}

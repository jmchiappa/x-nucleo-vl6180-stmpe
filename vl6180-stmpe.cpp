#include "vl6180-stmpe.h"

static const uint16_t PROGMEM VL_select[] = {
    VL6180_CE_TOP,
    VL6180_CE_BOTTOM,
    VL6180_CE_LEFT,
    VL6180_CE_RIGHT
};

static const uint16_t PROGMEM digit_sel[] = {
  0b0000011100000000, //LSB
  0b0000011010000000,
  0b0000010110000000,
  0b0000001110000000
};

static const unsigned char PROGMEM Segment_digit[] = {
  S_G,            // 0
  ~(S_E | S_F),   // 1
  S_C | S_F,      // 2
  S_B | S_C,      // 3
  S_A | S_B | S_D,// 4
  S_B | S_E,      // 5
  S_E,            // 6
  ~(S_D | S_E | S_F), // 7
  0,              // 8
  S_B,            // 9
  S_A,            // A
  S_D | S_E,      // B
  S_E | S_F | S_G, // C
  S_D | S_E,      // D
  S_E | S_F,      // E
  S_E | S_F | S_A, // F
  ~S_G,           // -
  0x7F,           // BLANK
};

VL6180STMPE::VL6180STMPE(void) {}

void VL6180STMPE::init(void) {
	expander.init();
  expander.writeDirection(~SELECTOR);
}

void VL6180STMPE::displayValue(uint16_t val) {
  uint8_t tmp;
  for(uint8_t d=0;d<4;d++){
    tmp = val - (val/10)*10;
    if( (d>0) && (val==0) )
      expander.writeState(digit_sel[d] | Segment_digit[S_BLANK] );
    else
      expander.writeState(digit_sel[d] | ( Segment_digit[tmp] & 0x7F) );
    delay(2);
    val /= 10;
  }
}

void VL6180STMPE::select_VL(uint8_t sensor_nb) {
  if(sensor_nb<4){
    uint16_t tmp =expander.readState();
    tmp |= VL_select[sensor_nb];
    expander.writeState(tmp);
  }
}

void VL6180STMPE::deselect_VL(uint8_t sensor_nb) {
  if(sensor_nb<4){
    uint16_t tmp =expander.readState();
    tmp &= (~VL_select[sensor_nb]);
    expander.writeState(tmp);
  }
}
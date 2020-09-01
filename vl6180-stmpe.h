#ifndef VL6180STMPE_h
#define VL6180STMPE_h

#include "stmpe.h"

/*
      d
      -
   c | | e
      -  <-- g
   b | | f
      - 
      a
*/

// segment is off when set to 1

#define S_A (1<<0)
#define S_B (1<<1)
#define S_C (1<<2)
#define S_D (1<<3)
#define S_E (1<<4)
#define S_F (1<<5)
#define S_G (1<<6)

#define DIGIT1  (1<<7)
#define DIGIT2  (1<<8)
#define DIGIT3  (1<<9)
#define DIGIT4  (1<<10)

#define SELECTOR (1<<11)

#define VL6180_CE_TOP     (1<<12)
#define VL6180_CE_BOTTOM  (1<<13)
#define VL6180_CE_LEFT    (1<<14)
#define VL6180_CE_RIGHT   (1<<15)


#define S_MINUS 16
#define S_BLANK 17

#define ALL_SEG_SEL 0x780

#define I2C_ADDR  0x42


class VL6180STMPE {
	public:
		VL6180STMPE(void);
		void init(void);
		void displayValue(uint16_t val);
		void select_VL(uint8_t sensor_nb);
		void deselect_VL(uint8_t sensor_nb);
	private:
		STMPE expander;
};

#endif
#ifndef sh3d_led_h
#define sh3d_led_h
#include <Arduino.h>

// ENUM !!!
enum {
	LED_OFF,
	LED_ON,
	LED_SLOW,
	LED_FAST,
	LED_SHORT,
	LED_DOUBLE,
	LED_TRIPPLE,
	LED_SHORT_LONG,
	LED_DOUBLE_LONG,
	LED_TRIPPLE_LONG
};

class LED {
	public:
		void loop();
		void set(uint8_t m) { mode = m; state = 0; }
		uint8_t get() { return mode; }
		void begin();
		void disable();
		void enable();
		void setInverted(bool i) { inverted = i; }
		
		LED(uint8_t _p, bool i = false) {pin = _p; inverted = i;}

	protected:
		uint8_t pin;
		uint8_t mode;
		uint8_t state;
		bool inverted;
		uint32_t last;	// TODO - support roll over (elapsedMillis)
};

#endif



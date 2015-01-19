/*

TODO

*/
#include <LED.h>

void LED::begin() {
	pinMode(pin, OUTPUT);
}

void LED::loop() {
	if ( (millis() - last) < 100)
		return;

	switch (mode) {
		case LED_OFF:      // Off
			digitalWrite(pin, inverted ? HIGH : LOW);
			break;
		case LED_ON: // On
			digitalWrite(pin, inverted ? LOW : HIGH);
			break;
		case LED_SLOW: // Slow
			if ((state % 4) == 0)
				digitalWrite(pin, !digitalRead(pin));
			break;
		case LED_FAST: // Fast
			if ((state % 2) == 0)
				digitalWrite(pin, !digitalRead(pin));
			break;
		case LED_SHORT: // Fast
			if ((state % 6) == 0)
				digitalWrite(pin, inverted ? LOW : HIGH);
			else 
				digitalWrite(pin, inverted ? HIGH : LOW);
			break;
		case LED_DOUBLE:
			if ( ((state % 8) == 0) || ((state % 8) == 2) )
				digitalWrite(pin, inverted ? LOW : HIGH);
			else 
				digitalWrite(pin, inverted ? HIGH : LOW);
			break;
		case LED_TRIPPLE:
			if ( ((state % 12) == 0) || ((state % 12) == 2) || ((state % 12) == 4) ) 
				digitalWrite(pin, inverted ? LOW : HIGH);
			else 
				digitalWrite(pin, inverted ? HIGH : LOW);
			break;
	}

	state++;
	last = millis();
}

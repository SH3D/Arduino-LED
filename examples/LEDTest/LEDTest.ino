#include <LED.h>
LED led(9, true);

void setup() {
	Serial.begin(115200);
	led.begin();

}

uint8_t mode = 0;
uint32_t last;
void loop() {
	led.loop();

	if ( (millis() - last) > 5000) {
		led.set(led.get() + 1);
		if (led.get() > 6)
			led.set(0);
		Serial.print(F("Mode = "));
		Serial.println(led.get());
		last = millis();
	}
}

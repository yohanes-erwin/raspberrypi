#include <stdio.h>
#include <wiringPi.h>

// LED on Raspberry Pi 2 (pin 16), Broadcom (pin 23)
#define LED_PIN	23

int main(void)
{
	// Initialize wiringPi using Broadcom pin numbers
	wiringPiSetupGpio();

	// Initialize LED pin as an output
	pinMode(LED_PIN, OUTPUT);

	printf("LED blinking on Raspberry Pi 2 pin 16. Press CTRL+C to quit.\n");

	while (1)
	{
		// Blink LED every 1s
		digitalWrite(LED_PIN, HIGH);
		delay(1000);
		digitalWrite(LED_PIN, LOW);
		delay(1000);
	}

	return 0;
}

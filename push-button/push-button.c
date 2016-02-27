#include <stdio.h>
#include <wiringPi.h>

// Push button on Raspberry Pi 2 (pin 11), Broadcom (pin 17)
#define PUSH_BUTTON_PIN	17

int main(void)
{
	// Initialize wiringPi using Broadcom pin numbers
	wiringPiSetupGpio();

	// Initialize push button pin as input
	pinMode(PUSH_BUTTON_PIN, INPUT);
	// Enable internal pull-up resistor for button
	pullUpDnControl(PUSH_BUTTON_PIN, PUD_UP);

	printf("Read push button input from Raspberry Pi 2 pin 11. Press CTRL+C to quit.\n");

	while (1)
	{
		// If digitalRead returns 0, then button is pressed (active low button configuration)
		if (!digitalRead(PUSH_BUTTON_PIN))
		{
			printf("Push button on Raspberry Pi pin 11 is pressed.\n");
		}
		else
		{
			printf("Push button on Raspberry Pi pin 11 is released.\n");
		}

		delay(100);
	}

	return 0;
}

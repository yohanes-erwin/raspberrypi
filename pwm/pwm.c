#include <stdio.h>
#include <wiringPi.h>

// PWM LED on Raspberry Pi 2 (pin 12), Broadcom (pin 18)
#define PWM_PIN 18

int i;

int main(void)
{
	// Initialize wiringPi using Broadcom pin numbers
	wiringPiSetupGpio();

	// Initialize PWM LED pin as an PWM output
	pinMode(PWM_PIN, PWM_OUTPUT);

	printf("LED dimming on Raspberry Pi 2 pin 12. Press CTRL+C to quit.\n");

	while (1)
	{
		// Dimming LED from zero to maximum brightness
		for (i = 0; i <= 255; i+=10)
		{
			pwmWrite(PWM_PIN, i);
			delay(100);
		}
		// Dinning LED from maximum to zero brightness
		for (i = 255; i >= 0; i-=10)
		{
			pwmWrite(PWM_PIN, i);
			delay(100);
		}
	}

	return 0;
}

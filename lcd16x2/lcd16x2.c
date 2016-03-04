#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>

// LCD pin numbers definition using wiringPi pin numbers
#define LCD_RS	0
#define LCD_E	1
#define LCD_D4	2
#define LCD_D5	3
#define LCD_D6	4
#define LCD_D7	5

int lcdHandle;

int main(void)
{
	// Initialize wiringPi using wiringPi pin numbers
	wiringPiSetup();

	// Initialize LCD
	lcdHandle = lcdInit(2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);

	printf("LCD 16x2 \"Hello, World!\" blinking. Press CTRL+C to quit.\n");

	while (1)
	{
		// Blinking "Hello, World!" every 1s
		lcdPuts(lcdHandle, "Hello, World!");
		delay(1000);
		lcdClear(lcdHandle);
		delay(1000);
	}

	return 0;
}

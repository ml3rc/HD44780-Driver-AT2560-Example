/********** Defines before Includes **********/
#define F_CPU 16000000UL // CPU frequency for delay (must be before includes)

/********** Includes **********/
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "lib/HD44780-Driver-AT2560/HD44780.h"

/********** Buttons **********/
#define BUTTON_PORT PORTA
#define BUTTON_DDR  DDRA
#define BUTTON_PIN  PINA

#define T0 PA0
#define T1 PA1
#define T2 PA2
#define T3 PA3
#define T4 PA4
#define T7 PA7

int main(void) {

	/* Example strings */
	char helloString[] = "Hello World!";
	char valueString[] = "23";
	char piString[] = "3.141";

	/* Custom character example */
	uint8_t symbol[8] = {
		0x00,
		0x0A,
		0x00,
		0x04,
		0x11,
		0x0E,
		0x00,
		0x00
	};

	/* Configure buttons as input with pull-ups */
	BUTTON_DDR = 0x00;     // all inputs
	BUTTON_PORT = 0xFF;    // enable internal pull-ups

	/* Initialize LCD */
	InitPins();
	InitDisplay();
	CreateCustomChar(symbol, 0);

	ClearDisplay();

	while (1) {

		/* T0 -> Hello World */
		if (!(BUTTON_PIN & (1 << T0))) {
			PrintString(helloString);
			_delay_ms(200);
		}

		/* T1 -> "23" */
		if (!(BUTTON_PIN & (1 << T1))) {
			PrintString(valueString);
			_delay_ms(200);
		}

		/* T2 -> "3.141" */
		if (!(BUTTON_PIN & (1 << T2))) {
			PrintString(piString);
			_delay_ms(200);
		}

		/* T3 -> show custom symbol */
		if (!(BUTTON_PIN & (1 << T3))) {
			ShowCustomChar(0, 1, 0);
			_delay_ms(200);
		}

		/* T4 -> shift display right */
		if (!(BUTTON_PIN & (1 << T4))) {
			ShiftRight();
			_delay_ms(200);
		}

		/* T7 -> clear display */
		if (!(BUTTON_PIN & (1 << T7))) {
			const char formFeed[] = "\f";
			PrintString(formFeed);
			_delay_ms(200);
		}
	}
}
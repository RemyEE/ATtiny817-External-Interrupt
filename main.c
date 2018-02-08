#include <atmel_start.h>
#include <util/delay.h>
#include <avr/interrupt.h>


ISR(PORTC_PORT_vect) {
	PORTC.OUT ^= (1 << 0);
	PORTC.INTFLAGS |= (1 << 5);
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	PORTC.DIR |= (1 << 0);			// User led as Output
	
	/*
	* INTn in PORT.INTFLAGS is raised as configured by ISC bit in
	* PORT.PINnCTRL.
	*/
	PORTC.DIR &= ~(1 << 5);			// User button as Input
	PORTC.PIN5CTRL |= (1 << 1) | (1 << 0);	//Sense falling edge
	
	sei();
	
	while (1)
	{
		
		//_delay_ms(500);
	}
}

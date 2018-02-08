# ATtiny817 External Interrupt using ATtiny817 Xplained Mini

## Create New Atmel Start project
http://start.atmel.com/#board/ATtiny817XplainedMini
You can set pins as input or output on Atmel START project or do it later on your code.

## Enable external interrupt
```C
PORTC.DIR &= ~(1 << 5);			// Set User button as Input
PORTC.PIN5CTRL |= (1 << 1) | (1 << 0);	//Sense falling edge

sei();			// Enable Interrupt
```

## Set a pin as output (my case: PC0)

## Handle Interrupt Service Routine
```C
ISR(PORTC_PORT_vect) {
	PORTC.OUT ^= (1 << 0);
	PORTC.INTFLAGS |= (1 << 5);			// Clear Interrup Pin Flag, must do this to handle next interrupt
}
```

Check source code (main.c file only)

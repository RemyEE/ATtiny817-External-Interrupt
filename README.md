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
```
PORTC.DIR |= (1 << 0);			// User led as Output
```

## Handle Interrupt Service Routine
```C
ISR(PORTC_PORT_vect) {
	PORTC.OUT ^= (1 << 0);
	PORTC.INTFLAGS |= (1 << 5);			// Clear Interrup Pin Flag, must do this to handle next interrupt
}
```

Check source code (main.c file only)

## Buy me a Coffee

<a href='https://ko-fi.com/H2H096KN' target='_blank'><img height='32' style='border:0px;height:32px;' src='https://az743702.vo.msecnd.net/cdn/kofi1.png?v=b' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>

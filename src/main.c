#include "main.h"

// Default values for the core system clock frequency.
uint32_t core_clock_hz = 8000000;

// SysTick counter definition.
volatile uint32_t systick = 0;

// Delay for a specified number of milliseconds.
// TODO: Prevent rollover bug on the 'systick' value.
void delay_ms( uint32_t ms ) {
  // Calculate the tick value when the system should stop delaying.
  uint32_t next = systick + ms;

  // Wait until the system reaches that tick value.
  // Use the 'wait for interrupt' instruction to save power.
  while ( systick < next ) __WFI();
}

void delay_nop(uint32_t iterations) {
	for (uint32_t i = 0; i < iterations; ++i) __NOP();
}

// SysTick interrupt handler: increment the global 'systick' value.
void SysTick_Handler( void ) {
  ++systick;
}

/**
 * Main program.
 */
int main(void) {
  // Setup the SysTick peripheral to 1ms ticks.
  SysTick_Config( core_clock_hz / 1000 );

  // Enable GPIO peripherals. (`LEDEN` defined in `main.h`)
  RCC->AHBENR   |= ( LEDEN );

  // GPIO pin setup: output, push-pull, low-speed.
  // (`PoLED` and `PiLED` defined in `main.h`)
  PoLED->MODER    &= ~( 0x3 << ( PiLED * 2 ) );
  PoLED->MODER    |=  ( 0x1 << ( PiLED * 2 ) );
  PoLED->OTYPER   &= ~( 0x1 << PiLED );
  PoLED->OSPEEDR  &= ~( 0x3 << ( PiLED * 2 ) );
  PoLED->OSPEEDR  |=  ( 0x1 << ( PiLED * 2 ) );
  PoLED->ODR      |=  ( 1 << PiLED );

  // Toggle the LED every second.
  while ( 1 ) {
    delay_ms(1000);
    PoLED->ODR ^=  ( 1 << PiLED );
  }

  return 0;
}

#include "asf.h"

int main(void)
{
  SystemInit();
  configure_io();
  
  WDT->WDT_MR = WDT_MR_WDDIS;

	// Set up SysTick Timer for 1 msec interrupts.
	if (SysTick_Config(SystemCoreClock/ 1000)) {
		// Capture error.
		while (1);
	}
  return 0;
}
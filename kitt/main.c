typedef volatile unsigned int DWCREG;
typedef DWCREG * DWCREG_PTR;

#define CPU_CLOCK		        25000000
#define	DWC_GPIO_0	                0x00002000U
#define PERIPHERAL_BASE_ADDRESS		0x20a
#define PERIPHERAL_BASE 	        __builtin_arc_lr(PERIPHERAL_BASE_ADDRESS)

#define SWPORTA_DR      0
#define SWPORTA_DDR     1

#define SWPORTB_DR      3
#define SWPORTB_DDR     4

#define SWPORTC_DR      6
#define SWPORTC_DDR     7

#define DEFAULT_LED_MASK	 	(0x1FF)

#include "delay.h"


void gpio_init (DWCREG_PTR gpioRegs)
{
  //initilize buttons
  gpioRegs[SWPORTA_DR]  = 0;       //Data to PortA
  gpioRegs[SWPORTA_DDR]  = 0;      //PortA - input

  //LED[7:0]
  gpioRegs[SWPORTB_DR]  = DEFAULT_LED_MASK;
  gpioRegs[SWPORTB_DDR] = DEFAULT_LED_MASK;  //PortB - output

  //Switches
  gpioRegs[SWPORTC_DR]  = 0;       //Data to PortC
  gpioRegs[SWPORTC_DDR] = 0;       //PortC - input
}

void
gpio_set_leds (DWCREG_PTR gpioRegs,
	       unsigned int leds)
{
  gpioRegs[SWPORTB_DR] = leds;
}

int main (void)
{
  uint32_t leds;
  uint32_t i;
  DWCREG_PTR pctr = (DWCREG_PTR) (DWC_GPIO_0 | PERIPHERAL_BASE);

  gpio_init(pctr);

  leds = 1;
  while (1)
    {
      for (i=0; i<7; i++)
	{
	  _delay_ms (80);
	  leds = leds << 1;
	  gpio_set_leds(pctr, ~leds);
	}
      for (i=0; i<7; i++)
	{
	  _delay_ms (80);
	  leds = leds >> 1;
	  gpio_set_leds(pctr, ~leds);
	}
    }
  return 0;
}

#ifndef _UTIL_DELAY_H_
#define _UTIL_DELAY_H_

#include <inttypes.h>

#ifndef CPU_CLOCK
# error "CPU_CLOCK not defined"
# define CPU_CLOCK 1000000UL
#endif

#define DELAY_MS ((int) (((CPU_CLOCK * 10)/ 2e3 + 9) / 10))

/**
   Delay loop using a 32-bit counter \c __count, so up to 4294967295
   iterations are possible. The loop executes two CPU cycles per
   iteration, not including the overhead the compiler requires to
   setup the counter register pair.
*/
void
_delay_loop(uint32_t __count)
{
        __asm__ volatile (
                "1: sub.f %0,%0,1" "\n\t"
                "bne_s 1b"
                : "=r" (__count)
                : "0" (__count)
	        : "cc"
        );
}

void _delay_ms(uint16_t __ms)
{
  uint32_t __ticks = DELAY_MS * __ms;
  _delay_loop (__ticks);
}

#endif /* _UTIL_DELAY_H_ */

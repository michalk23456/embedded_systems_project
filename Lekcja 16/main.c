#include <stdint.h>
#include <intrinsics.h>
#include "tm4c_cmsis.h"
#include "bsp.h"

int main() {
    SYSCTL->RCGC2 |= (1U << 5); 
    SYSCTL->GPIOHSCTL |= (1U << 5); 
    GPIOF_HS->DIR |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIOF_HS->DEN |= (LED_RED | LED_BLUE | LED_GREEN);

    SysTick->LOAD = SYS_CLOCK_HZ/2U - 1U;
    SysTick->VAL  = 0U;
    SysTick->CTRL = (1U << 2) | (1U << 1) | 1U;

    __enable_interrupt();
    
    while (1) {
    }
    
}

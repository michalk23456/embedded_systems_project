#include "tm4c_cmsis.h"

__stackless void assert_failed (char const *file, int line) {
  NVIC_SystemReset(); 
}

void SysTick_Handler(void) {
}
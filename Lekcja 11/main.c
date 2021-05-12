#include <stdint.h>

#include "lm4f120h5qr.h"
#include "delay.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)

uint8_t u8a, u8b;
uint16_t u16c, u16d;
uint32_t u32e, u32f;

int8_t s8;
int16_t s16;
int32_t s32;

int main()
{
 u8a= sizeof(u8a); 
 u16c = sizeof(uint16_t);
 u32e = sizeof(uint32_t);
 
 u8a = 0xa1U;
 u16c = 0xc1c2U;
 u32e = 0xe1e2e3e4U;
 
 u8b = u8a;
 u16d=u16c;
 u32f = u32e;
 u16c = 40000U;
 u16d =30000U;
 u32e = (uint32_t)u16c +u16d;
 
 u16c = 100U;
 s32 = 10 - (int16_t(u16c));
 
 if ((int32_t)u32e > -1)
 {
   u8a = 1U;
 }
 else 
 {
   u8a = 0U;
 }

 u8a = 0xffU;
 if ((uint8_t)~u8a == 0x00U)  //konwertowanie na bajt 
 {
   u8a = 1U;
 }
  
 SYSCTL_RCGCGPIO_R |= (1U << 5);//odblokowujemy clock gating, GPIO PORTF enabled
 SYSCTL_GPIOHBCTL_R |= (1U << 5); //wlaczamy AHB dla GPIOF 
 GPIO_PORTF_AHB_DIR_R|=(LED_RED|LED_BLUE|LED_GREEN);  //ustawiamy piny 1,2,3 jako nasze outputy 
 GPIO_PORTF_AHB_DEN_R |=(LED_RED|LED_BLUE|LED_GREEN);
 
 GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE; // niebieski led wlaczony caly czas 
 while(1)
 {
 GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
 delay(500000);
 GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0; 
 delay(500000);
 }
  
}

    
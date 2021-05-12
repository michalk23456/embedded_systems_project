#include "lm4f120h5qr.h"
#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)
int main()
{
 SYSCTL_RCGCGPIO_R |= (1U << 5);//odblokowujemy clock gating, GPIO PORTF enabled
 SYSCTL_GPIOHBCTL_R |= (1U << 5); //wlaczamy AHB dla GPIOF 
 GPIO_PORTF_AHB_DIR_R|=(LED_RED|LED_BLUE|LED_GREEN);  //ustawiamy piny 1,2,3 jako nasze outputy 
 GPIO_PORTF_AHB_DEN_R |=(LED_RED|LED_BLUE|LED_GREEN);
 
 GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE; // niebieski led wlaczony caly czas 
 while(1)
 {
 GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
 int volatile counter[2]={0 , 0};
 while (counter[0] <1000000)
 {
   ++counter[0];
 }
 GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0; 
 while (counter[1] <1000000)
 {
   ++counter[1];
 }
 }
  return 0;
}

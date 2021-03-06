#include "lm4f120h5qr.h"
#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)
void delay(int iter); //prototyp funkcji 
void delay(int iter) //nie przyjmuje zadnych argumentów (void), ani nie zwraca zadnej wartosci void
{
   int volatile counter;
   counter = 0;
 while (counter < iter)
 {
   ++counter;
 }
}

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
 delay(2000000);
 GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0; 
 delay(500000);
 }
  return 0;
}

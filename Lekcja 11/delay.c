#include "delay.h"

void delay(int volatile iter) //nie przyjmuje zadnych argument�w (void), ani nie zwraca zadnej wartosci void
{
 while (iter > 0)
 {
   --iter;
 }
}
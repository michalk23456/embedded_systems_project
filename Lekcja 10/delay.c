#include "delay.h"

void delay(int iter) //nie przyjmuje zadnych argumentów (void), ani nie zwraca zadnej wartosci void
{
   int volatile counter;
   counter = 0;
 while (counter < iter)
 {
   ++counter;
 }
}
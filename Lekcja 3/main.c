int counter = 0;
int main()
{
   /* zmienna która moze przetrzymywac adres zmiennej counter typu integer (integer variables */
  int *p_int = &counter; /* aperand na poczatku daje nam adress zmiennej counter i adres ten moze zostac przypisany do zmiennej p_int*/
  while(*p_int < 21) /* mozemy wyciagnac wartosc trzymana pod danym adresem wskaznika (czyli deferencja), gwiazdka na poczatku reprezentuje wartosc trzymana pod adresem p_int */
  {
    ++(*p_int);
  }   
   p_int = (int *)0x20000002; /* robimy type casting*/
  *p_int = 0xDEADBEEF; 
 
  return 0;
}

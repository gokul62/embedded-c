#include<pic.h>

#define PORTB;

void delay()
{
int i;
for (i=0;i<1275;i++);
}

void main()
{
  TRISB = 0;
  PORTB = 0X55;
  delay();
  PORTB = 0XAA;
  delay();
}

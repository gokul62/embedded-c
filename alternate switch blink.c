#include<pic.h>

#define LED0   RB0;
#define LED1   RB1;
#define LED2   RB2;

void main()
{
TRISB0 = 0;
TRISB1 = 0;
TRISB2 = 1;

LED1 = 0;
LED2 = 0;

while(1)
{
if(switch == 1)
{
LED1 = 1;
LED2 = 0;
delay();
LED1 = 0;
LED2 = 1;
delay();
}
else 
{
LED1 =0;
LED2 = 0;
}
}

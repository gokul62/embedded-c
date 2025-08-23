#include <pic.h>

#define LED = RB0;
#define switch = RB2;

void main()
{
TRISB0 = 0;
TRISB2 = 1;

while(1)
{
if(switch ==1)
{
RB0 = 1;
}
else 
{
RB2 = 0;
}
}
}

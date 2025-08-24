#include<pic.h>

void delay(int n)
{
    TRISB = 0x00;
    PORTC = 0x09;
    
}

void main()

{
    while(1)

{
    RC0 = 1;  // green 
    RC1 = 0;
    RC2 = 0;
    
    delay(1000);
    
    RC0 = 0;
    RC1 = 1;  //yellow
    RC2 = 0;
    
    delay(500);
    
    RC0 = 0;
    RC1 = 0;
    RC2 = 1;  // red
    
    delay(1000); 
}
    
    
}

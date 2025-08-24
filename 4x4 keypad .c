#include <pic.h>
#define _XTAL_FREQ 20000000   // Crystal 20 MHz

// Initialize keypad
void keypad_init()
{
    TRISB = 0x0F;   // RB0-RB3 = input (rows), RB4-RB7 = output (columns)
    PORTB = 0x00;
}

void main(void)
{
    char display;
    unsigned char scan, read;

    keypad_init();

    while(1)
    {
        scan = 0xFE;      // Make RB4 LOW, others HIGH
        PORTB = scan;
        read = PORTB & 0x0F;   

        if(read == 0x0E) display = '1';
        if(read == 0x0D) display = '4';
        if(read == 0x0B) display = '7';
        if(read == 0x07) display = '*';

        // ===== Column 2 =====
        scan = 0xFD;      // Make RB5 LOW
        PORTB = scan;
        read = PORTB & 0x0F;

        if(read == 0x0E) display = '2';
        if(read == 0x0D) display = '5';
        if(read == 0x0B) display = '8';
        if(read == 0x07) display = '0';

        
        scan = 0xFB;      //  RB6 LOW
        PORTB = scan;
        read = PORTB & 0x0F;

        if(read == 0x0E) display = '3';
        if(read == 0x0D) display = '6';
        if(read == 0x0B) display = '9';
        if(read == 0x07) display = '#';

        scan = 0xF7;      //  RB7 LOW
        PORTB = scan;
        read = PORTB & 0x0F;

        if(read == 0x0E) display = 'A';
        if(read == 0x0D) display = 'B';
        if(read == 0x0B) display = 'C';
        if(read == 0x07) display = 'D';

    
        TRISC = 0x00;   // PORTC output
        PORTC = display;

        __delay_ms(200);   // debounce
    }
}

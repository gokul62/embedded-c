#include<pic.h>

void main(void) {
    TRISB = 0x00;   // PORTB as output (connect LEDs to RB0–RB3)
    PORTB = 0x00;   // Initialize LEDs OFF

    while(1) {
        for (unsigned char i = 0; i < 16; i++) {  // 0 to 15 (4-bit binary)
            PORTB = i;    // Send binary value to LEDs
            __delay_ms(500);   // 500ms delay
        }
    }
}

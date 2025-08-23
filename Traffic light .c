#include <pic.h>

// PORTC : North & East
#define N_RED   RC0
#define N_YEL   RC1
#define N_GRN   RC2
#define E_RED   RC3
#define E_YEL   RC4
#define E_GRN   RC5

// PORTD : South & West
#define S_RED   RD0
#define S_YEL   RD1
#define S_GRN   RD2
#define W_RED   RD3
#define W_YEL   RD4
#define W_GRN   RD5

// ===== 7-SEGMENT LOOKUP (Common Anode) =====
const unsigned char seg_table[10] = {
    0xC0, //0
    0xF9, //1
    0xA4, //2
    0xB0, //3
    0x99, //4
    0x92, //5
    0x82, //6
    0xF8, //7
    0x80, //8
    0x90  //9
};

void seg_display(unsigned char num) {
    PORTB = seg_table[num];  // Output to 7-seg
}

// ===== DELAY WITH COUNTDOWN DISPLAY =====
void countdown(unsigned char t) {
    while(t > 0) {
        seg_display(t);
        __delay_ms(1000);
        t--;
    }
}

// ===== RESET ALL LIGHTS TO RED =====
void all_red() {
    N_RED=E_RED=S_RED=W_RED = 1;
    N_YEL=E_YEL=S_YEL=W_YEL = 0;
    N_GRN=E_GRN=S_GRN=W_GRN = 0;
}

// ===== ROAD CYCLES =====
void north_cycle() {
    all_red();
    N_GRN = 1;
    countdown(10);
    N_GRN = 0;
    N_YEL = 1;
    countdown(3);
    N_YEL = 0;
}

void east_cycle() {
    all_red();
    E_GRN = 1;
    countdown(10);
    E_GRN = 0;
    E_YEL = 1;
    countdown(3);
    E_YEL = 0;
}

void south_cycle() {
    all_red();
    S_GRN = 1;
    countdown(10);
    S_GRN = 0;
    S_YEL = 1;
    countdown(3);
    S_YEL = 0;
}

void west_cycle() {
    all_red();
    W_GRN = 1;
    countdown(10);
    W_GRN = 0;
    W_YEL = 1;
    countdown(3);
    W_YEL = 0;
}

// ===== MAIN PROGRAM =====
void main() {
    TRISC = 0x00;   // PORTC output
    TRISD = 0x00;   // PORTD output
    TRISB = 0x00;   // PORTB output (7-seg)

    PORTC = 0x00;
    PORTD = 0x00;
    PORTB = 0x00;

    while(1) {
        north_cycle();
        east_cycle();
        south_cycle();
        west_cycle();
    }
}

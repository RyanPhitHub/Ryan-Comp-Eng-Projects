#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP410.h"           // Include UBMP4 constants and functions

#include    "lcd.h" // Include LCD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONFIG1
// #pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
// #pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
// #pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
// #pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
// #pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
// #pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
// #pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
// #pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
// #pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// // CONFIG2
// #pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
// #pragma config CPUDIV = NOCLKDIV// CPU System Clock Selection Bit (NO CPU system divide)
// #pragma config USBLSCLK = 48MHz // USB Low Speed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
// #pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
// #pragma config PLLEN = ENABLED  // PLL Enable Bit (3x or 4x PLL Enabled)
// #pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
// #pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
// #pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
// #pragma config LVP = OFF        // Low-Voltage Programming Enable (Low-voltage programming disabled)



// location of the LED, DATA output, and pushbutton
#define LED LED4
#define DATA H1OUT



// frequency is 48MHz
// (need this so that __delay_ms() works properly)
#define _XTAL_FREQ 48000000


// macro to send the bit 'b' (can be either 0 or 1)
#define send(b) DATA=1; NOP(); NOP(); NOP(); DATA=b; NOP(); NOP(); NOP(); NOP(); DATA=0; NOP(); NOP(); NOP(); NOP();


// auxiliary functions to control the WS2812 NeoPixel LEDs
void sendByte (unsigned char b);
void sendRGB (unsigned char r, unsigned char g, unsigned char b);

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Variables
bool saberStatus = false;
char colourPicker = 0;
unsigned char red;
unsigned char green;
unsigned char blue;
// Macros 
#define lightSpeed 10


//Functions
void playNote(unsigned char duration, unsigned int originNote1, unsigned int originNote2) //Play note for duration and degree of slide
{
    unsigned int noteLength = duration * 15;
    for (unsigned int t = 0; t <= noteLength; t++)
    {
        if (t % originNote1 == 0)
        {
            BEEPER = !BEEPER;
        }
        if(t % originNote2 == 0)
        {
            H8OUT = !H8OUT;
        }
    }
}

void saberOff()
{
    char note = 140;
    char note2 = 100;
    for (char n = 37; n > 0; n--) 
    {
        for ( char x = 0; x < n - 1; x++)
        {
            sendRGB(red, green, blue);
        }
        sendRGB(0, 0, 0);
        playNote(10, note, note2);
        note -= 3;
        note2 -= 2;
        __delay_ms(lightSpeed);
    }
}

void saberOn()
{
    char note = 5;
    char note2 = 10;
    for (char n = 1; n < 38; n++) 
    {
        for (char x = 0; x < n; x++)
        {
            sendRGB(red, green, blue);
        }
        playNote(10, note, note2);
        note += 2;
        note2 += 4;
        __delay_ms(lightSpeed);
    }
}


void saberHum()
{
    for (char x = 0; x <= 30; x++)
    {
        playNote(10, 140, 190);
        playNote(10, 200, 240);
    }
    for (char x = 0; x <= 10; x++)
    {
        playNote(10, 140, 160);
        playNote(10, 170, 180);
    }
}

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
    // set up internal oscillator to run at 48 MHz
    
    // set the SCS settings (system clock select)
    // to use the frequency specified in configuration word (line 9)
    SCS0 = 0;
    SCS1 = 0;
    
    // set to 16 MHz configuration
    IRCF0 = 1;
    IRCF1 = 1;
    IRCF2 = 1;
    IRCF3 = 1;
    
    // enable PLL to result in 48MHz
    // (PLL is set to 3x in line 23)
    SPLLEN = 1;
    
    
    // set up peripherals
    
    // // LED is an output
    // TRISC2 = 0;
    
    // // DATA is an output
    // TRISC3 = 0;
    TRISC = 0b00000000;
    
    // turn off analog to digital converter
    ANSC2 = 0;
    ANSC3 = 0;
    
    // button input
    TRISB4 = 1;
    WPUA5 = 1;
    nWPUEN = 0;
    
    
    // declare variables used for animation



    while(1)
	{
        if (SW5 == 0 & saberStatus == false)
        {
            __delay_ms(500);
            colourPicker++;
            if (colourPicker > 5)
            {
                colourPicker = 0;
            }
        }
        if (colourPicker == 0)
        {
            red = green = 0;
            blue = 255;
        }
        if (colourPicker == 1)
        {
            red = blue = 0;
            green = 255;
        }
        if (colourPicker == 2)
        {
            blue = green = 0;
            red = 255;
        }
        if (colourPicker == 3)
        {
            red = blue = 255;
            green = 0;
        }
        if (colourPicker == 4)
        {
            red = 255;
            green = 100;
            blue = 0;
        }
        if (colourPicker == 5)
        {
            red = green = blue = 255;
        }
        if (SW3 == 0)
        {
            saberStatus = !saberStatus;
            if (saberStatus == false)
            {
                saberOff();
            }
            if (saberStatus == true)
            {
                saberOn();
            }
        }
        if (saberStatus == true)
        {
            saberHum();
        }




        __delay_ms(1);
       
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}
// send out a byte b in WS2812 protocol
void sendByte (unsigned char b) {

    if (b & 0b10000000) { send(1); } else { send(0); }
    if (b & 0b01000000) { send(1); } else { send(0); }
    if (b & 0b00100000) { send(1); } else { send(0); }
    if (b & 0b00010000) { send(1); } else { send(0); }
    if (b & 0b00001000) { send(1); } else { send(0); }
    if (b & 0b00000100) { send(1); } else { send(0); }
    if (b & 0b00000010) { send(1); } else { send(0); }
    if (b & 0b00000001) { send(1); } else { send(0); }
    
}

// send red, green, and blue values in WS2812 protocol
void sendRGB (unsigned char r, unsigned char g, unsigned char b) {

    sendByte(g);
    sendByte(r);
    sendByte(b);

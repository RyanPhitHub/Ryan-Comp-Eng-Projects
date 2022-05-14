```c
#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Variables
bool saberStatus = false; //Check if lightsaber is on or off

// Macros for note periods (First octave is modified to be lower)
#define C4 183465 / 16 
#define Db4 173172 / 16
#define D4 163454 / 16
#define Eb4 154276 / 16
#define E4 145617 / 16
#define F4 137445 / 16
#define Gb4 129733 / 16
#define G4 122448 / 16
#define Ab4 115579 / 16
#define A4 109090 / 16
#define Bb4 102968 / 16
#define B4 97189 / 16
#define C5 91734 / 64
#define Db5 166584 / 64
#define D5 161725 / 64
#define Eb5 77139 / 64
#define E5 72810 / 64
#define F5 68722 / 64
#define Gb5 64865 / 64
#define G5 61225 / 64
#define Ab5 57788 / 64
#define A5 54545 / 64
#define Bb5 51483 / 64
#define B5 48594 / 64
#define C6 45867 / 64


//Functions
void playNote(int duration, unsigned int originNote, char noteSlope) //Play note for duration and degree of slide
{
    for(unsigned int x = 0; x != duration; x++)
    {
        unsigned int note = x * noteSlope + originNote;
        BEEPER = !BEEPER;
        for(unsigned int y = 0; y < note; y++){}
    }
}

void saberHum() //Humming noise of lighsaber
{
    for(char i = 0; i < 2; i++)
    {
        playNote(30, C4, 10);
    }
    playNote(60, Eb4, 10);
}

void saberSwing() //Swinging noise of lightsaber
{
    playNote(15, B4, 20);
    playNote(30, A4, 20);
    playNote(30, Gb4, 30);
}

void saberContact() //Hitting noise of lightsaber
{
    for(char i = 0; i < 8; i++)
    {
        playNote(8, Ab5, 20);
        playNote(10, C6, 20);
    }
    playNote(200, C5, 30);
}

void saberOn() //Sound of lightsaber turning on
{
    for(char i = 0; i < 8; i++)
    {
        playNote(8, Ab5, 25);
        playNote(8, B5, 20);
    }
    playNote(250, C5, 20);
    playNote(150, Bb4, 20);
}

void saberOff() //Sound of lightsaber turning off
{
    playNote(20, G4, 5);
    playNote(40, G4, -(1 / 100));
    playNote(20, A4, 1);
    for(char i = 0; i < 8; i++)
    {
        playNote(10, C6, 25);
        playNote(10, A5, 20);
    }
    playNote(200, G5, 20);
    playNote(10, Gb5, 20);


}

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices

    while(1)
	{
        if(SW2 == 0) //Turn saber on when SW2 is pressed
        {
            saberOn();
            saberStatus = true;
        }
        while(saberStatus == true)
        {
            saberHum();
            if(SW2 == 0) //Turn off if SW2 is pressed again
            {
                saberOff();
                saberStatus = false;
            }
            else if(SW4 == 0) //Swing saber if SW4 is pressed
            {
                saberSwing();
            }
            else if(SW5 == 0) //Saber is touching something when SW5 is pressed
            {
                saberContact();
            }
        }
       
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}
```

```c
#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Program variable/definitions
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
void playNote(int duration, unsigned int originNote)
{
    for(unsigned int x = 0; x != duration; x++)
    {
        unsigned int cycleIndex = x;
        unsigned int note = cycleIndex * 10 + originNote;
        BEEPER = !BEEPER;
        for(unsigned int y = 0; y < note; y++){}
    }
}

void saberHum()
{
    for(char i = 0; i < 4; i++)
    {
        playNote(30, C4);
    }
    playNote(50, D4);
}


int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
    ADC_config();
	
    ADC_select_channel(ANQ1);

    while(1)
	{
        unsigned char lightSensorRead = ADC_read();//ADC_read_channel(ANQ1); closest hand: 11001110 close hand: 11001010 -> 11001100 anything else: <11001100
        //ADC_select_channel
        
        if(SW2 == 0)//(lightSensorRead < 0b11001100)
        {
            saberHum();
        }
        else if(SW3 == 0)//(lightSensorRead >= 0b11001100 && lightSensorRead < 0b11001110)
        {
            BEEPER = !BEEPER;
            __delay_us(1517);
            
        }
        else
        {
      
        }
       
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}


```

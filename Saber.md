```c
#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Program variable definitions
int delayCycles = 7000;
int resetDelay = 7000;
int maxDelay = 11000;
//Functions
void saberHum()
{
    delayCycles += 250;
    if(delayCycles >= maxDelay) // Delay resets; starts the next hum
    {
         delayCycles = resetDelay;
    }
    for(char humLength = 2; humLength != 0; humLength--)
    {
        BEEPER = !BEEPER;
        for( int humPitch = 0; humPitch <= delayCycles; humPitch++)
        {}
    }
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
        
        if(lightSensorRead < 0b11001100)
        {
            saberHum();
            LATC = 0b0000000;
        }
        else if(lightSensorRead >= 0b11001100 && lightSensorRead < 0b11001110)
        {
            __delay_ms(100);
            LATC = 0b00100000;
        }
        else
        {
            __delay_ms(100);
            LATC = 0b01000000;
        }
       
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

```

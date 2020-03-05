#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.

    unsigned char history = UNPRESSED;


    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if(timer0Expired())
        {
            count0 = count0 + 1;
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if(timer1Expired())
        {
            history = history << 1;
            unsigned char padS1 = checkStatus_LaunchpadS1();
            unsigned char padS2 = checkStatus_LaunchpadS2();
            unsigned char packS1 = checkStatus_BoosterpackS1();
            unsigned char packS2 = checkStatus_BoosterpackS2();
            if(padS1 == 0x01)
            {
                history |= (1<<0);
            }
            else if(padS2 == 0x01)
            {
                history |= (1<<0);
            }
            else if(packS1 == 0x01)
            {
                history |= (1<<0);
            }
            else if(packS2 == 0x01)
            {
                history |= (1<<0);
            }
            else
            {
                history &= ~(1<<0);
            }
        }



        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        bool check = fsmBoosterpackButtonS1(history);


        // TODO: If a completed, debounced button press has occurred, increment count1.
        if(check)
        {
            count1 = count1 + 1;
        }


    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    if(count % 3 == 0)
    {
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
    }
    else if((count+2) % 3 == 0)
    {
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Red();
    }
    else if((count+1) % 3 == 0)
    {
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    if(count % 3 == 0)
    {
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDBlue();
        turnOn_BoosterpackLEDGreen();
    }
    else if((count+2) % 3 == 0)
    {
        turnOff_BoosterpackLEDBlue();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDRed();
    }
    else if((count+1) % 3 == 0)
    {
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    bool pressed = false;

    if(buttonhistory == UNPRESSED)
    {
        if(PUSHED == true)
        {
            PUSHED = false;
            pressed = true;
        }
    }
    else
    {
        PUSHED = true;
    }


    return pressed;
}

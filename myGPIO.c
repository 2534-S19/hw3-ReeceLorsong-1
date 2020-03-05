/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    P1DIR &= ~(1<<1);
    P1REN |= (1<<1);
    P1OUT &= ~(1<<1);

    // Launchpad S2
    P1DIR &= ~(1<<4);
    P1REN |= (1<<4);
    P1OUT &= ~(1<<4);

    // Boosterpack S1
    P5DIR &= ~(1<<1);
    P5REN |= (1<<1);
    P5OUT &= ~(1<<1);

    // Boosterpack S2
    P3DIR &= ~(1<<5);
    P3REN |= (1<<5);
    P3OUT &= ~(1<<5);

    // Launchpad LED1
    P1DIR |= (1<<0);
    turnOff_LaunchpadLED1();

    // Launchpad LED2 Red
    P2DIR |= (1<<0);
    turnOff_LaunchpadLED2Red();

    // Launchpad LED2 Green
    P2DIR |= (1<<1);
    turnOff_LaunchpadLED2Green();

    // Launchpad LED2 Blue
    P2DIR |= (1<<2);
    turnOff_LaunchpadLED2Blue();

    // Boosterpack LED Red
    P2DIR |= (1<<6);
    turnOff_BoosterpackLEDRed();

    // Boosterpack LED Green
    P2DIR |= (1<<4);
    turnOff_BoosterpackLEDGreen();

    // Boosterpack LED Blue
    P5DIR |= (1<<6);
    turnOff_BoosterpackLEDBlue();


    // Turn off all LEDs at the start.
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    if(P1IN & (1<<1))
    {
        return 0x01;
    }
    else
    {
        return 0x00;
    }
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    if(P1IN & (1<<4))
    {
        return 0x01;
    }
    else
    {
        return 0x00;
    }
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    if(P5IN & (1<<1))
    {
        return 0x01;
    }
    else
    {
        return 0x00;
    }
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    if(P3IN & (1<<5))
    {
        return 0x01;
    }
    else
    {
        return 0x00;
    }
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT |= (1<<0);
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT &= ~(1<<0);
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT |= (1<<0);
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT &= ~(1<<0);
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT |= (1<<1);
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT &= ~(1<<1);
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT |= (1<<2);
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT &= ~(1<<2);
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT |= (1<<6);
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT &= ~(1<<6);
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT |= (1<<4);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT &= ~(1<<4);
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT |= (1<<6);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT &= ~(1<<6);
}

/* ***************************************************************************
**  File Name    	: HelloWorld_V1.c
**  Version			: 1.0
**  Description		: Introduce to digital I/O of PIC. This program basically
**					  works by displaying the LED attached to PORT B and pin
**					  7th of PORT D. Eight leds at port B use source current,
**					  so, they will turn on if pins at port B at high logic.
**					  Led at port D use sink current, so it will turn on if
**					  pin RD7 at low logic.
**  Author			: NguyenTienDat
**	Class			: KSTN - DTVT - K54
**  Microcontroller	: PIC18F46K20
**  Compiler     	: Microchip C18 v3.40 C Compiler
**  IDE          	: Microchip MPLAB IDE v8.83
**  Programmer   	: Microchip PICKit2 Programmer
**  Last Updated 	: 29 April 2012
** ***************************************************************************/


/*include header file p18f46k20.h.The �p18f46k20.h� file
 *is included as this device-specific header file contains
 *definitions for the variables used to access the Special
 *Function Registers (SFRs) of the microcontroller. Some
 *useful macros such as Nop() and ClrWdt() are also defined in this header
 */
#include "p18f46k20.h"


//Configuration bits
#pragma config FOSC = INTIO67	/*using internal oscillator with default frequency is 1MHz.
								 *To know more, you should reference in C18 lesson document or datasheet.
								 */
#pragma config WDTEN = OFF, LVP = OFF//turn off LVP because LVP mode is not used by the Pickit 2 Programmer
									 //and turn off Watchdog Timer. You can find out information in ICSP document.

/* I create some definitions to easy to change port and have more meaning.
 * If need to define many definitons, you should locate them in another file.
 */
#define ControlDirectIO_1		TRISB
#define ControlDirectIO_2		TRISD
#define RB_port				LATB
#define RD7_port			LATDbits.LATD7

//main function
void main(void)
{
	//if we want all pins of PORT B is ouput at high level to all led is turned on, we must do as following
	ControlDirectIO_1 = 0x00;//all pins of PORT B is output
	RB_port = 0xFF;//all pins of PORT B output at high level (use source current)
	
	//if we only want 7th pin of PORT D is output at high level, we must do as follow
	ControlDirectIO_2 = 0x7F;//all pins of PORT D is input except 7th pin
	RD7_port = 0;//7th pin is output at low level to turn on led (use sink current)
	
	while(1);//infinite while loop is used to keep the microcontroller running and 
			 //prevent it from exiting main() and trying to execute undefined memory 
			 //locations
}

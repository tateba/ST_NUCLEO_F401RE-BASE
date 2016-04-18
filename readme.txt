*****************************************************************************
** ST NUCLEO F401RE BASE PROGRAM                                           **
*****************************************************************************

Description
	This program is a starting point for any other projects.
	It just blink a LED and print a value of a counter to the Serial 
	Driver 2 (the USB port com).

RTOS
	The RTOS use is ChibiOS/RT, Thanks to Giovanni.

TARGET
	The program runs on an ST NUCLEOF401RE board from ST-Microelectronics.

Build Procedure
    1- Change the ChibiOS path according to your directories on the Makefile.
    2- Type make to compile the program

Flash the Board
	To program the board you can use one of the following:
    1- By using the st-flash command: st-flash write build/ch.bin 0x8000000
    2- By using my command, I add a makefile rules to easy program the board.
	the command is then: make program

Enjoy, comment.....

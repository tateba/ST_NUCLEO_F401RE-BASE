*****************************************************************************
** ST_NUCLEO_F401RE-BASE.                                                  **
*****************************************************************************

** Description **
    This program is a start point for my other projects, it just blink a LED
    and print a message to the Serial Driver 2 ( the USB port com ).

** RTOS **
    The RTOS use is ChibiOS/RT.

** TARGET **
    The program runs on an ST NUCLEOF401RE board.

** The Program **
    The program flashes the on board LED using a thread and send a message to
    the serial port 2 at the same time.

** Build Procedure **
    1- Change the ChibiOS path according to your directories on the Makefile.
    2- Type make to compile the program

** Flash the Board **
    1- By using the st-flash command: st-flash write build/ch.bin 0x8000000
    2- By using my command: make program

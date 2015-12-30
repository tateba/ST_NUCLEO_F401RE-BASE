*****************************************************************************
** ST_NUCLEO_F401RE-BASE.                                                  **
*****************************************************************************

** RTOS **
    The RTOS use is ChibiOS/RT

** TARGET **
    The program runs on an ST NUCLEOF401RE board.

** The Program **
    The program flashes the on board LED using a thread and send a message to
    the serial port 2 at the same time.

** Build Procedure **
    1- Change the ChibiOS path according to your directories on the Makefile.
    2- Type make to compile the program

** Flash the Board **
    st-flash write build/ch.bin 0x8000000

** enjoy ;) **

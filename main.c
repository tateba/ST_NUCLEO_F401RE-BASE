/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
* Includes libraries files
*/
#include "ch.h"
#include "hal.h"
#include "chprintf.h"

/*
* Variables:
*/
BaseSequentialStream* pc = (BaseSequentialStream*) &SD2; ///< Help to print data to a serial port
uint16_t counter = 0;	// Counter f

/*
 * LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg){
    
    (void)arg;
    chRegSetThreadName("blinker");
    systime_t time = chVTGetSystemTimeX();
    while (true){
		time += MS2ST(1000);
		palTogglePad(GPIOA, GPIOA_LED_GREEN);
        chprintf(pc, "\n\rfox: Hello - %d", counter++);
		chThdSleepUntil(time);
    }
}

/*
 * Application entry point.
 */
int main(void){
    /*
    * System initializations.
    * - HAL initialization, this also initializes the configured device drivers
    *   and performs the board-specific initializations.
    * - Kernel initialization, the main() function becomes a thread and the
    *   RTOS is active.
    */
    halInit();
    chSysInit();

    /*
    * Init Serial Driver 2 using the default configuration
    */
    sdStart(&SD2, NULL);
	chprintf(pc, "\n\r\n\rfox: Init serial port.");

    /*
    * Creates the blinker thread.
    */
	chprintf(pc, "\n\rfox: Create thread to blink the onboard LED2, increment a counter and print it to the serial port 2 (USB).");
    chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

    /*
    * Normal main() thread activity, in this demo it does nothing.
    */
    while (true){
        chThdSleepMilliseconds(1000);
    }
}

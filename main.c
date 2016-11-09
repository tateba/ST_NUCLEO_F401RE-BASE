/**
 * @file    main.c
 *
 * @brief   Main file for the application.
 *
 * @author  Theodore Ateba, tf.ateba@gmail.com
 *
 * @version 1.0
 *
 * @date    30 December 2015
 *
 * @update  09 November 2016
 *
 */

/*===========================================================================*/
/* Includes libraries files.                                                 */
/*===========================================================================*/
#include "ch.h"
#include "hal.h"
#include "chprintf.h"

/*===========================================================================*/
/* Local Variables.                                                          */
/*===========================================================================*/
BaseSequentialStream* pc = (BaseSequentialStream*) &SD2;  /**< For print     */
uint16_t counter = 0;                                     /**< Simple counter*/

/*===========================================================================*/
/* Function and thread function.                                             */
/*===========================================================================*/

/*
 * @biref LED blinker thread.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {
  (void)arg;

  chRegSetThreadName("blinker");
  systime_t time = chVTGetSystemTimeX();
  while (true) {
    time += MS2ST(1000);
    palTogglePad(GPIOA, GPIOA_LED_GREEN);
    chprintf(pc, "\n\rHello - %d", counter++);
    chThdSleepUntil(time);
  }
}

/*
 * Application entry point.
 */
int main(void) {
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
  chprintf(pc, "\n\r\n\r Init serial port.");

  /*
   * Creates the blinker thread.
   */
  chprintf(pc, "\n\r Create thread to blink the onboard LED2, increment a\
      counter and print it to the serial port 2 (USB).");
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  /*
   * Normal main() thread activity, in this demo it does nothing.
   */
  while (true) {
    chThdSleepMilliseconds(1000);
  }

  return 0;
}


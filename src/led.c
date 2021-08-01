/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "led.h"

/**
 * @brief Enciende el led que le defino
 * 
 * @param led gpioMap_t
 * @return bool_t (true si logro encender)
 */
#define encenderLed(led) gpioWrite(led, 1)

/**
 * @brief apago el led que le defino
 * 
 * @param led gpioMap_t
 * @return bool_t (true si logro apagar)
 */
#define apagarLed(led) gpioWrite(led, 0)

bool_t apagarLeds(void) {
	bool_t no_error;
	uint8_t i;
	for (i = LEDR ; i <= LED3 ; i++) {
		if (!apagarLed(i)) {
			no_error = false;
			break;
		}
	}
	return no_error;
}

bool_t encenderLedUnico(gpioMap_t led) {
	bool_t no_error;
	uint8_t i;
	for (i = LEDR ; i <= LED3 ; i++) {
		if (i == led) {
			no_error = encenderLed(i);
		}
		else {
			no_error = apagarLed(i);
		} 
		if (!no_error) {
			break;
		}
	}
	return no_error;
}




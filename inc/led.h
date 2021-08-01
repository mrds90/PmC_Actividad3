/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/08/01
 * Version: 1
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __LED_H__
#define __LED_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>
#include "sapi.h"

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/
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
/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/
/**
 * @brief Enciende el led que se le pasa por argumento y apaga los otros, si entra un valor que no corresponde a ningun led apaga todos *
 * 
 * @param led gpioMap_t
 * @return bool_t (true si pudo escribir todos los pines)
 */
bool_t encenderLedUnico(gpioMap_t led);
/**
 * @brief Apaga todos los leds
 * 
 * @return bool_t 
 */
bool_t apagarLeds(void);
/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __ACTIVIDAD2_H__ */

/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __SECUENCIAS_H__
#define __SECUENCIAS_H__

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

/*=====[Definitions of public data types]====================================*/
/**
 * @brief Estructura para controlar de forma escalable y genérica cualquier secuencia.
 * 
 */
typedef struct {
   gpioMap_t *ptrLed;
   gpioMap_t *ptrPrimerLed;
   gpioMap_t *ptrUltimoLed;

   uint16_t *ptrTiempo;
   uint16_t *ptrPrimerTiempo;
   uint16_t *ptrUltimoTiempo;
} control_secuencia_t;

/*=====[Prototypes (declarations) of public functions]=======================*/
/**
 * @brief gestiona la eleccion del led que debe encenderse según la secuencia que se le pasa por referencia
 * 
 */
void activarSecuencia(void);
/**
 * @brief Congfigura la secuencia y tiempos que se van a utilizar para conmutar los Leds.
 * 
 * @param psecuencia 
 * @param tiempo_destello 
 * @param tamanio_secuencia 
 */
void configurarSecuencia(gpioMap_t psecuencia[], uint16_t tiempo_destello[], uint8_t tamanio_secuencia);
/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __ACTIVIDAD2_H__ */

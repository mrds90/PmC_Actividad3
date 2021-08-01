/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/08/01
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
#define LEDR_ON      (1 << (LEDR - LEDR)) // LEDR ON
#define LEDG_ON      (1 << (LEDG - LEDR)) // LEDG ON
#define LEDB_ON      (1 << (LEDB - LEDR)) // LEDB ON
#define LED1_ON      (1 << (LED1 - LEDR)) // LED1 ON
#define LED2_ON      (1 << (LED2 - LEDR)) // LED2 ON
#define LED3_ON      (1 << (LED3 - LEDR)) // LED3 ON

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
/**
 * @brief Estructura para controlar de forma escalable y genérica cualquier secuencia.
 * 
 */
typedef struct {
   uint8_t *ptrLed;
   uint8_t *ptrPrimerLed;
   uint8_t *ptrUltimoLed;

   uint16_t *ptrTiempo;
   uint16_t *ptrPrimerTiempo;
   uint16_t *ptrUltimoTiempo;
} control_secuencia_t;

/*=====[Prototypes (declarations) of public functions]=======================*/
/**
 * @brief gestiona la eleccion del led que debe encenderse según la secuencia que se le pasa por referencia
 * 
 */
void ActualizarMEFSecuencia(void);
/**
 * @brief Congfigura la secuencia y tiempos que se van a utilizar para conmutar los Leds.
 * 
 * @param psecuencia 
 * @param tiempo_destello 
 * @param tamanio_secuencia 
 */
void IniciarMEFSecuencia(uint8_t psecuencia[], uint16_t tiempo_destello[], uint8_t tamanio_secuencia);
/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __ACTIVIDAD2_H__ */

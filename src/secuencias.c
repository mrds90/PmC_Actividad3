/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/secuencias.h"
#include "led.h"

/*=====[Definitions of private functions]====================================*/
static void incrementarSecuencia(void);

/*=====[Definitions of private global variables]=============================*/

static delay_t delayLeds;
static control_secuencia_t secuencia;

/*=====[Implementation of private functions]====================================*/

static void incrementarSecuencia(void) {
	secuencia.ptrLed++;
   secuencia.ptrTiempo++;
	if (secuencia.ptrLed >= secuencia.ptrUltimoLed) {
		secuencia.ptrLed = secuencia.ptrPrimerLed;
      secuencia.ptrTiempo = secuencia.ptrPrimerTiempo;
	}
}
/*=====[Implementation of public functions]==================================*/
void configurarSecuencia(gpioMap_t psecuencia[], uint16_t tiempo_destello[], uint8_t tamanio_secuencia) {

   secuencia.ptrPrimerLed = &psecuencia[0];
   secuencia.ptrLed = secuencia.ptrPrimerLed;

   secuencia.ptrPrimerTiempo = &tiempo_destello[0];
   secuencia.ptrTiempo = secuencia.ptrPrimerTiempo;

   secuencia.ptrUltimoLed = &psecuencia[tamanio_secuencia];
   secuencia.ptrUltimoTiempo = &tiempo_destello[tamanio_secuencia];
}

void activarSecuencia(void) {
   if(delayRead(&delayLeds)) {
      incrementarSecuencia();
      encenderLedUnico(*secuencia.ptrLed);
      delayConfig(&delayLeds, *secuencia.ptrTiempo);
   }
}


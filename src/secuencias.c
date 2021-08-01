/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/08/01
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
static void DecodificarSecuencia(void) {
   uint8_t led;
   for (led = 0; led < (LED3 - LEDR + 1); led++) {
      if (*secuencia.ptrLed & (1<<led)) {
         encenderLed(led+LEDR);
      }
      else {
         apagarLed(led+LEDR);
      }
   }
}
/*=====[Implementation of public functions]==================================*/
void IniciarMEFSecuencia(uint8_t psecuencia[], uint16_t tiempo_destello[], uint8_t tamanio_secuencia) {

   secuencia.ptrPrimerLed = &psecuencia[0];
   secuencia.ptrLed = secuencia.ptrPrimerLed;

   secuencia.ptrPrimerTiempo = &tiempo_destello[0];
   secuencia.ptrTiempo = secuencia.ptrPrimerTiempo;

   secuencia.ptrUltimoLed = &psecuencia[tamanio_secuencia];
   secuencia.ptrUltimoTiempo = &tiempo_destello[tamanio_secuencia];

   DecodificarSecuencia();
   delayConfig(&delayLeds, *secuencia.ptrTiempo);
}

void ActualizarMEFSecuencia(void) {
   if(delayRead(&delayLeds)) {
      incrementarSecuencia();
      DecodificarSecuencia();
      if(*secuencia.ptrLed);
      delayConfig(&delayLeds, *secuencia.ptrTiempo);
   }
}



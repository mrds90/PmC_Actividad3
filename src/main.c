/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/main.h"
#include "../inc/semaforo.h"

/*=====[Main function, program entry point after power on or reset]==========*/

int main(void)
{
	boardInit();

	IniciarMEFSeaforo();
   // ----- Loop infinito -------------------------
    while(true) {
		ActualizarMEFSeaforo();
   }
	// Nunca se alcanza este punto debido al ciclo infinito del while(true)
   return 0;
}


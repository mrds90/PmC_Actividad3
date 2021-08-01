/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/08/01
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/main.h"
#include "../inc/semaforo.h"

/*=====[Main function, program entry point after power on or reset]==========*/

int main(void)
{
	boardInit();///< Initialize board

	IniciarMEFSeaforo();///< Initialize semaphore
   // ----- Loop infinito -------------------------
   while(true) {
		ActualizarMEFSeaforo();///< Update semaphore
   }
	
   return 0;
}


/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Author: Mario Aguilar <fernandoaguilar731010@gmail.com>
 * Date: 2021/07/31
 * Version: 1
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __SEMAFORO_H__
#define __SEMAFORO_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>
#include "sapi.h"


/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Prototypes (declarations) of public functions]=======================*/
/**
 * @brief Inicia la maquina de estados del semaforo.
 * 
 */
void IniciarMEFSeaforo(void);
/**
 * @brief Actualiza la maquina de estados del semaforo.
 * 
 */
void ActualizarMEFSeaforo(void);
/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __SEMAFORO_H__ */

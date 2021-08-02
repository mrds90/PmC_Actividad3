/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Author: Mario Aguilar <fernandoaguilar731010@gmail.com>
 * Date: 2021/08/01
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/semaforo.h"
#include "../inc/secuencias.h"
#include "../inc/teclas.h"

/*=====[Definitions of private constant]=================================*/
#define EDU_CIAA_OLD //comentar si se tiene una version nueva de la edu_ciaa

#define LED_OFF                 0
#ifdef  EDU_CIAA_OLD
#define LED_VERDE               LEDG_ON
#define LED_ROJO                LED2_ON
#define LED_AMARILLO            LED1_ON
#else
#define LED_ROJO                LED1_ON
#define LED_AMARILLO            LED2_ON
#define LED_VERDE               LED3_ON
#endif
#define PERIODO_500MS           500 
#define PERIODO_1S              1000 
#define PERIODO_3S              3000
#define TRUE_T                  0xFF
#define FALSE_T                 0x00


typedef enum {
    NORMAL,
    ALARM,
    DISCONECTED,
    
    SEMAFORO_QTY,
} semaforo_state_t;

/*=====[Definitions of private functions]====================================*/
/**
 * @brief Estado normal del semaforo. ROJO, ROJO_AMARILLO, VERDE, AMARILLO
 * 
 */
static void NormalState(void);
/**
 * @brief Estado desconectado del semaforo. AMARILLO, OFF, AMARILLO, OFF
 * 
 */
static void DisconnectedState(void);
/**
 * @brief Estado alarma del semaforo. ROJO, OFF, ROJO, OFF
 * 
 */
static void AlarmState(void);

/*=====[Definitions of private global variables]=============================*/
static semaforo_state_t semaforo_state;

/**
 * @brief Vector con los tiempos de la secuencia
 * 
 */
static uint16_t tiempo[4] = {PERIODO_3S,PERIODO_500MS,PERIODO_1S,PERIODO_500MS};
/**
 * @brief Matriz que tiene en la primera dimensión los posibles estados de semaforo y en la segunda dimensión la secuencia de leds que deben ensenderse en cada estado.
 * 
 */
static uint8_t secuencia[SEMAFORO_QTY][4] = {{LED_ROJO    , LED_ROJO | LED_AMARILLO , LED_VERDE    , LED_AMARILLO},
                                             {LED_ROJO    , LED_OFF                 , LED_ROJO     , LED_OFF     },
                                             {LED_AMARILLO, LED_OFF                 , LED_AMARILLO , LED_OFF     }};

/*=====[Implementation of public functions]==================================*/

void IniciarMEFSeaforo(void) {
    semaforo_state = NORMAL;
    IniciarMEFTecla(TEC2);
    IniciarMEFSecuencia(secuencia[NORMAL],tiempo,sizeof(secuencia[NORMAL])/sizeof(secuencia[NORMAL][0]));
}

void ActualizarMEFSeaforo(void) {
    void (*SemaforoFunc[SEMAFORO_QTY])(void) = {NormalState ,DisconnectedState, AlarmState};
    
    ActualizarMEFTecla(TEC2);
    if (CheckFallState(TEC2)) {
        if(++semaforo_state >= SEMAFORO_QTY) {
            semaforo_state = NORMAL;
        }
        SemaforoFunc[semaforo_state]();
    }

    ActualizarMEFSecuencia();
}
/*=====[Implementation of private functions]====================================*/

static void NormalState(void) {
    tiempo[0] = PERIODO_3S;
    tiempo[1] = PERIODO_500MS;
    tiempo[2] = PERIODO_1S;
    tiempo[3] = PERIODO_500MS;
    IniciarMEFSecuencia(secuencia[NORMAL],tiempo,sizeof(secuencia[NORMAL])/sizeof(secuencia[NORMAL][0]));
}

static void DisconnectedState(void) {
    tiempo[0] = PERIODO_500MS;
    tiempo[1] = PERIODO_500MS;
    tiempo[2] = PERIODO_500MS;
    tiempo[3] = PERIODO_500MS;
    IniciarMEFSecuencia(secuencia[DISCONECTED],tiempo,sizeof(secuencia[DISCONECTED])/sizeof(secuencia[DISCONECTED][0]));
}

static void AlarmState(void) {
    tiempo[0] = PERIODO_1S;
    tiempo[1] = PERIODO_1S;
    tiempo[2] = PERIODO_1S;
    tiempo[3] = PERIODO_1S;
    IniciarMEFSecuencia(secuencia[ALARM],tiempo,sizeof(secuencia[ALARM])/sizeof(secuencia[ALARM][0]));
}


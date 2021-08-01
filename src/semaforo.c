/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/semaforo.h"
#include "../inc/secuencias.h"
#include "../inc/teclas.h"

/*=====[Definitions of private constant]=================================*/
#define LED_OFF                 0
#define LED_VERDE               LEDG
#define LED_ROJO                LED2
#define LED_AMARILLO            LED1
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
static void NormalState(void);
static void AlarmState(void);
static void DisconnectedState(void);

/*=====[Definitions of private global variables]=============================*/
static semaforo_state_t semaforo_state;
static bool_t change_state = 0;

static uint16_t tiempo[4] = {PERIODO_3S,PERIODO_500MS,PERIODO_1S,PERIODO_500MS};

static gpioMap_t secuencia[SEMAFORO_QTY][4] = {{LED_ROJO    , LED_AMARILLO, LED_VERDE    , LED_AMARILLO},
                                               {LED_ROJO    , LED_OFF     , LED_ROJO     , LED_OFF  },
                                               {LED_AMARILLO, LED_OFF     , LED_AMARILLO , LED_OFF  }};

/*=====[Implementation of public functions]==================================*/

void IniciarMEFSeaforo(void) {
    semaforo_state = NORMAL;
    IniciarMEFTecla(TEC2);
    configurarSecuencia(secuencia[NORMAL],tiempo,sizeof(secuencia[NORMAL])/sizeof(secuencia[NORMAL][0]));
}

void ActualizarMEFSeaforo(void) {
    void (*SemaforoFunc[SEMAFORO_QTY])(void) = {NormalState, AlarmState ,DisconnectedState};
    
    ActualizarMEFTecla(TEC2);
    if (CheckFallState(TEC2)) {
        change_state = TRUE_T;
        if(++semaforo_state >= SEMAFORO_QTY) {
            semaforo_state = NORMAL;
        }
    }
    
    SemaforoFunc[semaforo_state]();
    activarSecuencia();
}
/*=====[Implementation of private functions]====================================*/
static void NormalState(void) {
    if(change_state) {
        change_state = FALSE_T;
        tiempo[0] = PERIODO_3S;
        tiempo[1] = PERIODO_500MS;
        tiempo[2] = PERIODO_1S;
        tiempo[3] = PERIODO_500MS;
        configurarSecuencia(secuencia[NORMAL],tiempo,sizeof(secuencia[NORMAL])/sizeof(secuencia[NORMAL][0]));
    }
}

static void AlarmState(void) {
    if(change_state) {
        change_state = FALSE_T;
        tiempo[0] = PERIODO_1S;
        tiempo[1] = PERIODO_1S;
        tiempo[2] = PERIODO_1S;
        tiempo[3] = PERIODO_1S;
        configurarSecuencia(secuencia[ALARM],tiempo,sizeof(secuencia[ALARM])/sizeof(secuencia[ALARM][0]));
    }
}

static void DisconnectedState(void) {
    if(change_state) {
        change_state = FALSE_T;
        tiempo[0] = PERIODO_500MS;
        tiempo[1] = PERIODO_500MS;
        tiempo[2] = PERIODO_500MS;
        tiempo[3] = PERIODO_500MS;
        configurarSecuencia(secuencia[DISCONECTED],tiempo,sizeof(secuencia[DISCONECTED])/sizeof(secuencia[DISCONECTED][0]));
    }
}



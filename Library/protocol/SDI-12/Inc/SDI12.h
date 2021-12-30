#ifndef __SDI_12_H__
#define __SDI_12_H__

#include "SDI12_conf.h"

#define SDI_MAX     1024

#define SDI12_WAKE_TIME               12
#define SDI12_RESPONSE_TIME_MAX       15

typedef enum _state{
    SPACING = 0,            // 3.5 to 5.5 volts
    MARKING = 1,            // -0.5 to 1.0 volts
    TRANSATION = 2          // 1.0 to 3.5 volts
    STANDBY = 3
}SDI_12_State;

typedef struct _SDI_12{
    
    
}SDI12_InitTypeDef;

/** Command enum Type */
typedef enum _SDI12_Command{
    GET_ALL_SENSOR_IDENTIFY,        // ()?I!
    SENSOR_IDENTIFY,                // (address)I!
    SENSOR_ADDRESS_CHANGE,          // (address)A(change_address)!
    SENSOR_START_MEASUREMENT,       // (sensorAddress)M! response - min wait time and get data value number
    SENSOR_GET_DATA,                // (sensorAddress)D(0 ~ data value number)!
    GET_ALL_DATA                    // (sensorAddress)R0!
} SDI12_Command_TypeDef;

typedef enum _SDI12_error_t{
    SDI12_ERROR_INVALID = -1,        // -1
	SDI12_ERROR_SUCCESS = 0,         // 0
	SDI12_ERROR_TIMEOUT,             // 1
	SDI12_ERROR_UNEXPECTED_PARAM,    // 2
	SDI12_ERROR_UNEXPECTED_RESPONSE, // 3
	SDI12_ERROR_NO_RESPONSE         // 4
} SDI12_error_t;



/** Break time high 12 ms and low 8ms  */
void SDI12_Break(uint32_t time);
/** making time 8ms */
void SDI12_Masking(uint32_t time);
/** Send SDI-12 Protocol Command*/
SDI12_error_t SDI12_SendCommand(SDI12_Command_TypeDef command);
/** Return Buffer Address */
uint8_t *SDI12_GetData();

#endif
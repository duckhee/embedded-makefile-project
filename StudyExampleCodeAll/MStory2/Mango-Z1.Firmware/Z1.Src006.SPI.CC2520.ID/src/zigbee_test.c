/*
 * zigbee_test.c
 */

/* includes */

#include "hw_config.h"

void ZigBee_Test(void)
{
    DEBUG_MSG_FUNC_START;

    SPIx_Init();

    halRfInit();

    printf("chipid : 0x%x\n", halRfGetChipId());
    printf("version : 0x%x\n", halRfGetChipVer());
}


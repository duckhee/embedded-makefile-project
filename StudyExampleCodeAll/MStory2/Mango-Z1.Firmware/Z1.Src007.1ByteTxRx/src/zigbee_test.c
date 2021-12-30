/*
 * zigbee_test.c
 */

/* Includes ------------------------------------------------------------------*/
#include "zigbee_test.h"
#include "hal_rf.h"
#include "hw_config.h"
#include "hal_cc2520.h"
#include "string.h"
#include "basic_rf.h"
#include "debug.h"

/***********************************************************************************
 * CONSTANTS
 */

#define KVP(v)	{ v, #v }

typedef struct {
    const uint8 iRegNum;
    const char *szRegName;
} regKvp_t;

// Application parameters
#define RF_CHANNEL                25      // 2.4 GHz RF channel

// BasicRF address definitions
#define PAN_ID               0x2007
#define TX_ADDR              0x2520
#define RX_ADDR              0xBEEF

// transmit data
#define APP_PAYLOAD_LENGTH    1

/***********************************************************************************
 * LOCAL VARIABLES
 */

static uint8 pTxData[APP_PAYLOAD_LENGTH];
static uint8 pRxData[APP_PAYLOAD_LENGTH];
static basicRfCfg_t basicRfConfig;

#ifdef SECURITY_CCM
// Security key
static uint8 key[]= {
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
};
#endif

// CC2520 SREG names
static regKvp_t regLookup_SREG[]=
{
    KVP(CC2520_CHIPID),
    KVP(CC2520_VERSION),
    KVP(CC2520_EXTCLOCK),
    KVP(CC2520_MDMCTRL0),
    KVP(CC2520_MDMCTRL1),
    KVP(CC2520_FREQEST),
    KVP(CC2520_RXCTRL),
    KVP(CC2520_FSCTRL),
    KVP(CC2520_FSCAL0),
    KVP(CC2520_FSCAL1),
    KVP(CC2520_FSCAL2),
    KVP(CC2520_FSCAL3),
    KVP(CC2520_AGCCTRL0),
    KVP(CC2520_AGCCTRL1),
    KVP(CC2520_AGCCTRL2),
    KVP(CC2520_AGCCTRL3),
    KVP(CC2520_ADCTEST0),
    KVP(CC2520_ADCTEST1),
    KVP(CC2520_ADCTEST2),
    KVP(CC2520_MDMTEST0),
    KVP(CC2520_MDMTEST1),
    KVP(CC2520_DACTEST0),
    KVP(CC2520_DACTEST1),
    KVP(CC2520_ATEST),
    KVP(CC2520_DACTEST2),
    KVP(CC2520_PTEST0),
    KVP(CC2520_PTEST1),
    KVP(CC2520_DPUBIST),
    KVP(CC2520_ACTBIST),
    KVP(CC2520_RAMBIST),
    KVP(0xFF),
};

// CC2520 FREG names
static regKvp_t regLookup_FREG[]=
{
    KVP(CC2520_FRMFILT0),
    KVP(CC2520_FRMFILT1),
    KVP(CC2520_SRCMATCH),
    KVP(CC2520_SRCSHORTEN0),
    KVP(CC2520_SRCSHORTEN1),
    KVP(CC2520_SRCSHORTEN2),
    KVP(CC2520_SRCEXTEN0),
    KVP(CC2520_SRCEXTEN1),
    KVP(CC2520_SRCEXTEN2),
    KVP(CC2520_FRMCTRL0),
    KVP(CC2520_FRMCTRL1),
    KVP(CC2520_RXENABLE0),
    KVP(CC2520_RXENABLE1),
    KVP(CC2520_EXCFLAG0),
    KVP(CC2520_EXCFLAG1),
    KVP(CC2520_EXCFLAG2),
    KVP(CC2520_EXCMASKA0),
    KVP(CC2520_EXCMASKA1),
    KVP(CC2520_EXCMASKA2),
    KVP(CC2520_EXCMASKB0),
    KVP(CC2520_EXCMASKB1),
    KVP(CC2520_EXCMASKB2),
    KVP(CC2520_EXCBINDX0),
    KVP(CC2520_EXCBINDX1),
    KVP(CC2520_EXCBINDY0),
    KVP(CC2520_EXCBINDY1),
    KVP(CC2520_GPIOCTRL0),
    KVP(CC2520_GPIOCTRL1),
    KVP(CC2520_GPIOCTRL2),
    KVP(CC2520_GPIOCTRL3),
    KVP(CC2520_GPIOCTRL4),
    KVP(CC2520_GPIOCTRL5),
    KVP(CC2520_GPIOPOLARITY),
    KVP(CC2520_GPIOCTRL),
    KVP(CC2520_DPUCON),
    KVP(CC2520_DPUSTAT),
    KVP(CC2520_FREQCTRL),
    KVP(CC2520_FREQTUNE),
    KVP(CC2520_TXPOWER),
    KVP(CC2520_TXCTRL),
    KVP(CC2520_FSMSTAT0),
    KVP(CC2520_FSMSTAT1),
    KVP(CC2520_FIFOPCTRL),
    KVP(CC2520_FSMCTRL),
    KVP(CC2520_CCACTRL0),
    KVP(CC2520_CCACTRL1),
    KVP(CC2520_RSSI),
    KVP(CC2520_RSSISTAT),
    KVP(CC2520_TXFIFO_BUF),
    KVP(CC2520_RXFIRST),
    KVP(CC2520_RXFIFOCNT),
    KVP(CC2520_TXFIFOCNT),
    KVP(0xFF),
};

#define LED_ONOFF_DELAY  50

static void led_tx_ok(void)
{
    LED_Off_All();

    LED_On_Blue();
    Delay(LED_ONOFF_DELAY);
    LED_Off_Blue();
    Delay(LED_ONOFF_DELAY);
    LED_On_Blue();
    Delay(LED_ONOFF_DELAY);
    LED_Off_Blue();
    Delay(LED_ONOFF_DELAY);
    LED_On_Blue();
}

static void led_rx_ok(void)
{
    LED_Off_All();

    LED_On_Yellow();
    Delay(LED_ONOFF_DELAY);
    LED_Off_Yellow();
    Delay(LED_ONOFF_DELAY);
    LED_On_Yellow();
    Delay(LED_ONOFF_DELAY);
    LED_Off_Yellow();
    Delay(LED_ONOFF_DELAY);
    LED_On_Yellow();
}

static void led_txrx_error(void)
{
    LED_Off_All();

    LED_On_Red();
    Delay(LED_ONOFF_DELAY);
    LED_Off_Red();
    Delay(LED_ONOFF_DELAY);
    LED_On_Red();
    Delay(LED_ONOFF_DELAY);
    LED_Off_Red();
    Delay(LED_ONOFF_DELAY);
    LED_On_Red();
}

/*********************************************************************
 * @fn      appPrintRfRegs_SREG
 * @brief   Print radio registers
 * @param   none
 * @return  none
 */
static void appPrintRfRegs_SREG(void)
{
    regKvp_t *p;
    uint16 iRegVal;

    p = regLookup_SREG;

    while ( p->iRegNum != 0xFF) {
        // Read radio registers
        iRegVal = CC2520_MEMRD8(p->iRegNum);

        // Print name and contents
        printf("0x%02X %-20s : 0x%02X\n",
               p->iRegNum, (char*)p->szRegName, iRegVal);

        p++;
    }
}

static void appPrintRfRegs_FREG(void)
{
    regKvp_t *p;
    uint16 iRegVal;

    p = regLookup_FREG;

    while ( p->iRegNum != 0xFF) {
        // Read radio registers
        iRegVal = CC2520_REGRD8(p->iRegNum);

        // Print name and contents
        printf("0x%02X %-20s : 0x%02X\n",
               p->iRegNum, (char*)p->szRegName, iRegVal);

        p++;
    }
}

/***********************************************************************************
* @fn          appLight
*
* @brief       Application code for light application. Puts MCU in endless
*              loop waiting for user input from joystick.
*
* @param       basicRfConfig - file scope variable. Basic RF configuration data
*              pRxData - file scope variable. Pointer to buffer for RX data
*
* @return      none
*/
static void appLight(void)
{
    DEBUG_MSG_FUNC_START;
    
    // Initialize BasicRF
    basicRfConfig.myAddr = RX_ADDR;
    if(basicRfInit(&basicRfConfig) == HAL_RF_FAILED) {
        DEBUG_MSG_ASSERT;
    }
    basicRfReceiveOn();

    DEBUG_MSG_FUNC_NOTIFY;

    // Main loop
    while (TRUE) {
        while(!basicRfPacketIsReady());

        DEBUG_MSG_FUNC_NOTIFY;

        if(basicRfReceive(pRxData, APP_PAYLOAD_LENGTH, NULL)>0) {
            printf("pRxData[0]: %c\n", pRxData[0]);
#ifdef DEBUG_MSG_LEVEL0
            printf("basicRfGetRssi() val: %d\n", basicRfGetRssi());
#endif
            led_rx_ok();
        }
        else
        {
            DEBUG_MSG_FUNC_ERROR;
            led_txrx_error();
        }
    }
}


/***********************************************************************************
* @fn          appSwitch
*
* @brief       Application code for switch application. Puts MCU in
*              endless loop to wait for commands from from switch
*
* @param       basicRfConfig - file scope variable. Basic RF configuration data
*              pTxData - file scope variable. Pointer to buffer for TX
*              payload
*              appState - file scope variable. Holds application state
*
* @return      none
*/
static void appSwitch(void)
{
    uint8 status;

    DEBUG_MSG_FUNC_START;

    // Initialize BasicRF
    basicRfConfig.myAddr = TX_ADDR;
    if(basicRfInit(&basicRfConfig) == HAL_RF_FAILED) {
        DEBUG_MSG_ASSERT;
    }

    // Keep Receiver off when not needed to save power
    basicRfReceiveOff();

    // Set TX output power
    CC2520_REGWR8(CC2520_TXPOWER, CC2520_TXPOWER_4_DBM);

    pTxData[0] = 'a' - 1;

    // Main loop
    while (TRUE) {
        Delay(500);
        if(pTxData[0] == 'z')
        {
            pTxData[0] = 'a';
        }
        else
        {
            pTxData[0] += 1;
        }
        printf("send data is %c\n", pTxData[0]);

        status = basicRfSendPacket(RX_ADDR, pTxData, APP_PAYLOAD_LENGTH);
        if(HAL_RF_SUCCESS != status)
        {
            DEBUG_MSG_FUNC_ERROR;
            led_txrx_error();
        }
        else
        {
            led_tx_ok();
        }

#if 0 // POOH
        // Put MCU to sleep. It will wake up on joystick interrupt
        halIntOff();
        halMcuSetLowPowerMode(HAL_MCU_LPM_3); // Will turn on global
        // interrupt enable
        halIntOn();
#endif
    }
}

void ZigBee_Test(void)
{
    u8 ch;
    int channelNum;

    DEBUG_MSG_FUNC_START;

    printf("\n- Select Channel -\n");
    printf("<a> channel 11, <b> channel 12, <c> channel 13, <d> channel 14\n");
    printf("<e> channel 15, <f> channel 16, <g> channel 17, <h> channel 18\n");
    printf("<i> channel 19, <j> channel 20, <k> channel 21, <l> channel 22\n");
    printf("<m> channel 23, <n> channel 24, <o> channel 25, <p> channel 26\n");

    ch = USART_GetCharacter(USART1);
    printf(" is selected\n");

    channelNum = MIN_CHANNEL + ((int) (ch - 'a'));
    printf("selected channel is %d\n", channelNum);
    
    if((channelNum >= MIN_CHANNEL) && (channelNum <= MAX_CHANNEL))
    {
        basicRfConfig.channel = channelNum;
    }
    else
    {
        printf("default channel is %d\n", RF_CHANNEL);
        basicRfConfig.channel = RF_CHANNEL;
    }

    // F = 2405 + 5 * (k - 11) [MHz] k ¡ô[11,26]
    printf("frequency range is from %d MHz to %d MHz\n", 2405, 2480);
    printf("selected frequency is %d MHz\n",
           2405 + 5 * (basicRfConfig.channel - MIN_CHANNEL));

    // Config basicRF
    basicRfConfig.panId = PAN_ID;

#if 1
    basicRfConfig.ackRequest = TRUE;
#else
    basicRfConfig.ackRequest = FALSE;
#endif

#ifdef SECURITY_CCM
    basicRfConfig.securityKey = key;
#endif

    SPIx_Init();

    halRfInit();

    printf("chipid : 0x%x\n", halRfGetChipId());
    printf("version : 0x%x\n", halRfGetChipVer());

    while(1)
    {
        printf("\n\n---------------------\n");
        printf("Press menu key\n");
        printf("---------------------\n");
        printf("1> Print Registers: FREG\n");
        printf("2> Print Registers: SREG\n");
        printf("---------------------\n");
        printf("3> appLight\n");
        printf("4> appSwitch\n");
        printf("---------------------\n");
        printf("x> quit\n\n");

#if 1
        ch = USART_GetCharacter(USART1);
#else
        ch = '4';
#endif

        printf(" is selected\n");

        switch((char)ch)
        {
        case '1':
            appPrintRfRegs_FREG();
            break;

        case '2':
            appPrintRfRegs_SREG();
            break;

        case '3':
            appLight();
            break;

        case '4':
            appSwitch();
            break;
        }

        if('x' == (char)ch)
        {
            break;
        }
    }
}


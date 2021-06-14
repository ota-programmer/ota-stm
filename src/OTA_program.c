#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "OTA_interface.h"
#include "OTA_private.h"
#include "OTA_config.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "USART_interface.h"
#include "STK_interface.h"
#include "FPEC_interface.h"

volatile u8 g_recieveBuffer[100]; /* Array to store the received line */
volatile u8 g_recieveCounter = 0; /* Counter for received line chars */
volatile u16 g_data[100] = {0};   /* Array to store the data of line to pass it to Flash Writer */
volatile u32 g_address;           /* Pointer to store the address in to write */

volatile boolean g_lineReceivedFlag = FALSE;  /* Flag to check if the NodeMCU finished sending a complete line */
volatile boolean g_finishReceiveFlag = FALSE; /* Flag to check if NodeMCU finished sending the code to run application code */

/* Pointer to function to run application code */
typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

void OTA_vidInit(void)
{

    RCC_vidInitSysClock();          /* Init System Clock       */
    FPEC_vidEnableClock();          /* Enable Flash Driver Clock */
    USART1_vidEnableClock();        /* Enable UART Clock         */
    GPIO_vidEnablePortClock(GPIOA); /* Enable PORTA Clock for UART pins (Rx, Tx) */

    USART1_vidInit(); /* Init USART1  */
    STK_vidInit();    /* Init SysTick */

    /* Set direction of UART Pins */
    GPIO_vidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_50MHZ_AFPP); /* A09 - Tx */
    GPIO_vidSetPinDirection(GPIOA, PIN10, INPUT_FLOATING);         /* A10 - Rx */

    /* If did not recieve any data through UART for (OTA_RECIEVE_TIMEOUT_S) seconds, the old application code will run */
    STK_vidSetIntervalSingle(OTA_RECIEVE_TIMEOUT_S * 1000000, OTA_vidRunAppCode);

    /* Enable interrupt for UART */
    NVIC_vidEnableInterrupt(NVIC_USART1);
    USART1_vidEnableRecieveInterrupt(OTA_vidCharReceived);
}

void OTA_vidRun(void)
{
    while (g_finishReceiveFlag == FALSE)
    {

        if (g_lineReceivedFlag == TRUE)
        {
            switch (g_recieveBuffer[g_recieveCounter])
            {
            case OTA_DATA_START_CHAR:
                g_recieveCounter = 0;
                STK_vidStopInterval();
                FPEC_voidEraseArea(8, 64);
                USART1_vidTransmit(OTA_READ_CONFIRM_CHAR);
                break;
            case OTA_LINE_BREAK_CHAR:
                OTA_vidParseRecord();
                g_recieveCounter = 0;
                USART1_vidTransmit(OTA_READ_CONFIRM_CHAR);
                break;
            default:
                break;
            }
            g_lineReceivedFlag = FALSE;
        }
    }
    USART1_vidDisableRecieveInterrupt();
    OTA_vidRunAppCode();
}

static void OTA_vidRunAppCode(void)
{
    *((volatile u32 *)0xE000ED08) = 0x08002000;
    addr_to_call = *(Function_t *)(0x08002004);
    addr_to_call();
}

void OTA_vidCharReceived(u8 rec)
{
    g_recieveBuffer[g_recieveCounter] = rec;
    switch (rec)
    {
    case OTA_DATA_START_CHAR:
    case OTA_LINE_BREAK_CHAR:
        g_lineReceivedFlag = TRUE;
        break;
    case OTA_DATA_END_CHAR:
        g_finishReceiveFlag = TRUE;
        break;
    default:
        g_recieveCounter++;
        break;
    }
}

static u8 getHex(u8 Copy_u8Asci)
{
    u8 Result = 0;

    /*0 ... 9*/
    if ((Copy_u8Asci >= 48) && (Copy_u8Asci <= 57))
    {
        Result = Copy_u8Asci - 48;
    }

    /*A ... F*/
    else if ((Copy_u8Asci >= 65) && (Copy_u8Asci <= 70))
    {
        Result = Copy_u8Asci - 55;
    }

    return Result;
}

static void OTA_vidParseRecord()
{
    u8 CC, i;
    u8 dataDigits[4];
    u8 dataCounter = 0;

    switch (getHex(g_recieveBuffer[8]))
    {

    case 4: /* Extended Linear Address Record: used to identify the extended linear address  */
        OTA_vidSetHighAddress();
        break;

    case 5: /* Start Linear Address Record: the address where the program starts to run      */
        break;

    case 0: /* Data Rrecord: used to record data, most records of HEX files are data records */

        /* Get Character Count */
        CC = (getHex(g_recieveBuffer[1]) << 4) | getHex(g_recieveBuffer[2]);

        /* Get low part of address */
        dataDigits[0] = getHex(g_recieveBuffer[3]);
        dataDigits[1] = getHex(g_recieveBuffer[4]);
        dataDigits[2] = getHex(g_recieveBuffer[5]);
        dataDigits[3] = getHex(g_recieveBuffer[6]);

        /* Set full address */
        g_address = g_address & 0xFFFF0000;
        g_address = g_address |
                    (dataDigits[3]) |
                    (dataDigits[2] << 4) |
                    (dataDigits[1] << 8) |
                    (dataDigits[0] << 12);

        /* Get the data of the record */
        for (i = 0; i < CC / 2; i++)
        {
            dataDigits[0] = getHex(g_recieveBuffer[4 * i + 9]);
            dataDigits[1] = getHex(g_recieveBuffer[4 * i + 10]);
            dataDigits[2] = getHex(g_recieveBuffer[4 * i + 11]);
            dataDigits[3] = getHex(g_recieveBuffer[4 * i + 12]);
            g_data[dataCounter] = (dataDigits[3] << 8) |
                                  (dataDigits[2] << 12) |
                                  (dataDigits[1] << 0) |
                                  (dataDigits[0] << 4);
            dataCounter++;
        }

        if (CC % 2 != 0)
        {
            dataDigits[0] = getHex(g_recieveBuffer[4 * (CC / 2) + 9]);
            dataDigits[1] = getHex(g_recieveBuffer[4 * (CC / 2) + 10]);
            g_data[dataCounter] = 0xFF00 | (dataDigits[0] << 4) | (dataDigits[1] << 0);
            FPEC_voidFlashWrite(g_address, (u16 *)g_data, CC / 2 + 1);
        }
        else
        {
            FPEC_voidFlashWrite(g_address, (u16 *)g_data, CC / 2);
        }

        break;
    default:
        break;
    }
}

static void OTA_vidSetHighAddress(void)
{
    g_address = (getHex(g_recieveBuffer[9]) << 28) |
                (getHex(g_recieveBuffer[10]) << 24) |
                (getHex(g_recieveBuffer[11]) << 20) |
                (getHex(g_recieveBuffer[12]) << 16);
}

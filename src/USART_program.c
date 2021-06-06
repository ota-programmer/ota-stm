/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Mar 02,   2021                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

#include "RCC_interface.h"

static void (*USART1_recieveCallback)(u8 x);

void USART1_vidInit(void)
{
    USART1->BRR = 0x341;        /* Setting up baud rate 9600 */
    SET_BIT((USART1->CR1), 2);  /* RX enable                 */
    SET_BIT((USART1->CR1), 3);  /* TX enable                 */
    SET_BIT((USART1->CR1), 13); /* USART enable              */
    USART1->SR = 0;             /* Clear status register     */
}

void USART1_vidEnableRecieveInterrupt(void (*copy_ptr)(u8 x))
{
    USART1_recieveCallback = copy_ptr;
    SET_BIT((USART1->CR1), 5); /* Enable Interrupt */
}

void USART1_vidTransmit(u8 data)
{
    USART1->DR = data;
    while ((GET_BIT(USART1->SR, 6)) == 0)
        ; /* Wait till transmission is complete */
}

void USART1_vidEnableClock(void)
{
    RCC_vidEnableClock(RCC_APB2, USART1EN);
}

void USART1_IRQHandler(void)
{

    if ((GET_BIT(USART1->SR, 5)))
    {
        /* Callback notification */
        USART1_recieveCallback(USART1->DR);
    }
}

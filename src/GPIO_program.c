/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V02                                                               */
/* Date      : Jan 19,   2021                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

#include "RCC_interface.h"

void GPIO_vidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 u8Copy_u8Mode) {

    switch (Copy_u8Port)
    {
    case GPIOA:

        /* PINS 0...7 (CRL) */
        if (Copy_u8Pin<=7) 
        {
            GPIOA_CRL &= ~ (0xF << (Copy_u8Pin * 4));
            GPIOA_CRL |= (u8Copy_u8Mode << (Copy_u8Pin*4));
        }

        /* PINS 8...15 (CRH) */
        else if (Copy_u8Pin<=15) 
        {
            Copy_u8Pin -= 8;
            GPIOA_CRH &= ~ (0xF << (Copy_u8Pin * 4));
            GPIOA_CRH |= (u8Copy_u8Mode << (Copy_u8Pin*4));
        }

        break;

    case GPIOB:

        /* PINS 0...7 (CRL) */
        if (Copy_u8Pin<=7) 
        {
            GPIOB_CRL &= ~ (0xF << (Copy_u8Pin * 4));
            GPIOB_CRL |= (u8Copy_u8Mode << (Copy_u8Pin*4));
        }

        /* PINS 8...15 (CRH) */
        else if (Copy_u8Pin<=15) 
        {
            Copy_u8Pin -= 8;
            GPIOB_CRH &= ~ (0xF << (Copy_u8Pin * 4));
            GPIOB_CRH |= (u8Copy_u8Mode << (Copy_u8Pin*4));
        }

        break;

    case GPIOC:

        /* PINS 0...7 (CRL) */
        if (Copy_u8Pin<=7) 
        {   
            GPIOC_CRL &= ~ (0xF << (Copy_u8Pin * 4));
            GPIOC_CRL |= (u8Copy_u8Mode << (Copy_u8Pin*4));
        }

        /* PINS 8...15 (CRH) */
        else if (Copy_u8Pin<=15) 
        {
            Copy_u8Pin -= 8;
            GPIOC_CRH &= ~ (0xF << (Copy_u8Pin * 4));
            GPIOC_CRH |= (u8Copy_u8Mode << (Copy_u8Pin*4));
        }

        break;
    
    default:
        break;
    }

}

void GPIO_vidEnablePortClock (u8 Copy_u8Port) {
    switch (Copy_u8Port)
    {
    case GPIOA:
        RCC_vidEnableClock(RCC_APB2 , IOPAEN);
        break;
    case GPIOB:
        RCC_vidEnableClock(RCC_APB2 , IOPBEN);
        break;
    case GPIOC:
        RCC_vidEnableClock(RCC_APB2 , IOPCEN);
        break;
    default:
        break;
    }
}

/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Jan 28,   2021                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_vidEnableInterrupt (u8 copy_u8PeripheralIndex) {

    if (copy_u8PeripheralIndex<=31) {
        NVIC_ISER0 = (1<<copy_u8PeripheralIndex);
    }

    else if (copy_u8PeripheralIndex<=63) {
        copy_u8PeripheralIndex -= 32;
        NVIC_ISER1 = (1<<copy_u8PeripheralIndex);
    }
}
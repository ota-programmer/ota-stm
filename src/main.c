/******************************************************/
/* Author    : Ahmed Hassan                           */
/* Date      : Jun 1, 2021                            */
/* Version   : V01                                    */
/******************************************************/

#include "OTA_interface.h"

void main (void) {

    OTA_vidInit();
    OTA_vidRun();

    while (1);
}

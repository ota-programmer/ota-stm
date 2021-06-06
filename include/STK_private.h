/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Jan 30,   2021                                                    */
/*********************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


#define STK_CTRL     *((volatile u32*)0xE000E010)
#define STK_LOAD     *((volatile u32*)0xE000E014)
#define STK_VAL      *((volatile u32*)0xE000E018)
#define STK_CALIB    *((volatile u32*)0xE000E01C)


#define     STK_SRC_AHB            0
#define     STK_SRC_AHB_8          1

#define     STK_SINGLE_INTERVAL    0
#define     STK_PERIOD_INTERVAL    1


#endif

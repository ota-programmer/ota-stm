/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Jan 30,   2021                                                    */
/*********************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


void STK_vidInit                (void);
void STK_vidStopInterval        (void);
void STK_vidSetIntervalSingle   ( u32 copy_u32Ticks, void (*copy_ptr)(void) );

#endif
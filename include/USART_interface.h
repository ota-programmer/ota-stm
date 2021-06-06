/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Mar 02,   2021                                                    */
/*********************************************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void USART1_vidInit (void);
void USART1_vidTransmit(u8 data);
void USART1_vidEnableClock(void);
void USART1_vidEnableRecieveInterrupt(void (*copy_ptr)(u8 x));
#endif

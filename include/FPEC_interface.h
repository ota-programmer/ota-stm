/******************************************************/
/* Author    : Ahmed Hassan                           */
/* Date      : Jun 1, 2021                            */
/* Version   : V01                                    */
/******************************************************/

#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H

void FPEC_voidEraseArea(u8 copy_u8StartPage, u8 copy_u8EndPage);
void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber);
void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);
void FPEC_vidEnableClock(void);

#endif

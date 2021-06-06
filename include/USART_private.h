/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Mar 02,   2021                                                    */
/*********************************************************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct {
    volatile u32 SR     ;
    volatile u32 DR     ;
    volatile u32 BRR    ;
    volatile u32 CR1    ;
    volatile u32 CR2    ;
    volatile u32 CR3    ;
    volatile u32 GTPR   ;
} USART_registers;

#define USART1   ((USART_registers*)(0x40013800))
#define USART2   ((USART_registers*)(0x40004400))
#define USART3   ((USART_registers*)(0x40004800))


#define USART_PARITTY_CONTROL_ENABLED  1
#define USART_PARITTY_CONTROL_DISABLED 0

#define USART_EVEN_PARITY 0
#define USART_ODD_PARITY 1

#define USART_FIRST_CLOCK_FIRST_CAPTURE  1
#define USART_SECOND_CLOCK_FIRST_CAPTURE 0

#define USART_CLK_1_WHEN_IDLE 1
#define USART_CLK_0_WHEN_IDLE 0

#define USART_1_STOP_BIT 0
#define USART_0_5_STOP_BIT 1
#define USART_2_STOP_BIT 2
#define USART_1_5_STOP_BIT 3

#define USART_1_CLOCK_ENABLED 1
#define USART_1_CLOCK_DISABLED 0


#endif

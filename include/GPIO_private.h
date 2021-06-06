/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Jan 19,   2021                                                    */
/*********************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/* PORTA Registers */
#define GPIOA_CRL                 *((volatile u32*)(0x40010800))
#define GPIOA_CRH                 *((volatile u32*)(0x40010804))
#define GPIOA_IDR                 *((volatile u32*)(0x40010808))
#define GPIOA_ODR                 *((volatile u32*)(0x4001080c))
#define GPIOA_BSRR                *((volatile u32*)(0x40010810))
#define GPIOA_BRR                 *((volatile u32*)(0x40010814))
#define GPIOA_LCKR                *((volatile u32*)(0x40010818))

/* PORTB Registers */
#define GPIOB_CRL                 *((volatile u32*)(0x40010C00))
#define GPIOB_CRH                 *((volatile u32*)(0x40010C04))
#define GPIOB_IDR                 *((volatile u32*)(0x40010C08))
#define GPIOB_ODR                 *((volatile u32*)(0x40010C0c))
#define GPIOB_BSRR                *((volatile u32*)(0x40010C10))
#define GPIOB_BRR                 *((volatile u32*)(0x40010C14))
#define GPIOB_LCKR                *((volatile u32*)(0x40010C18))

/* PORTC Registers */
#define GPIOC_CRL                 *((volatile u32*)(0x40011000))
#define GPIOC_CRH                 *((volatile u32*)(0x40011004))
#define GPIOC_IDR                 *((volatile u32*)(0x40011008))
#define GPIOC_ODR                 *((volatile u32*)(0x4001100c))
#define GPIOC_BSRR                *((volatile u32*)(0x40011010))
#define GPIOC_BRR                 *((volatile u32*)(0x40011014))
#define GPIOC_LCKR                *((volatile u32*)(0x40011018))


#endif
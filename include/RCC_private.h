/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V02                                                               */
/* Date      : Feb 19,   2021                                                    */
/*********************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/* Register Definitions */
#define RCC_CR         *((volatile u32*)0x40021000)
#define RCC_CFGR       *((volatile u32*)0x40021004)
#define RCC_CIR        *((volatile u32*)0x40021008)
#define RCC_APB2RSTR   *((volatile u32*)0x4002100C)
#define RCC_APB1RSTR   *((volatile u32*)0x40021010)
#define RCC_AHBENR     *((volatile u32*)0x40021014)
#define RCC_APB2ENR    *((volatile u32*)0x40021018)
#define RCC_APB1ENR    *((volatile u32*)0x4002101C)
#define RCC_BDCR       *((uvolatileu32*)0x40021020)
#define RCC_CSR        *((volatile u32*)0x40021024)

/* Bits */
#define HSIRDY                1
#define HSERDY                17
#define PLLRDY                25
#define PLLXTPRE              17
#define PLLSRC                16

/* Clock Types */
#define RCC_HSE_CRYSTAL       0
#define RCC_HSE_RC            1
#define RCC_HSI               2
#define RCC_PLL               3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2


#define RCC_SYSCLK_DIVIDED_1     0b0001
#define RCC_SYSCLK_DIVIDED_2     0b1000
#define RCC_SYSCLK_DIVIDED_4     0b1001
#define RCC_SYSCLK_DIVIDED_8     0b1010
#define RCC_SYSCLK_DIVIDED_16    0b1011
#define RCC_SYSCLK_DIVIDED_64    0b1100
#define RCC_SYSCLK_DIVIDED_128   0b1101
#define RCC_SYSCLK_DIVIDED_256   0b1110
#define RCC_SYSCLK_DIVIDED_512   0b1111

#define RCC_HCLK_DIVIDED_1       0b001
#define RCC_HCLK_DIVIDED_2       0b100
#define RCC_HCLK_DIVIDED_4       0b101
#define RCC_HCLK_DIVIDED_8       0b110
#define RCC_HCLK_DIVIDED_16      0b111






#endif

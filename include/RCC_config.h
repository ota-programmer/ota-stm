/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V02                                                               */
/* Date      : Feb 19,   2021                                                    */
/*********************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

#define RCC_HSI_FREQ    8000000
#define RCC_HSE_FREQ    8000000

#define RCC_CLOCK_TYPE          RCC_HSI
#define RCC_AHB_PRESCALER       RCC_SYSCLK_DIVIDED_1
#define RCC_APB1_PRESCALER      RCC_HCLK_DIVIDED_1
#define RCC_APB2_PRESCALER      RCC_HCLK_DIVIDED_1

#if RCC_CLOCK_TYPE == RCC_PLL
    #define RCC_PLL_INPUT       RCC_PLL_IN_HSE_DIV_2
    #define RCC_PLL_MUL_VAL     4
#endif

/* 
--> Options for (RCC_CLOCK_TYPE):    
        RCC_HSE_CRYSTAL
        RCC_HSE_RC
        RCC_HSI
        RCC_PLL
-----------------------------------------------------------------------
--> Options for (RCC_AHB_PRESCALER):
        RCC_SYSCLK_DIVIDED_1
        RCC_SYSCLK_DIVIDED_2
        RCC_SYSCLK_DIVIDED_4
        RCC_SYSCLK_DIVIDED_8
        RCC_SYSCLK_DIVIDED_16
        RCC_SYSCLK_DIVIDED_64
        RCC_SYSCLK_DIVIDED_128
        RCC_SYSCLK_DIVIDED_256
        RCC_SYSCLK_DIVIDED_512
-----------------------------------------------------------------------
--> Options for (RCC_APB1_PRESCALER) , (RCC_APB2_PRESCALER):
        RCC_HCLK_DIVIDED_1
        RCC_HCLK_DIVIDED_2
        RCC_HCLK_DIVIDED_4
        RCC_HCLK_DIVIDED_8
        RCC_HCLK_DIVIDED_16
-----------------------------------------------------------------------
--> Options for (RCC_PLL_INPUT):     
        RCC_PLL_IN_HSI_DIV_2
        RCC_PLL_IN_HSE_DIV_2
        RCC_PLL_IN_HSE      
-----------------------------------------------------------------------
--> Options for (RCC_PLL_MUL_VAL):     
        2, 3, 4, ...... , 16   
-----------------------------------------------------------------------
--> Note:
        (RCC_PLL_INPUT), (RCC_PLL_MUL_VAL) are used 
        only if you have PLL as input clock source.
*/



#endif

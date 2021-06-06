/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V02                                                               */
/* Date      : Feb 19,   2021                                                    */
/*********************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void RCC_vidInitSysClock        ( void );
void RCC_vidEnableClock         ( u8 copy_u8BusId      , u8 copy_u8PeriheralId );

/*
-----------------------------------------------------------------------
--> copy_u8BusId Options:
    RCC_AHB
    RCC_APB1
    RCC_APB2
-----------------------------------------------------------------------
--> copy_u8BusSource Options:
    RCC_AHB
    RCC_APB1
    RCC_APB2
    RCC_SYSCLK
-----------------------------------------------------------------------
--> copy_u8PeriheralId options for RCC_AHB
        SDIOEN:     SDIO clock enable
        FSMCEN:     FSMC clock enable
        CRCEN:      CRC clock enable
        FLITFEN:    FLITF clock enable
        SRAMEN:     SRAM interface clock enable
        DMA2EN:     DMA2 clock enable
        DMA1EN:     DMA1 clock enable
-----------------------------------------------------------------------
--> copy_u8PeriheralId options for RCC_APB1
        DACEN:      DAC interface clock enable
        PWREN:      Power interface clock enable
        BKPEN:      Backup interface clock enable
        CANEN:      CAN clock enable
        USBEN:      USB clock enable
        I2C2EN:     I2C 2 clock enable
        I2C1EN:     I2C 1 clock enable
        UART5EN:    USART 5 clock enable
        UART4EN:    USART 4 clock enable
        USART3EN:   USART 3 clock enable
        USART2EN:   USART 2 clock enable
        SPI3EN:     SPI 3 clock enable
        SPI2EN:     SPI 2 clock enable
        WWDGEN:     Window watchdog clock enable
        TIM14EN:    Timer 14 clock enable
        TIM13EN:    Timer 13 clock enable
        TIM12EN:    Timer 12 clock enable
        TIM7EN:     Timer 7 clock enable
        TIM6EN:     Timer 6 clock enable
        TIM5EN:     Timer 5 clock enable
        TIM4EN:     Timer 4 clock enable
        TIM3EN:     Timer 3 clock enable
        TIM2EN:     Timer 2 clock enable
-----------------------------------------------------------------------
--> copy_u8PeriheralId options for RCC_APB2
        TIM11EN:    TIM11 timer clock enable
        TIM10EN:    TIM10 timer clock enable
        TIM9EN:     TIM9 timer clock enable
        ADC3EN:     ADC3 interface clock enable
        USART1EN:   USART1 clock enable
        TIM8EN:     TIM8 Timer clock enable
        SPI1EN:     SPI 1 clock enable
        TIM1EN:     TIM1 Timer clock enable
        ADC2EN:     ADC 2 interface clock enable
        ADC1EN:     ADC 1 interface clock enable
        IOPCEN:     I/O port C clock enable
        IOPBEN:     I/O port B clock enable
        IOPAEN:     I/O port A clock enable
        AFIOEN:     Alternate function I/O clock enable
-----------------------------------------------------------------------
*/

/*         Bus          */
#define RCC_AHB         0 
#define RCC_APB1        1
#define RCC_APB2        2
#define RCC_SYSCLK      3

/*         AHB          */
#define SDIOEN          10
#define FSMCEN          8
#define CRCEN           6
#define FLITFEN         4
#define SRAMEN          2
#define DMA2EN          1
#define DMA1EN          0


/*         APB1         */
#define DACEN           29
#define PWREN           28
#define BKPEN           27
#define CANEN           25
#define USBEN           23
#define I2C2EN          22
#define I2C1EN          21
#define UART5EN         20 
#define UART4EN         19
#define USART3EN        18
#define USART2EN        17
#define SPI3EN          15
#define SPI2EN          14
#define WWDGEN          11
#define TIM14EN         8
#define TIM13EN         7
#define TIM12EN         6
#define TIM7EN          5
#define TIM6EN          4
#define TIM5EN          3
#define TIM4EN          2
#define TIM3EN          1
#define TIM2EN          0

/*         APB2         */
#define TIM11EN         21
#define TIM10EN         20
#define TIM9EN          19
#define ADC3EN          15
#define USART1EN        14
#define TIM8EN          13
#define SPI1EN          12
#define TIM1EN          11
#define ADC2EN          10
#define ADC1EN          9
#define IOPCEN          4
#define IOPBEN          3
#define IOPAEN          2
#define AFIOEN          0


#endif

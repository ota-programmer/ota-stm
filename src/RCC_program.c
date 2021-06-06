/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V02                                                               */
/* Date      : Feb 19,   2021                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_vidInitSysClock(void)
{
	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; /* Enable HSE with no bypass : HSEON = 1, HSEBYP = 0		*/
		RCC_CFGR = 0x00000001; /* HSE selected as system clock : SW = 01				*/
		/*Wait until HSE ready*/
		while (!GET_BIT(RCC_CR, HSERDY));

		
	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /* Enable HSE with bypass : HSEON = 1, HSEBYP = 1 		*/
		RCC_CFGR = 0x00000001; /* HSE selected as system clock : SW = 01 				*/
		/*Wait until HSE ready*/
		while (!GET_BIT(RCC_CR, HSERDY));

	#elif   RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 : HSION = 1, HSITRIM = 10000 */
		RCC_CFGR = 0x00000000; /* HSI selected as system clock : SW = 00 				 */
		/*Wait until HSI ready*/
		while (!GET_BIT(RCC_CR, HSIRDY));

	#elif   RCC_CLOCK_TYPE == RCC_PLL
		RCC_CR   = 0x00000000;
		RCC_CFGR = 0x00000002; /* PLL selected as system clock : SW = 11 				 */
		RCC_CFGR |= (RCC_PLL_MUL_VAL-2)<<18; /* PLL multiplication factor 				 */
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			CLR_BIT(RCC_CFGR, PLLSRC);
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			SET_BIT(RCC_CFGR, PLLSRC);
			SET_BIT(RCC_CFGR, PLLXTPRE);
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			SET_BIT(RCC_CFGR, PLLSRC);
			CLR_BIT(RCC_CFGR, PLLXTPRE);
		#else
			#error("WRONG PLL INPUT")
		#endif
		RCC_CR   = 0x01000000; /* Enable PLL : PLLON = 1*/

	
	#else
		#error("WRONG CLOCK TYPE")
	#endif

	/* Configure AHB presaler */
	RCC_CFGR |= (RCC_AHB_PRESCALER << 4);

	/* Configure APB1 presaler */
	RCC_CFGR |= (RCC_APB1_PRESCALER << 8);

	/* Configure APB2 presaler */
	RCC_CFGR |= (RCC_APB2_PRESCALER << 11);

}

void RCC_vidEnableClock (u8 copy_u8BusId, u8 copy_u8PeriheralId)
{
	if (copy_u8PeriheralId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,copy_u8PeriheralId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,copy_u8PeriheralId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,copy_u8PeriheralId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}


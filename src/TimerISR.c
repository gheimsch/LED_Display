/******************************************************************************/
/*! \file TimerISR.c
******************************************************************************
* \brief Library function for the interrupt
*
* Procedures : initISR()
*
* \author meert1,heimg1
*
* \version 0.0.1
*
* \history 14.03.2014 File Created
*
*/
/* ****************************************************************************/
/* LED_Display */
/* ****************************************************************************/

/* --------------------------------- imports ---------------------------------*/
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_TIM.h"

/* ------------------------- module data declaration -------------------------*/
#define FIRSTPORTBIT 10
#define NUMBEROFBIT 4
#define ROWNUMB 16

unsigned char bit = 0;
unsigned char row = ROWNUMB-1;
unsigned char bitpos = NUMBEROFBIT-1;
int Width = 0;
int Height = 0;
volatile uint32_t Data = 0;
volatile uint16_t *Buffer = 0;

/* ****************************************************************************/
/* End Header : TimerISR.c */
/* ****************************************************************************/

/* Function to init the interrupt */
void initISR(int width, int height, uint16_t *dataPtr) {

	Width = width;
	Height = height;
	Buffer = dataPtr;
	TIM_TimeBaseInitTypeDef TIM_TimeBase_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBase_InitStructure.TIM_Period = (SystemCoreClock/20000)-1;
	TIM_TimeBase_InitStructure.TIM_Prescaler = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBase_InitStructure);

	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_Init(&NVIC_InitStructure);

	TIM_Cmd(TIM2, ENABLE);
}


/******************************************************************************/
/* Function: TIM2_IRQHandler */
/******************************************************************************/
/*! \brief Timer2 IRQ handler
*
* \author meert1,heimg1
*
* \version 0.0.1
*
* \date 03.04.2014 File Created
*
*******************************************************************************/
void TIM2_IRQHandler(void){

	/*Clear the interrupt bit*/
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update );

	GPIO_WriteBit(GPIOB,GPIO_Pin_1,Bit_RESET);

	/*Set EN to low (zero active)*/
	GPIO_WriteBit(GPIOB, GPIO_Pin_14, Bit_SET);
	/*Set Latch to high*/
	GPIO_WriteBit(GPIOB, GPIO_Pin_13, Bit_SET);

	/*Increment the bitposition for the BCM*/
	if (++bitpos >= NUMBEROFBIT) {
		bitpos = 0;
		/*Increment the row number*/
		if (++row >= ROWNUMB) {
			row = 0;
		}
		/*Change the current row address*/
	} else if (bitpos == 1) {
		GPIO_Write(GPIOD, (row & 0x0F));
	}

	//Change duration of the ISR
	TIM2 ->ARR = ((SystemCoreClock / 20000) - 1) << bitpos;
	//Set ISR counter to zero
	TIM2 ->CNT = 0;

	/*Set Latch to low*/
	GPIO_WriteBit(GPIOB, GPIO_Pin_13, Bit_RESET);
	/*Set EN to high (zero active)*/
	GPIO_WriteBit(GPIOB, GPIO_Pin_14, Bit_RESET);

	/*Mask out the data from the buffer and write the data to the port for each bit-position */
//	if (bitpos == 0) {
//		for (bit = 0; bit < (32*Width); bit++) {
//			Data = (Data & ~0x3F)
//					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x010) >> 1)
//					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x200) >> 5)
//					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x4000) >> 9)
//					| ((Buffer[bit + (row) * (32*Width)] & 0x010) >> 4)
//					| ((Buffer[bit + (row) * (32*Width)] & 0x200) >> 8)
//					| ((Buffer[bit + (row) * (32*Width)] & 0x4000) >> 12);
//			GPIOE ->ODR = (GPIOE ->ODR & ~(0x03F << FIRSTPORTBIT))
//					| (Data << FIRSTPORTBIT);
//			GPIOE ->BSRRH = GPIO_Pin_9 ;
//			GPIOE ->BSRRL = GPIO_Pin_9;
//		}
//	} else
	if (bitpos == 0) {
		for (bit = 0; bit < (32*Width); bit++) {
			Data = (Data & ~0x3F) | ((Buffer[bit + (row + 16) * (32*Width)] & 0x08))
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x100) >> 4)
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x2000) >> 8)
					| ((Buffer[bit + (row) * (32*Width)] & 0x08) >> 3)
					| ((Buffer[bit + (row) * (32*Width)] & 0x100) >> 7)
					| ((Buffer[bit + (row) * (32*Width)] & 0x2000) >> 11);
			GPIOE ->ODR = (GPIOE ->ODR & ~(0x03F << FIRSTPORTBIT))
					| (Data << FIRSTPORTBIT);
			GPIOE ->BSRRH = GPIO_Pin_9 ;
			GPIOE ->BSRRL = GPIO_Pin_9;
		}
	} else if (bitpos == 1) {
		for (bit = 0; bit < (32*Width); bit++) {

			Data = (Data & ~0x3F)
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x04) << 1)
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x80) >> 3)
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x1000) >> 7)
					| ((Buffer[bit + (row) * (32*Width)] & 0x04) >> 2)
					| ((Buffer[bit + (row) * (32*Width)] & 0x80) >> 6)
					| ((Buffer[bit + (row) * (32*Width)] & 0x1000) >> 10);
			GPIOE ->ODR = (GPIOE ->ODR & ~(0x03F << FIRSTPORTBIT))
					| (Data << FIRSTPORTBIT);
			GPIOE ->BSRRH = GPIO_Pin_9 ;
			GPIOE ->BSRRL = GPIO_Pin_9;
		}
	} else if (bitpos == 2) {
		for (bit = 0; bit < (32*Width); bit++) {

			Data = (Data & ~0x3F)
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x02) << 2)
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x40) >> 2)
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x800) >> 6)
					| ((Buffer[bit + (row) * (32*Width)] & 0x02) >> 1)
					| ((Buffer[bit + (row) * (32*Width)] & 0x40) >> 5)
					| ((Buffer[bit + (row) * (32*Width)] & 0x800) >> 9);
			GPIOE ->ODR = (GPIOE ->ODR & ~(0x03F << FIRSTPORTBIT))
					| (Data << FIRSTPORTBIT);
			GPIOE ->BSRRH = GPIO_Pin_9 ;
			GPIOE ->BSRRL = GPIO_Pin_9;
		}
	} else if (bitpos == 3) {
		for (bit = 0; bit < (32*Width); bit++) {

			Data = (Data & ~0x3F)
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x01) << 3)
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x20) >> 1)
					| ((Buffer[bit + (row + 16) * (32*Width)] & 0x400) >> 5)
					| ((Buffer[bit + (row) * (32*Width)] & 0x01))
					| ((Buffer[bit + (row) * (32*Width)] & 0x20) >> 4)
					| ((Buffer[bit + (row) * (32*Width)] & 0x400) >> 8);
			GPIOE ->ODR = (GPIOE ->ODR & ~(0x03F << FIRSTPORTBIT))
					| (Data << FIRSTPORTBIT);
			GPIOE ->BSRRH = GPIO_Pin_9 ;
			GPIOE ->BSRRL = GPIO_Pin_9;
		}
	}

}
/* ****************************************************************************/
/* End : TIM2_IRQHandler */
/* ****************************************************************************/

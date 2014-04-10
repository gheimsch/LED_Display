/******************************************************************************/
/*! \file Main.c
******************************************************************************
* \brief Short description of the files function
*
* Function : More detailed description of the files function
*
* Procedures :
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
#include <stdint.h>
#include "stm32f4xx.h"
#include "GPIO.h"
#include "stm32f4xx_TIM.h"
#include "TimerISR.h"
#include "Gamma.h"
/* --------------------------------- defines ---------------------------------*/
#define FIRSTPORTBIT 10
#define NUMBEROFBIT 4
#define ROWNUMB 16
/* ------------------------- module data declaration -------------------------*/
uint16_t Buffer[1024] = {0x00};// 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
//		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
//		0x4200, 0x7FE0, 0x7FE0, 0x7FE0, 0x4200, 0x0000, 0x0000, 0x0000, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FE0, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FE0, 0x7FE0, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x0000, 0x7FE0, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FE0, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x6318,
//		0x7FFF, 0x7FFF, 0x6318, 0x7FFF, 0x7FFF, 0x7FFF, 0x4200, 0x0000, 0x7FE0,
//		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x4210, 0x6318, 0x6318, 0x6318,
//		0x6318, 0x6318, 0x0000, 0x7FE0, 0x7FFF, 0x7FE0, 0x0000, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FE0, 0x7FE0, 0x7FE0,
//		0x7FE0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FE0, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FE0, 0x7FE0, 0x6318,
//		0x0000, 0x7FE0, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FE0, 0x0000, 0x0000,
//		0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
//		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FE0, 0x0000, 0x0010, 0x0010, 0x0000, 0x0000,
//		0x7FFF, 0x6318, 0x7FFF, 0x7FFF, 0x7FE0, 0x0000, 0x0000, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FE0, 0x7FFF, 0x7FFF,
//		0x6318, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x0000, 0x0010, 0x0010, 0x0000, 0x4210, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x4210, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0010, 0x0010, 0x0000,
//		0x7FFF, 0x6318, 0x6318, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0010, 0x0000,
//		0x7FFF, 0x0000, 0x4200, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x0000,
//		0x0000, 0x6318, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x0000, 0x0010, 0x0010, 0x0000, 0x6318, 0x7FFF, 0x6318, 0x0000,
//		0x0000, 0x0010, 0x0010, 0x0010, 0x0000, 0x0000, 0x4200, 0x7FE0, 0x0000,
//		0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x0000, 0x0000, 0x4210, 0x7FFF, 0x0000,
//		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0010, 0x0000,
//		0x0000, 0x6318, 0x6318, 0x0000, 0x0000, 0x0010, 0x0010, 0x0010, 0x0010,
//		0x0010, 0x0000, 0x7FE0, 0x7FFF, 0x4200, 0x0000, 0x7FFF, 0x0000, 0x7FFF,
//		0x0000, 0x0000, 0x6318, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x0000, 0x0010, 0x0000, 0x4210, 0x4210, 0x0000, 0x0010,
//		0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0000, 0x7FE0, 0x7FFF,
//		0x4200, 0x0000, 0x7FFF, 0x0000, 0x7FFF, 0x0000, 0x0000, 0x4210, 0x7FFF,
//		0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0010,
//		0x001F, 0x0010, 0x0010, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
//		0x0010, 0x0010, 0x0000, 0x4210, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x0000,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x6318, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0010, 0x001F, 0x001F, 0x001F, 0x001F,
//		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0010, 0x0000,
//		0x6318, 0x6318, 0x0000, 0x7FFF, 0x0000, 0x6318, 0x7FFF, 0x7FFF, 0x0000,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0010,
//		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
//		0x001F, 0x001F, 0x001F, 0x0000, 0x0000, 0x4210, 0x7FFF, 0x0000, 0x7FFF,
//		0x7FFF, 0x0000, 0x6318, 0x7FFF, 0x6318, 0x0000, 0x6318, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x6318, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
//		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000,
//		0x4210, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x6318,
//		0x6318, 0x4210, 0x0000, 0x6318, 0x6318, 0x6318, 0x0000, 0x0000, 0x001F,
//		0x001F, 0x001F, 0x03FF, 0x0210, 0x03FF, 0x0210, 0x03FF, 0x0210, 0x03FF,
//		0x0210, 0x001F, 0x001F, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x6318, 0x0000,
//		0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
//		0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x03FF, 0x03FF, 0x03FF,
//		0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x0210, 0x0210, 0x0000,
//		0x0000, 0x7FFF, 0x7FFF, 0x6318, 0x0000, 0x7FFF, 0x0000, 0x7FE0, 0x7FE0,
//		0x7FE0, 0x7FE0, 0x7FE0, 0x7FE0, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F,
//		0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x7FFF, 0x7FFF, 0x7FFF, 0x03FF,
//		0x03FF, 0x03FF, 0x0210, 0x0000, 0x0000, 0x0000, 0x6318, 0x7FFF, 0x0000,
//		0x7FFF, 0x7FFF, 0x0000, 0x7FE0, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x0000, 0x0000, 0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x03FF, 0x03FF, 0x0210, 0x0000,
//		0x7FFF, 0x7FFF, 0x0000, 0x6318, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
//		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FE0, 0x7FE0, 0x0000, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x03FF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FE0, 0x0000, 0x0000,
//		0x0000, 0x7FE0, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x6318, 0x0000,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x0000, 0x7FE0, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x6318,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x6318, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x0000, 0x6318, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x6318, 0x0000, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x6318, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
//		0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x6318, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x6318, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
//		0x7FFF};

unsigned char Reverse5Bit[32] = { 0x00, 0x10, 0x08, 0x18, 0x04, 0x14, 0x0C, 0x1C,
		0x02, 0x12, 0x0A, 0x1A, 0x06, 0x16, 0x0E, 0x1E, 0x01, 0x11, 0x09, 0x19, 0x05,
		0x15, 0x0D, 0x1D, 0x03, 0x13, 0x0B, 0x1B, 0x07, 0x17, 0x0F, 0x1F };

unsigned char bit = 0;
unsigned char row = ROWNUMB-1;
unsigned char bitpos = NUMBEROFBIT-1;
volatile uint32_t Data = 0;
uint16_t color = 0;
/* ----------------------- module procedure declaration ----------------------*/
extern "C" void TIM2_IRQHandler(void);

/* ****************************************************************************/
/* End Header : Main.c */
/* ****************************************************************************/

/******************************************************************************/
/* Function: Delay_us */
/******************************************************************************/
/*! \brief Delay in microseconds
*
* \param[in] microseconds
*
* \author meert1,heimg1
*
* \version 0.0.1
*
* \date 03.04.2014 File Created
*
*******************************************************************************/
void Delay_us(unsigned int us)
{
 unsigned int temp;
 SysTick->LOAD = us * 11;
 SysTick->VAL = 0x00;
 SysTick->CTRL = 0x01 ;
 do
 {
  temp=SysTick->CTRL;

 }while(temp&0x01&&!(temp&(1<<16)));
 SysTick->CTRL = 0x00;
 SysTick->VAL = 0X00;
}
/* ****************************************************************************/
/* End : Delay_us */
/* ****************************************************************************/

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
//		for (bit = 0; bit < 32; bit++) {
//			Data = (Data & ~0x3F)
//					| ((Buffer[bit + (row + 16) * 32] & 0x010) >> 1)
//					| ((Buffer[bit + (row + 16) * 32] & 0x200) >> 5)
//					| ((Buffer[bit + (row + 16) * 32] & 0x4000) >> 9)
//					| ((Buffer[bit + (row) * 32] & 0x010) >> 4)
//					| ((Buffer[bit + (row) * 32] & 0x200) >> 8)
//					| ((Buffer[bit + (row) * 32] & 0x4000) >> 12);
//			GPIOE ->ODR = (GPIOE ->ODR & ~(0x03F << FIRSTPORTBIT))
//					| (Data << FIRSTPORTBIT);
//			GPIOE ->BSRRH = GPIO_Pin_9 ;
//			GPIOE ->BSRRL = GPIO_Pin_9;
//		}
//	} else
	if (bitpos == 0) {
		for (bit = 0; bit < 32; bit++) {
			Data = (Data & ~0x3F) | ((Buffer[bit + (row + 16) * 32] & 0x08))
					| ((Buffer[bit + (row + 16) * 32] & 0x100) >> 4)
					| ((Buffer[bit + (row + 16) * 32] & 0x2000) >> 8)
					| ((Buffer[bit + (row) * 32] & 0x08) >> 3)
					| ((Buffer[bit + (row) * 32] & 0x100) >> 7)
					| ((Buffer[bit + (row) * 32] & 0x2000) >> 11);
			GPIOE ->ODR = (GPIOE ->ODR & ~(0x03F << FIRSTPORTBIT))
					| (Data << FIRSTPORTBIT);
			GPIOE ->BSRRH = GPIO_Pin_9 ;
			GPIOE ->BSRRL = GPIO_Pin_9;
		}
	} else if (bitpos == 1) {
		for (bit = 0; bit < 32; bit++) {

			Data = (Data & ~0x3F)
					| ((Buffer[bit + (row + 16) * 32] & 0x04) << 1)
					| ((Buffer[bit + (row + 16) * 32] & 0x80) >> 3)
					| ((Buffer[bit + (row + 16) * 32] & 0x1000) >> 7)
					| ((Buffer[bit + (row) * 32] & 0x04) >> 2)
					| ((Buffer[bit + (row) * 32] & 0x80) >> 6)
					| ((Buffer[bit + (row) * 32] & 0x1000) >> 10);
			GPIOE ->ODR = (GPIOE ->ODR & ~(0x03F << FIRSTPORTBIT))
					| (Data << FIRSTPORTBIT);
			GPIOE ->BSRRH = GPIO_Pin_9 ;
			GPIOE ->BSRRL = GPIO_Pin_9;
		}
	} else if (bitpos == 2) {
		for (bit = 0; bit < 32; bit++) {

			Data = (Data & ~0x3F)
					| ((Buffer[bit + (row + 16) * 32] & 0x02) << 2)
					| ((Buffer[bit + (row + 16) * 32] & 0x40) >> 2)
					| ((Buffer[bit + (row + 16) * 32] & 0x800) >> 6)
					| ((Buffer[bit + (row) * 32] & 0x02) >> 1)
					| ((Buffer[bit + (row) * 32] & 0x40) >> 5)
					| ((Buffer[bit + (row) * 32] & 0x800) >> 9);
			GPIOE ->ODR = (GPIOE ->ODR & ~(0x03F << FIRSTPORTBIT))
					| (Data << FIRSTPORTBIT);
			GPIOE ->BSRRH = GPIO_Pin_9 ;
			GPIOE ->BSRRL = GPIO_Pin_9;
		}
	} else if (bitpos == 3) {
		for (bit = 0; bit < 32; bit++) {

			Data = (Data & ~0x3F)
					| ((Buffer[bit + (row + 16) * 32] & 0x01) << 3)
					| ((Buffer[bit + (row + 16) * 32] & 0x20) >> 1)
					| ((Buffer[bit + (row + 16) * 32] & 0x400) >> 5)
					| ((Buffer[bit + (row) * 32] & 0x01))
					| ((Buffer[bit + (row) * 32] & 0x20) >> 4)
					| ((Buffer[bit + (row) * 32] & 0x400) >> 8);
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

/******************************************************************************/
/* Function: setColor */
/******************************************************************************/
/*! \brief Convert and set a 888 color to a 555 color
*
* \param[in] parameter1 8bit red value
* \param[in] parameter2 8bit green value
* \param[in] parameter2 8bit blue value
*
* \return 16bit value with the color
*
* \author meert1,heimg1
*
* \version 0.0.1
*
* \date 03.04.2014 File Created
*
*******************************************************************************/
uint16_t setColor(unsigned char R,unsigned char G,unsigned char B){
	unsigned char red = R>>3;
	unsigned char green = G>>3;
	unsigned char blue = B>>3;
	return (((Reverse5Bit[red]) | ((Reverse5Bit[green]) << 5)
				| ((Reverse5Bit[blue]) << 10)));
}
/* ****************************************************************************/
/* End : setColor */
/* ****************************************************************************/

/******************************************************************************/
/* Function: setPixel */
/******************************************************************************/
/*! \brief set the desired pixel in the color col
*
* \param[in] parameter1 x coordinate
* \param[in] parameter2 y coordinate
* \param[in] parameter3 16bit color value(BGR)
*
* \return none
*
* \author meert1,heimg1
*
* \version 0.0.1
*
* \date 03.04.2014 File Created
*
*******************************************************************************/
void setPixel(int x,int y,uint16_t col){
	Buffer[x+32*y] = col;
}
/* ****************************************************************************/
/* End : SetPixel */
/* ****************************************************************************/

/******************************************************************************/
/* Function: main */
/******************************************************************************/
/*! \brief main routine
*
* \return none
*
* \author meert1,heimg1
*
* \version 0.0.1
*
* \date 03.04.2014 File Created
*
*******************************************************************************/
int main(void)
{

	initGPIO();
	initISR();
	GPIO_WriteBit(GPIOB,GPIO_Pin_14,Bit_SET);		//Enabel auf null
	GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_RESET);		//Lat auf null

    while(1)
    {
    	setPixel(0,0,setColor(0x00,0x00,0x80));
    	setPixel(0,1,setColor(0x00,0x00,0xFF));
    	setPixel(0,2,setColor(0x00,0x80,0x00));
    	setPixel(0,3,setColor(0x00,0x80,0x80));
    	setPixel(0,4,setColor(0x00,0xFF,0x00));
    	setPixel(0,5,setColor(0x00,0xFF,0xFF));
    	setPixel(0,6,setColor(0x80,0x00,0x00));
    	setPixel(0,7,setColor(0x80,0x00,0x80));
    	setPixel(0,8,setColor(0x80,0x80,0x00));
    	setPixel(0,9,setColor(0x80,0x80,0x80));
    	setPixel(0,10,setColor(0xC0,0xC0,0xC0));
    	setPixel(0,11,setColor(0xFF,0x00,0x00));
    	setPixel(0,12,setColor(0xFF,0x00,0xFF));
    	setPixel(0,13,setColor(0xFF,0xFF,0x00));
    	setPixel(0,14,setColor(0xFF,0xFF,0xFF));
    	setPixel(0,15,setColor(0x00,0x00,0x00));
    	setPixel(0,16,setColor(0xFF,0xA5,0x00));

    }
}
/* ****************************************************************************/
/* End : main */
/* ****************************************************************************/

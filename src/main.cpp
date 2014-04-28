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
#include "Gamma.h"
#include "MatrixClass.hpp"
#include "LEDArrayClass.hpp"
#include "PointClass.hpp"
/* --------------------------------- defines ---------------------------------*/

/* ------------------------- module data declaration -------------------------*/

unsigned char Reverse5Bit[32] = { 0x00, 0x10, 0x08, 0x18, 0x04, 0x14, 0x0C, 0x1C,
		0x02, 0x12, 0x0A, 0x1A, 0x06, 0x16, 0x0E, 0x1E, 0x01, 0x11, 0x09, 0x19, 0x05,
		0x15, 0x0D, 0x1D, 0x03, 0x13, 0x0B, 0x1B, 0x07, 0x17, 0x0F, 0x1F };

uint16_t color = 0;
/* ----------------------- module procedure declaration ----------------------*/

/* ****************************************************************************/
/* End Header : Main.c */
/* ****************************************************************************/

/* Test text von stetter */

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
	MatrixClass matrix(1,1);
	PointClass point(3,3);
	point.Draw(&matrix.Array);
    while(1)
    {

    }
}
/* ****************************************************************************/
/* End : main */
/* ****************************************************************************/

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
#include "LineClass.hpp"
#include "CircleClass.hpp"
#include "RectangleClass.hpp"
#include "EllipseClass.hpp"
#include "TriangleClass.hpp"
#include "ColorTableClass.hpp"
#include <math.h>
/* --------------------------------- defines ---------------------------------*/
//#define Row		1
//#define Colum	1
/* ------------------------- module data declaration -------------------------*/
static uint16_t  Picture[] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF,
		0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000,
		0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
		0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x0000,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
		0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x0000,
		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x001F, 0x001F,
		0x7FFF, 0x7FFF, 0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000,
		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x001F,
		0x001F, 0x7FFF, 0x7FFF, 0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x001F, 0x001F,
		0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x0000, 0x0000,
		0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
		0x001F, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x001F, 0x001F, 0x001F, 0x001F,
		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x0000,
		0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
		0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
		0x001F, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x001F, 0x001F, 0x7FFF, 0x7FFF,
		0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x001F, 0x001F, 0x7FFF, 0x7FFF,
		0x001F, 0x001F, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000 };

static uint16_t Picture1[1024] = { 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
		0x4200, 0x7FE0, 0x7FE0, 0x7FE0, 0x4200, 0x0000, 0x0000, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FE0, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FE0, 0x7FE0, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x0000, 0x7FE0, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FE0, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x6318,
		0x7FFF, 0x7FFF, 0x6318, 0x7FFF, 0x7FFF, 0x7FFF, 0x4200, 0x0000, 0x7FE0,
		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x4210, 0x6318, 0x6318, 0x6318,
		0x6318, 0x6318, 0x0000, 0x7FE0, 0x7FFF, 0x7FE0, 0x0000, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FE0, 0x7FE0, 0x7FE0,
		0x7FE0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FE0, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FE0, 0x7FE0, 0x6318,
		0x0000, 0x7FE0, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FE0, 0x0000, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FE0, 0x0000, 0x0010, 0x0010, 0x0000, 0x0000,
		0x7FFF, 0x6318, 0x7FFF, 0x7FFF, 0x7FE0, 0x0000, 0x0000, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FE0, 0x7FFF, 0x7FFF,
		0x6318, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x0000, 0x0010, 0x0010, 0x0000, 0x4210, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x4210, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0010, 0x0010, 0x0000,
		0x7FFF, 0x6318, 0x6318, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0010, 0x0000,
		0x7FFF, 0x0000, 0x4200, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x0000,
		0x0000, 0x6318, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x0010, 0x0010, 0x0000, 0x6318, 0x7FFF, 0x6318, 0x0000,
		0x0000, 0x0010, 0x0010, 0x0010, 0x0000, 0x0000, 0x4200, 0x7FE0, 0x0000,
		0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x0000, 0x0000, 0x4210, 0x7FFF, 0x0000,
		0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0010, 0x0000,
		0x0000, 0x6318, 0x6318, 0x0000, 0x0000, 0x0010, 0x0010, 0x0010, 0x0010,
		0x0010, 0x0000, 0x7FE0, 0x7FFF, 0x4200, 0x0000, 0x7FFF, 0x0000, 0x7FFF,
		0x0000, 0x0000, 0x6318, 0x7FFF, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x0000, 0x0010, 0x0000, 0x4210, 0x4210, 0x0000, 0x0010,
		0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0000, 0x7FE0, 0x7FFF,
		0x4200, 0x0000, 0x7FFF, 0x0000, 0x7FFF, 0x0000, 0x0000, 0x4210, 0x7FFF,
		0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0010,
		0x001F, 0x0010, 0x0010, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
		0x0010, 0x0010, 0x0000, 0x4210, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x0000,
		0x7FFF, 0x7FFF, 0x7FFF, 0x6318, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0010, 0x001F, 0x001F, 0x001F, 0x001F,
		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0010, 0x0000,
		0x6318, 0x6318, 0x0000, 0x7FFF, 0x0000, 0x6318, 0x7FFF, 0x7FFF, 0x0000,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0010,
		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
		0x001F, 0x001F, 0x001F, 0x0000, 0x0000, 0x4210, 0x7FFF, 0x0000, 0x7FFF,
		0x7FFF, 0x0000, 0x6318, 0x7FFF, 0x6318, 0x0000, 0x6318, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x6318, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
		0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000,
		0x4210, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x6318,
		0x6318, 0x4210, 0x0000, 0x6318, 0x6318, 0x6318, 0x0000, 0x0000, 0x001F,
		0x001F, 0x001F, 0x03FF, 0x0210, 0x03FF, 0x0210, 0x03FF, 0x0210, 0x03FF,
		0x0210, 0x001F, 0x001F, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x6318, 0x0000,
		0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x03FF, 0x03FF, 0x03FF,
		0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x0210, 0x0210, 0x0000,
		0x0000, 0x7FFF, 0x7FFF, 0x6318, 0x0000, 0x7FFF, 0x0000, 0x7FE0, 0x7FE0,
		0x7FE0, 0x7FE0, 0x7FE0, 0x7FE0, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F,
		0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x7FFF, 0x7FFF, 0x7FFF, 0x03FF,
		0x03FF, 0x03FF, 0x0210, 0x0000, 0x0000, 0x0000, 0x6318, 0x7FFF, 0x0000,
		0x7FFF, 0x7FFF, 0x0000, 0x7FE0, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x0000, 0x0000, 0x03FF, 0x03FF, 0x03FF, 0x03FF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x03FF, 0x03FF, 0x0210, 0x0000,
		0x7FFF, 0x7FFF, 0x0000, 0x6318, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FE0, 0x7FE0, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x03FF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FE0, 0x0000, 0x0000,
		0x0000, 0x7FE0, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x6318, 0x0000,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x7FE0, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x6318,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x6318, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x0000, 0x6318, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x6318, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x6318, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000,
		0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x0000, 0x6318, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x6318, 0x0000, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
		0x7FFF};

unsigned char picctr = 0;

/* ----------------------- module procedure declaration ----------------------*/
extern "C" void EXTI0_IRQHandler(void);
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
//#define DEMO_1 /* 1 Panel */
//#define DEMO_2	/* 1 - 2 Panel */
#define DEMO_3	/* 2 Panel */


int main(void)
{
	/* Init the GPIO's */
	initGPIO();

#ifdef DEMO_1

	int row = 1;
	int colum = 1;

	/* Create a new matrix */
	MatrixClass matrix(row,colum);

	/* Create new color table */
	ColorTableClass coltab;

	/* Add new color "Magenta" and "Orange" */
	coltab.setNew888Color("Magenta",0xFF,0x00,0xFF);
	coltab.setNew888Color("Orange",0xFF,0xa5,0x00);

	/* Draw a point */
	PointClass point(28,4,coltab.GetColorForKey("Orange"));
	point.Draw(&matrix.Array);

	/* Draw a line */
	LineClass line(1,0,1,14,coltab.GetColorForKey("Red"));
	line.Draw(&matrix.Array);

	/* Draw a circle */
	CircleClass circle(10,10,8,coltab.GetColorForKey("Magenta"));
	circle.Draw(&matrix.Array);

	/* Draw a rectangle */
	RectangleClass rect(0,25,5,5,coltab.GetColorForKey("Blue"));
	rect.Draw(&matrix.Array);

	/* Change the position of the rectangle and draw it */
	rect.setPosition(9,25);
	rect.Fill(&matrix.Array);

	rect.setPosition(18,25);
	rect.Draw(&matrix.Array);

	rect.setPosition(27,25);
	rect.Fill(&matrix.Array);

	/* Draw a triangle */
	TriangleClass tri(22,10,14,18,30,18,coltab.GetColorForKey("Green"));
	tri.Draw(&matrix.Array);

#endif

#ifdef DEMO_2

	int row = 2;
	int colum = 1;

	/* Create a new matrix */
	MatrixClass matrix(row,colum);

	/* Create new color table */
	ColorTableClass coltab;

	/* Add new color "Magenta" and "Orange" */
	coltab.setNew888Color("Magenta",0xFF,0x00,0xFF);
	coltab.setNew888Color("Orange",0xFF,0xa5,0x00);

	/* Draw a rectangle */
	RectangleClass rect(5,5,25,3,coltab.GetColorForKey("Green"));
	rect.Fill(&matrix.Array);

	/* Change the position of the rectangle and draw it */
	rect.setPosition(10,10);
	rect.Fill(&matrix.Array);

	/* Change the position of the rectangle and draw it */
	rect.setPosition(15,15);
	rect.Fill(&matrix.Array);

	/* Change the position of the rectangle and draw it */
	rect.setPosition(20,20);
	rect.Fill(&matrix.Array);

	/* Change the position of the rectangle and draw it */
	rect.setPosition(25,25);
	rect.Fill(&matrix.Array);



#endif

#ifdef DEMO_3

	int row = 2;
	int colum = 1;

	/* Create a new matrix */
	MatrixClass matrix(row,colum);

	/* Create new color table */
	ColorTableClass coltab;

	/* Add new color "Magenta" and "Orange" */
	coltab.setNew888Color("Magenta",0xFF,0x00,0xFF);
	coltab.setNew888Color("Orange",0xFF,0xa5,0x00);

	CircleClass Circle(32,32, 31,coltab.GetColorForKey("Magenta"));
	Circle.Draw(&matrix.Array);

	/* Draw a rectangle */
	RectangleClass rect(20,25,24,5,coltab.GetColorForKey("Blue"));
	rect.Fill(&matrix.Array);

	/* Draw a line */
	LineClass line1(10,10,31,24,coltab.GetColorForKey("Red"));
	line1.Draw(&matrix.Array);

	/* Draw a line */
	LineClass line2(53,10,32,24,coltab.GetColorForKey("Red"));
	line2.Draw(&matrix.Array);

#endif


    while(1)
    {

    }
}
/* ****************************************************************************/
/* End : main */
/* ****************************************************************************/
void EXTI0_IRQHandler(){

		if(picctr == 0){

			PrinterClass print(1,1,Picture);
			picctr++;
		}
		else if(picctr ==  1){

			PrinterClass print(1,1,Picture1);
			picctr++;
		}
		else{
			picctr = 0;
		}

	EXTI_ClearITPendingBit(EXTI_Line0);
}


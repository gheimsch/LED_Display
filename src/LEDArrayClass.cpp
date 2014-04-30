/******************************************************************************/
/*! \file LEDArrayClass.cpp
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
#include "MatrixClass.hpp"
#include "LEDArrayClass.hpp"
#include <iostream>
#include <string.h>

/* ------------------------- module data declaration -------------------------*/
uint16_t ctr = 0;
/* ----------------------- module procedure declaration ----------------------*/
LEDArrayClass::LEDArrayClass(int newWidth, int newHeight) : Width(newWidth), Height(newHeight){

	ledArray = new uint16_t[(32*Width)*(32*Height)];
	memset(ledArray,0x00,(32*Width)*(32*Height)*2);

	std::cout << "LineClass created" << std::endl;
}

LEDArrayClass::LEDArrayClass(){

	std::cout << "LineClass created" << std::endl;
}

LEDArrayClass::~LEDArrayClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

void LEDArrayClass::setPixel(int x,int y,uint16_t col){

	if((x < 0) || (x >= (32*Width)) || (y < 0) || (y >= (32*Height))) return;
	ledArray[x+(32*Width)*y] = col;
}

uint16_t * LEDArrayClass::getPtr(void){
	return ledArray;
}
/* ****************************************************************************/
/* End Header : LEDArrayClass.cpp */
/* ****************************************************************************/

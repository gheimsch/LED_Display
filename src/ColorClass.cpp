/******************************************************************************/
/*! \file ColorClass.cpp
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
#include "ColorClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
ColorClass::ColorClass(unsigned char newRed, unsigned char newGreen, unsigned char newBlue){

	Red = newRed;
	Green = newGreen;
	Blue = newBlue;

	std::cout << "LineClass created" << std::endl;
}


ColorClass::~ColorClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

//void LEDArrayClass::setColor(int x,int y,uint16_t col){
//	ledArray[x+(32*Width)*y] = col;
//}
//
//void LEDArrayClass::setPixel(int x,int y,uint16_t col){
//	ledArray[x+(32*Width)*y] = col;
//}
/* ****************************************************************************/
/* End Header : ColorClass.cpp */
/* ****************************************************************************/

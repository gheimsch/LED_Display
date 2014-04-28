/******************************************************************************/
/*! \file LineClass.cpp
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
#include "LineClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
LineClass::LineClass(int newXStart, int newYStart, int newXEnd, int newYEnd): XEnd(newXEnd),YEnd(newYEnd) {

	Position.X = newXStart;
	Position.Y = newYStart;
	std::cout << "LineClass created" << std::endl;
}


LineClass::~LineClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

void LineClass::Draw(LEDArrayClass *ledArray){

	ledArray->setPixel(Position.X,Position.Y,0xFFFF);
}
/* ****************************************************************************/
/* End Header : LineClass.cpp */
/* ****************************************************************************/

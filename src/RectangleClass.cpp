/******************************************************************************/
/*! \file RectangleClass.cpp
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
#include "RectangleClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
RectangleClass::RectangleClass(int newX, int newY, int newWidth, int newHeight) : Width(newWidth), Height(newHeight){

	Position.X = newX;
	Position.Y = newY;
	std::cout << "LineClass created" << std::endl;
}


RectangleClass::~RectangleClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

void RectangleClass::Draw(LEDArrayClass *ledArray){

	ledArray->setPixel(Position.X,Position.Y,0xFFFF);
}
/* ****************************************************************************/
/* End Header : RectangleClass.cpp */
/* ****************************************************************************/

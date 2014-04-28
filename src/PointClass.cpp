/******************************************************************************/
/*! \file PointClass.cpp
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
#include "PointClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
PointClass::PointClass(int newX, int newY, uint16_t newCol) : Col(newCol){

	Position.X = newX;
	Position.Y = newY;

}


PointClass::~PointClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

void PointClass::Draw(LEDArrayClass *ledArray){

	ledArray->setPixel(Position.X,Position.Y,Col);
}
/* ****************************************************************************/
/* End Header : PointClass.cpp */
/* ****************************************************************************/

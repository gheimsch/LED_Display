/******************************************************************************/
/*! \file PointClass.cpp
******************************************************************************
* \brief Class to draw a point
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

/* ****************************************************************************/
/* End Header : PointClass.cpp */
/* ****************************************************************************/

/* Constructor of the class */
PointClass::PointClass(int newX, int newY, uint16_t newCol) : Col(newCol){

	Position.X = newX;
	Position.Y = newY;

}

/* Destructor of the class */
PointClass::~PointClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

/* Draw method of the class */
void PointClass::Draw(LEDArrayClass *ledArray){

	ledArray->SetPixel(Position.X,Position.Y,Col);
}

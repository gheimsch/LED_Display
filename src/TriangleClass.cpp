/******************************************************************************/
/*! \file TriangleClass.cpp
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
#include "TriangleClass.hpp"
#include "LineClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
TriangleClass::TriangleClass(int newX0, int newY0, int newX1, int newY1, int newX2, int newY2): X1(newX1),Y1(newY1),X2(newX2),Y2(newY2) {

	Position.X = newX0;
	Position.Y = newY0;
	std::cout << "LineClass created" << std::endl;
}


TriangleClass::~TriangleClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

void TriangleClass::Draw(LEDArrayClass *ledArray){

	LineClass * line;

	line = new LineClass(Position.X, Position.Y, X1, Y1);
	line->Draw(ledArray);
	line = new LineClass(X1, Y1, X2, Y2);
	line->Draw(ledArray);
	line = new LineClass(X2, Y2, Position.X, Position.Y);
	line->Draw(ledArray);
}
/* ****************************************************************************/
/* End Header : LineClass.cpp */
/* ****************************************************************************/

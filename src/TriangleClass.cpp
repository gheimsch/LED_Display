/******************************************************************************/
/*! \file TriangleClass.cpp
******************************************************************************
* \brief Class to draw a triangle
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

/* ****************************************************************************/
/* End Header : LineClass.cpp */
/* ****************************************************************************/

/* Constructor of the class */
TriangleClass::TriangleClass(int newX0, int newY0, int newX1, int newY1, int newX2, int newY2, uint16_t newCol): X1(newX1),Y1(newY1),X2(newX2),Y2(newY2), Col(newCol) {

	Position.X = newX0;
	Position.Y = newY0;
}

/* Destructor of the class */
TriangleClass::~TriangleClass(){

}

/* Draw method of the class */
void TriangleClass::Draw(LEDArrayClass *ledArray){

	LineClass * line;

	line = new LineClass(Position.X, Position.Y, X1, Y1,Col);
	line->Draw(ledArray);
	line = new LineClass(X1, Y1, X2, Y2,Col);
	line->Draw(ledArray);
	line = new LineClass(X2, Y2, Position.X, Position.Y,Col);
	line->Draw(ledArray);
}

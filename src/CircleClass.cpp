/******************************************************************************/
/*! \file CircleClass.cpp
******************************************************************************
* \brief Class to draw a circle
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
#include "CircleClass.hpp"
#include <iostream>
#include <stdlib.h>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

/* ****************************************************************************/
/* End Header : CircleClass.cpp */
/* ****************************************************************************/

/* Constructor of the class */
CircleClass::CircleClass(int newX, int newY, int newRad, uint16_t newCol) : Rad(newRad){

	Position.X = newX;
	Position.Y = newY;
	Col = newCol;

}

/* Destructor of the class */
CircleClass::~CircleClass(){

}

/* Draw method of the class */
void CircleClass::Draw(LEDArrayClass *ledArray){

	int sw=0, y=0, x=0;
	signed char d;

	d = Position.Y - Position.X;
	y = Rad;
	sw = 2 - 2 * Rad;
	while (x <= y) {

		ledArray->SetPixel(Position.X + x,Position.Y + y,Col);
		ledArray->SetPixel(Position.X + x,Position.Y - y,Col);

		ledArray->SetPixel(Position.X - x,Position.Y + y,Col);
		ledArray->SetPixel(Position.X - x,Position.Y - y,Col);

		ledArray->SetPixel(Position.Y + y - d,Position.Y + x,Col);
		ledArray->SetPixel(Position.Y + y - d,Position.Y - x,Col);
		ledArray->SetPixel(Position.Y - y - d,Position.Y + x,Col);
		ledArray->SetPixel(Position.Y - y - d,Position.Y - x,Col);

		if (sw < 0)
			sw += (4 * x + 6);
		else {

			sw += (4 * (x - y) + 10);
			y--;
		}

		x++;
	}
}

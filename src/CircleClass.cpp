/******************************************************************************/
/*! \file CircleClass.cpp
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
#include "CircleClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
CircleClass::CircleClass(int newX, int newY, int newRad) : Rad(newRad){

	Position.X = newX;
	Position.Y = newY;

	std::cout << "LineClass created" << std::endl;
}


CircleClass::~CircleClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

void CircleClass::Draw(LEDArrayClass *ledArray){

		int sw=0, y=0, x=0;
		unsigned char d;

		d = Position.Y - Position.X;
		y = Rad;
		sw = 3 - 2 * Rad;
		while (x <= y) {

			ledArray->setPixel(Position.X + x,Position.Y + y,0xFFFF);
			ledArray->setPixel(Position.X + x,Position.Y - y,0xFFFF);

			ledArray->setPixel(Position.X - x,Position.Y + y,0xFFFF);
			ledArray->setPixel(Position.X - x,Position.Y - y,0xFFFF);

			ledArray->setPixel(Position.Y + y - d,Position.Y + x,0xFFFF);
			ledArray->setPixel(Position.Y + y - d,Position.Y - x,0xFFFF);
			ledArray->setPixel(Position.Y - y - d,Position.Y + x,0xFFFF);
			ledArray->setPixel(Position.Y - y - d,Position.Y - x,0xFFFF);

			if (sw < 0)
				sw += (4 * x + 6);
			else {

				sw += (4 * (x - y) + 10);
				y--;
			}

			x++;
		}

}
/* ****************************************************************************/
/* End Header : CircleClass.cpp */
/* ****************************************************************************/

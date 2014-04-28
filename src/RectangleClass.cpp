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
#include "LineClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
RectangleClass::RectangleClass(int newX, int newY, int newWidth, int newHeight, uint16_t newCol) : Width(newWidth), Height(newHeight), Col(newCol){

	Position.X = newX;
	Position.Y = newY;
	std::cout << "LineClass created" << std::endl;
}


RectangleClass::~RectangleClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

void RectangleClass::Draw(LEDArrayClass *ledArray){

	LineClass line1(Position.X,Position.Y,Position.X+Width-1,Position.Y,Col);
	line1.Draw(ledArray);
	LineClass line2(Position.X,Position.Y+Height-1,Position.X+Width-1,Position.Y+Height-1,Col);
	line2.Draw(ledArray);
	LineClass line3(Position.X,Position.Y,Position.X,Position.Y+Height-1,Col);
	line3.Draw(ledArray);
	LineClass line4(Position.X+Width-1,Position.Y,Position.X+Width-1,Position.Y+Height-1,Col);
	line4.Draw(ledArray);

}

void RectangleClass::Fill(LEDArrayClass *ledArray){

	LineClass * line;
	unsigned char i;

	for (i=Position.X; i<Position.X+Width; i++) {
		line = new LineClass(i,Position.Y, i,Position.Y+Height-1,Col);
		line->Draw(ledArray);
	}
	for (i=Position.Y; i<Position.Y+Height; i++) {
		line = new LineClass(Position.X,i,Position.X+Width-1,i,Col);
		line->Draw(ledArray);
	}
}
/* ****************************************************************************/
/* End Header : RectangleClass.cpp */
/* ****************************************************************************/

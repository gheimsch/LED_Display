/******************************************************************************/
/*! \file ShapeClass.cpp
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
#include "ShapeClass.hpp"
#include <iostream>
#include "MatrixClass.hpp"
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

ShapeClass::ShapeClass(){

	std::cout << "LineClass created" << std::endl;
}

ShapeClass::ShapeClass(int newX, int newY){

	Position.X = newX;
	Position.Y = newY;

	std::cout << "LineClass created" << std::endl;
}

ShapeClass::~ShapeClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

void ShapeClass::setPosition(int newXPos, int newYPos) {
	Position.X = newXPos;
	Position.Y = newYPos;

	std::cout << "LineClass destroyed" << std::endl;
}

/* ****************************************************************************/
/* End Header : ShapeClass.cpp */
/* ****************************************************************************/

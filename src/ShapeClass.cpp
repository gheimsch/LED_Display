/******************************************************************************/
/*! \file ShapeClass.cpp
******************************************************************************
* \brief Parent class of all geometric objects
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

/* ****************************************************************************/
/* End Header : ShapeClass.cpp */
/* ****************************************************************************/

/* Constructor of the class */
ShapeClass::ShapeClass(){

	std::cout << "LineClass created" << std::endl;
}

/* Constructor 2 of the class */
ShapeClass::ShapeClass(int newX, int newY){

	Position.X = newX;
	Position.Y = newY;

	std::cout << "LineClass created" << std::endl;
}

/* Destructor of the class */
ShapeClass::~ShapeClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

/* Method to set a position */
void ShapeClass::SetPosition(int newXPos, int newYPos) {
	Position.X = newXPos;
	Position.Y = newYPos;

	std::cout << "LineClass destroyed" << std::endl;
}

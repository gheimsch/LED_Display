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
CircleClass::CircleClass(MatrixClass *newMatrix, int newX, int newY, int newRad) : ShapeClass(newMatrix),X(newX),Y(newX), Rad(newRad){

	std::cout << "LineClass created" << std::endl;
}


CircleClass::~CircleClass(){

	std::cout << "LineClass destroyed" << std::endl;
}
/* ****************************************************************************/
/* End Header : CircleClass.cpp */
/* ****************************************************************************/

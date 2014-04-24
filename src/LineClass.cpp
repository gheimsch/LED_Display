/******************************************************************************/
/*! \file LineClass.cpp
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
#include "LineClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
LineClass::LineClass(MatrixClass *newMatrix, int newXStart, int newYStart, int newXEnd, int newYEnd): ShapeClass(newMatrix),XStart(newXStart),YStart(newYStart),XEnd(newXEnd),YEnd(newYEnd) {

	std::cout << "LineClass created" << std::endl;
}


LineClass::~LineClass(){

	std::cout << "LineClass destroyed" << std::endl;
}
/* ****************************************************************************/
/* End Header : LineClass.cpp */
/* ****************************************************************************/

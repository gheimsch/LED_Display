/******************************************************************************/
/*! \file PositionClass.cpp
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
#include "PositionClass.hpp"
#include <iostream>
#include "ShapeClass.hpp"
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
PositionClass::PositionClass(){

	std::cout << "LineClass created" << std::endl;
}

PositionClass::PositionClass(int newX, int newY) : X(newX), Y(newY){

	std::cout << "LineClass created" << std::endl;
}


PositionClass::~PositionClass(){

	std::cout << "LineClass destroyed" << std::endl;
}
/* ****************************************************************************/
/* End Header : PositionClass.cpp */
/* ****************************************************************************/

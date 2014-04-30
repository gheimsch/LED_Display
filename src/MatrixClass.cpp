/******************************************************************************/
/*! \file MatrixClass.cpp
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
#include "MatrixClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
MatrixClass::MatrixClass(int newWidth, int newHeight)
: Array(newWidth, newHeight)
{

	Width = newWidth;
	Height = newHeight;
	PrinterClass printer(Width,Height,Array.getPtr());

	std::cout << "LineClass created" << std::endl;
}


MatrixClass::~MatrixClass(){

	std::cout << "LineClass destroyed" << std::endl;
}
/* ****************************************************************************/
/* End Header : MatrixClass.cpp */
/* ****************************************************************************/

/******************************************************************************/
/*! \file MatrixClass.cpp
******************************************************************************
* \brief Class which represents a RGB matrix
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

/* ****************************************************************************/
/* End Header : MatrixClass.cpp */
/* ****************************************************************************/

/* Constructor of the class */
MatrixClass::MatrixClass(int newWidth, int newHeight)
: Array(newWidth, newHeight)
{

	Width = newWidth;
	Height = newHeight;
	PrinterClass printer(Width,Height,Array.GetPtr());

}

/* Destructor of the class */
MatrixClass::~MatrixClass(){

}

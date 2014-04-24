/******************************************************************************/
/*! \file ColorTableClass.cpp
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
#include "ColorTableClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
ColorTableClass::ColorTableClass(int newColum, int newRow){

	Row = newRow;
	Colum = newColum;
	DrawBuffer = new int[(32*Row)+(32*Colum)];

	std::cout << "LineClass created" << std::endl;
}


ColorTableClass::~ColorTableClass(){

	std::cout << "LineClass destroyed" << std::endl;
}
/* ****************************************************************************/
/* End Header : MatrixClass.cpp */
/* ****************************************************************************/

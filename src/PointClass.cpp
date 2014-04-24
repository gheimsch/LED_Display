/******************************************************************************/
/*! \file PointClass.cpp
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
#include "PointClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
PointClass::PointClass(MatrixClass *newMatrix, int newX, int newY) : ShapeClass(newMatrix),X(newX),Y(newX){

	Matrix->Array.setPixel(newX,newY,0xFFFF);
}


PointClass::~PointClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

PointClass::Draw(LEDArrayClass *ledArray){

	ledArray->setPixel(ShapeClass,newY,0xFFFF);
}
/* ****************************************************************************/
/* End Header : PointClass.cpp */
/* ****************************************************************************/

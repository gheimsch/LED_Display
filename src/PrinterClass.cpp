/******************************************************************************/
/*! \file PrinterClass.cpp
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
#include "PrinterClass.hpp"
#include <iostream>
#include "TimerISR.h"
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
PrinterClass::PrinterClass(int newWidth, int newHight, uint16_t *newDataPtr){

	Width = newWidth;
	Hight = newHight;
	DataPtr = newDataPtr;
	initISR(Width,Hight,DataPtr);

	std::cout << "LineClass created" << std::endl;
}


PrinterClass::~PrinterClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

void PrinterClass::setDataPtr(uint16_t *ptr){
	DataPtr = ptr;
}
/* ****************************************************************************/
/* End Header : PrinterClass.cpp */
/* ****************************************************************************/

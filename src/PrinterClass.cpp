/******************************************************************************/
/*! \file PrinterClass.cpp
******************************************************************************
* \brief Class to handle the HW-interface
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

/* ****************************************************************************/
/* End Header : PrinterClass.cpp */
/* ****************************************************************************/

/* Constructor of the class */
PrinterClass::PrinterClass(int newWidth, int newHight, uint16_t *newDataPtr){

	Width = newWidth;
	Hight = newHight;
	DataPtr = newDataPtr;
	initISR(Width,Hight,DataPtr);

}

/* Destructor of the class */
PrinterClass::~PrinterClass(){

}

/* Method to set a pointer of a LED array */
void PrinterClass::SetDataPtr(uint16_t *ptr){
	DataPtr = ptr;
}

/******************************************************************************/
/*! \file LEDArrayClass.cpp
******************************************************************************
* \brief Class which holds an array to store a RGB matrix
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
#include "LEDArrayClass.hpp"
#include <iostream>
#include <string.h>

/* ------------------------- module data declaration -------------------------*/
uint16_t ctr = 0;
/* ----------------------- module procedure declaration ----------------------*/

/* ****************************************************************************/
/* End Header : LEDArrayClass.cpp */
/* ****************************************************************************/

/* Constructor of the class */
LEDArrayClass::LEDArrayClass(int newWidth, int newHeight) : Width(newWidth), Height(newHeight){

	ledArray = new uint16_t[(32*Width)*(32*Height)];
	memset(ledArray,0x00,(32*Width)*(32*Height)*2);

}

/* Constructor of the class */
LEDArrayClass::LEDArrayClass(){

}

/* Destructor of the class */
LEDArrayClass::~LEDArrayClass(){

}

/* Method to set a "pixel" in the array */
void LEDArrayClass::SetPixel(int x,int y,uint16_t col){

	if((x < 0) || (x >= (32*Width)) || (y < 0) || (y >= (32*Height))) return;
	ledArray[x+(32*Width)*y] = col;
}

/* Returns the pointer to the LED array */
uint16_t * LEDArrayClass::GetPtr(void){
	return ledArray;
}

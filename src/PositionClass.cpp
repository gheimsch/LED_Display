/******************************************************************************/
/*! \file PositionClass.cpp
******************************************************************************
* \brief Class to handle a position
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

/* ****************************************************************************/
/* End Header : PositionClass.cpp */
/* ****************************************************************************/

/* Constructor of the class */
PositionClass::PositionClass(){

}

/* Constructor 2 of the class */
PositionClass::PositionClass(int newX, int newY) : X(newX), Y(newY){

}

/* Destructor of the class */
PositionClass::~PositionClass(){

}

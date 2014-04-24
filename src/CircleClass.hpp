#ifndef CIRCLE_CLASS_HPP_
#define CIRCLE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file CircleClass.hpp
******************************************************************************
* \brief Short description of the files function
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
#include "ShapeClass.hpp"
/* ----------------------- module constant declaration -----------------------*/

/* ------------------------- module type declaration -------------------------*/

/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

class CircleClass : public ShapeClass {

   // Data
	int X;
	int Y;
	int Rad;

   // Methods
public:
	CircleClass();
	CircleClass(MatrixClass *newMatrix, int newX, int newY, int newRad);
	~CircleClass();

};
/* ****************************************************************************/
/* End Header : CricleClass.hpp */
/* ****************************************************************************/
# endif
#endif /* CRICLE_CLASS_HPP_ */

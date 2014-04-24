#ifndef POINT_CLASS_HPP_
#define POINT_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file PointClass.hpp
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

class PointClass : public ShapeClass{

   // Data
	int X;
	int Y;

   // Methods
public:
	PointClass();
	PointClass(MatrixClass *newMatrix, int newX, int newY);
	~PointClass();

};
/* ****************************************************************************/
/* End Header : PointClass.hpp */
/* ****************************************************************************/
# endif
#endif /* POINT_CLASS_HPP_ */

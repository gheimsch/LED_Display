#ifndef TRIANGLE_CLASS_HPP_
#define TRIANGLE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file TRIANGLEClass.hpp
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

class TriangleClass : public ShapeClass {

   // Data
	int X1;
	int Y1;
	int X2;
	int Y2;
	uint16_t Col;

   // Methods
public:
	TriangleClass();
	TriangleClass(int newX0, int newY0, int newX1, int newY1, int newX2, int newY2, uint16_t newCol);
	~TriangleClass();

	void Draw(LEDArrayClass *);

};
/* ****************************************************************************/
/* End Header : TriangleClass.hpp */
/* ****************************************************************************/
# endif
#endif /* TRIANGLE_CLASS_HPP_ */

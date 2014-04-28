#ifndef RECTANGLE_CLASS_HPP_
#define RECTANGLE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file RectangleClass.hpp
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
#include "LEDArrayClass.hpp"
/* ----------------------- module constant declaration -----------------------*/

/* ------------------------- module type declaration -------------------------*/

/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

class RectangleClass : public ShapeClass {

   // Data
	int X;
	int Y;
	int Width;
	int Height;

   // Methods
public:
	RectangleClass();
	RectangleClass(int newX, int newY, int newWidth, int newHeight);
	~RectangleClass();

	void Draw(LEDArrayClass * ledArray);

};
/* ****************************************************************************/
/* End Header : RectangleClass.hpp */
/* ****************************************************************************/
# endif
#endif /* RECTANGLE_CLASS_HPP_ */

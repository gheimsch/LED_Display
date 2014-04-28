#ifndef SHAPE_CLASS_HPP_
#define SHAPE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file ShapeClass.hpp
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
#include "PositionClass.hpp"
#include "LEDArrayClass.hpp"
/* ----------------------- module constant declaration -----------------------*/

/* ------------------------- module type declaration -------------------------*/

/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

/* ****************************************************************************/
/* End Header : ShapeClass.hpp */
/* ****************************************************************************/

class ShapeClass {


protected:
	PositionClass Position;

   // Methods
public:
	ShapeClass();
	ShapeClass(int newX, int newY);
	~ShapeClass();

	void Draw();
	void Fill();
	void setPosition(int newXPos, int newYPos);
};

# endif
#endif /* SHAPE_CLASS_HPP_ */

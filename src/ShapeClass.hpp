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

class ShapeClass {


protected:
	//MatrixClass *Matrix;
	PositionClass Position;

   // Methods
public:
	//ShapeClass(MatrixClass *NewMatrix);
	ShapeClass();
	ShapeClass(int newX, int newY);
	~ShapeClass();

	void Draw();
};
/* ****************************************************************************/
/* End Header : ShapeClass.hpp */
/* ****************************************************************************/
# endif
#endif /* SHAPE_CLASS_HPP_ */

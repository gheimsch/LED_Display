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
#include "MatrixClass.hpp"
/* ----------------------- module constant declaration -----------------------*/

/* ------------------------- module type declaration -------------------------*/

/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

class ShapeClass {


private:
	MatrixClass *Matrix;
	PositionClass Position;

   // Methods
public:
	//ShapeClass(){};
	//ShapeClass(MatrixClass *NewMatrix);
	ShapeClass(PointClass NewPosition);
	~ShapeClass();

	void Draw();
	int getWidth() {return(Matrix->Width);};
	int getHeight() {return(Matrix->Height);};
};
/* ****************************************************************************/
/* End Header : ShapeClass.hpp */
/* ****************************************************************************/
# endif
#endif /* SHAPE_CLASS_HPP_ */

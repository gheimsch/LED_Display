#ifndef MATRIX_CLASS_HPP_
#define MATRIX_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file MatrixClass.hpp
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
#include "LEDArrayClass.hpp"
#include "PrinterClass.hpp"
/* ----------------------- module constant declaration -----------------------*/

/* ------------------------- module type declaration -------------------------*/

/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

class MatrixClass {

	friend class ShapeClass;
	//friend class LEDArrayClass;
   // Data
	int Height;
	int Width;
	//Colortable

   // Methods
public:
	//MatrixClass();
	LEDArrayClass Array;
	MatrixClass(int newHeight, int newWidth);
	~MatrixClass();

};
/* ****************************************************************************/
/* End Header : MatrixClass.hpp */
/* ****************************************************************************/
# endif
#endif /* MATRIX_CLASS_HPP_ */

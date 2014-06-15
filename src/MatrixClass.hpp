#ifndef MATRIX_CLASS_HPP_
#define MATRIX_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file MatrixClass.hpp
******************************************************************************
* \brief Class which represents a RGB matrix
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
#include "ColorTableClass.hpp"

class MatrixClass {

	friend class ShapeClass;
    // Data
	int Height;
	int Width;

public:
	ColorTableClass Coltab;

   // Methods
public:
	LEDArrayClass Array;
	MatrixClass(int newHeight, int newWidth);
	~MatrixClass();

};
/* ****************************************************************************/
/* End Header : MatrixClass.hpp */
/* ****************************************************************************/
# endif
#endif /* MATRIX_CLASS_HPP_ */

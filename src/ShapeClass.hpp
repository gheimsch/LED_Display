#ifndef SHAPE_CLASS_HPP_
#define SHAPE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file ShapeClass.hpp
******************************************************************************
* \brief Parent class of all geometric objects
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
	void SetPosition(int newXPos, int newYPos);
};

/* ****************************************************************************/
/* End Header : ShapeClass.hpp */
/* ****************************************************************************/

# endif
#endif /* SHAPE_CLASS_HPP_ */

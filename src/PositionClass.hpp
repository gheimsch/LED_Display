#ifndef POSITION_CLASS_HPP_
#define POSITION_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file PositionClass.hpp
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

class PositionClass {

private:
	ShapeClass Shape;
   // Data
	int X;
	int Y;



   // Methods
public:
	//PositionClass();
	PositionClass(ShapeClass newShape, int newX, int newY);
	~PositionClass();

	void SetX(int newX) {X = newX;};
	void SetY(int newY) {Y = newY;};
	int	GetX() {return(X);};
	int	GetY() {return(Y);};

};
/* ****************************************************************************/
/* End Header : PositionClass.hpp */
/* ****************************************************************************/
# endif
#endif /* POSITION_CLASS_HPP_ */

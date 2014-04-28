#ifndef CIRCLE_CLASS_HPP_
#define CIRCLE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file CircleClass.hpp
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

class CircleClass : public ShapeClass {

   // Data
	int Rad;


   // Methods
public:
	CircleClass();
	CircleClass(int newX, int newY, int newRad);
	~CircleClass();

	void Draw(LEDArrayClass *ledArray);

};
/* ****************************************************************************/
/* End Header : CricleClass.hpp */
/* ****************************************************************************/
# endif
#endif /* CRICLE_CLASS_HPP_ */

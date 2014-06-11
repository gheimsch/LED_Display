#ifndef CIRCLE_CLASS_HPP_
#define CIRCLE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file CircleClass.hpp
******************************************************************************
* \brief Class to draw a circle
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
#include "ColorClass.hpp"

class CircleClass : public ShapeClass {

   // Data
	int Rad;
	uint16_t Col;


   // Methods
public:
	CircleClass();
	CircleClass(int newX, int newY, int newRad, uint16_t newCol);
	~CircleClass();

	void Draw(LEDArrayClass *ledArray);

};
/* ****************************************************************************/
/* End Header : CricleClass.hpp */
/* ****************************************************************************/
# endif
#endif /* CRICLE_CLASS_HPP_ */

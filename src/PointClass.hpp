#ifndef POINT_CLASS_HPP_
#define POINT_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file PointClass.hpp
******************************************************************************
* \brief Class to draw a point
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


class PointClass : public ShapeClass{


   // Methods
public:
	uint16_t Col;
	PointClass(int newX, int newY, uint16_t newCol);
	~PointClass();

	void Draw(LEDArrayClass *);

};
/* ****************************************************************************/
/* End Header : PointClass.hpp */
/* ****************************************************************************/
# endif
#endif /* POINT_CLASS_HPP_ */

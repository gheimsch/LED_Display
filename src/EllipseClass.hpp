#ifndef ELLIPSE_CLASS_HPP_
#define ELLIPSE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file EllipseClass.hpp
******************************************************************************
* \brief Class to draw an elipse
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


class EllipseClass : public ShapeClass {

   // Data
	int A;
	int B;
	uint16_t Col;


   // Methods
public:
	EllipseClass();
	EllipseClass(int newX, int newY, int newA, int newB, uint16_t newCol);
	~EllipseClass();

	void Draw(LEDArrayClass *ledArray);

};
/* ****************************************************************************/
/* End Header : EllipseClass.hpp */
/* ****************************************************************************/
# endif
#endif /* ELLIPSE_CLASS_HPP_ */

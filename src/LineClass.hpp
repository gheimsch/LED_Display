#ifndef LINE_CLASS_HPP_
#define LINE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file LineClass.hpp
******************************************************************************
* \brief Class to draw a line in a array
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


class LineClass : public ShapeClass {

   // Data
	int XStart;
	int YStart;
	int XEnd;
	int YEnd;
	uint16_t Col;

   // Methods
public:
	LineClass();
	LineClass(int newXStart, int newYStart, int newXEnd, int newYEnd, uint16_t newCol);
	~LineClass();

	void Draw(LEDArrayClass *);

};
/* ****************************************************************************/
/* End Header : LineClass.hpp */
/* ****************************************************************************/
# endif
#endif /* LINE_CLASS_HPP_ */

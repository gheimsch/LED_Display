#ifndef RECTANGLE_CLASS_HPP_
#define RECTANGLE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file RectangleClass.hpp
******************************************************************************
* \brief Class to draw a rectangle
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


class RectangleClass : public ShapeClass {

private:
   // Data
	int X;
	int Y;
	int Width;
	int Height;
	uint16_t Col;

   // Methods
public:
	RectangleClass();
	RectangleClass(int newX, int newY, int newWidth, int newHeight, uint16_t newCol);
	~RectangleClass();

	void Draw(LEDArrayClass * ledArray);
	void Fill(LEDArrayClass * ledArray);

};
/* ****************************************************************************/
/* End Header : RectangleClass.hpp */
/* ****************************************************************************/
# endif
#endif /* RECTANGLE_CLASS_HPP_ */

#ifndef LINE_CLASS_HPP_
#define LINE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file LineClass.hpp
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

class LineClass : public ShapeClass {

   // Data
	int XStart;
	int YStart;
	int XEnd;
	int YEnd;

   // Methods
public:
	LineClass();
	LineClass(int newXStart, int newYStart, int newXEnd, int newYEnd);
	~LineClass();

	void Draw(LEDArrayClass *);

};
/* ****************************************************************************/
/* End Header : LineClass.hpp */
/* ****************************************************************************/
# endif
#endif /* LINE_CLASS_HPP_ */

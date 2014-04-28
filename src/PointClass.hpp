#ifndef POINT_CLASS_HPP_
#define POINT_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file PointClass.hpp
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

class PointClass : public ShapeClass{

   // Data

   // Methods
public:
	//PointClass();
	PointClass(int newX, int newY);
	~PointClass();

	void Draw(LEDArrayClass *);

};
/* ****************************************************************************/
/* End Header : PointClass.hpp */
/* ****************************************************************************/
# endif
#endif /* POINT_CLASS_HPP_ */

#ifndef LED_ARRAY_HPP_
#define LED_ARRAY_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file LEDArray.hpp
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
#include <stdint.h>
/* ----------------------- module constant declaration -----------------------*/

/* ------------------------- module type declaration -------------------------*/

/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

class LEDArrayClass {

   // Data
	friend class MatrixClass;
	int Width;
	int Height;
	uint16_t *ledArray;

   // Methods
public:
	LEDArrayClass();
	LEDArrayClass(int newWidth, int newHeight);
	~LEDArrayClass();

	void setPixel(int x,int y, uint16_t col);
	uint16_t * getPtr(void);

};
/* ****************************************************************************/
/* End Header : LEDArrayClass.hpp */
/* ****************************************************************************/
# endif
#endif /* LED_ARRAY_HPP_ */

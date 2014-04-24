#ifndef PRINTER_CLASS_HPP_
#define PRINTER_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file PrinterClass.hpp
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

class PrinterClass {

   // Data
	int Width;
	int Hight;
	uint16_t *DataPtr;

   // Methods
public:
	PrinterClass();
	PrinterClass(int newWidth, int newHight, uint16_t *newDataPtr);
	~PrinterClass();

	void setDataPtr(uint16_t *ptr);

};
/* ****************************************************************************/
/* End Header : Matrix.hpp */
/* ****************************************************************************/
# endif
#endif /* TIMERISR_HPP_ */

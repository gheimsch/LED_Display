#ifndef COLOR_TABLE_CLASS_HPP_
#define COLOR_TABLE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file ColorTableClass.hpp
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

/* ----------------------- module constant declaration -----------------------*/

/* ------------------------- module type declaration -------------------------*/

/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

class ColorTableClass {

   // Data
	int Colum;
	int Row;
	int *DrawBuffer;

   // Methods
public:
	ColorTableClass();
	ColorTableClass(int newColum, int newRow);
	~ColorTableClass();

};
/* ****************************************************************************/
/* End Header : ColorTableClass.hpp */
/* ****************************************************************************/
# endif
#endif /* COLOR_TABLE_CLASS_HPP_ */

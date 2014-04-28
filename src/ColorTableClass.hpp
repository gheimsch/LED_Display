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
#include <iostream>
#include <map>

#include "ColorClass.hpp"
/* ----------------------- module constant declaration -----------------------*/

/* ------------------------- module type declaration -------------------------*/

/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

class ColorTableClass {

   // Data

   // Methods
public:
	ColorTableClass();
	~ColorTableClass();

	void PrintColors(void);
	uint16_t GetColorForKey(std::string key);
	void setNew888Color(std::string name, uint8_t red,uint8_t green,uint8_t blue);
	void setNew555Color(std::string name, uint8_t red,uint8_t green,uint8_t blue);

};
/* ****************************************************************************/
/* End Header : ColorTableClass.hpp */
/* ****************************************************************************/
# endif
#endif /* COLOR_TABLE_CLASS_HPP_ */

#ifndef COLOR_TABLE_CLASS_HPP_
#define COLOR_TABLE_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file ColorTableClass.hpp
******************************************************************************
* \brief Class with a list of colors, defined by the user
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


class ColorTableClass {

   // Data

   // Methods
public:
	ColorTableClass();
	~ColorTableClass();

	void PrintColors(void);
	uint16_t GetColorForKey(std::string key);
	void SetNew888Color(std::string name, uint8_t red,uint8_t green,uint8_t blue);
	void SetNew555Color(std::string name, uint8_t red,uint8_t green,uint8_t blue);

};
/* ****************************************************************************/
/* End Header : ColorTableClass.hpp */
/* ****************************************************************************/
# endif
#endif /* COLOR_TABLE_CLASS_HPP_ */

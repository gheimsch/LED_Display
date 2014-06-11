#ifndef COLOR_CLASS_HPP_
#define COLOR_CLASS_HPP_

# ifdef __cplusplus

/******************************************************************************/
/*! \file ColorClass.hpp
******************************************************************************
* \brief Color Class to store and load defined colors
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


class ColorClass {

   // Data
	unsigned char Red;
	unsigned char Green;
	unsigned char Blue;

   // Methods
public:
	ColorClass();
	ColorClass(unsigned char newRed, unsigned char newGreen, unsigned char newBlue);
	~ColorClass();

	void SetColor(uint16_t red, uint16_t green, uint16_t blue);
	uint16_t GetColor(void);
	uint16_t GetHSV2RGB(long hue, uint8_t sat, uint8_t val);
	void SetColor888(unsigned char red,unsigned char green,unsigned char blue);
	void SetColor555(unsigned char red,unsigned char green,unsigned char blue);
};
/* ****************************************************************************/
/* End Header : ColorClass.hpp */
/* ****************************************************************************/
# endif
#endif /* COLOR_CLASS_HPP_ */

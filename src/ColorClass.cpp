/******************************************************************************/
/*! \file ColorClass.cpp
******************************************************************************
* \brief Short description of the files function
*
* Function : More detailed description of the files function
*
* Procedures :
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
#include "ColorClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

unsigned char Reverse5Bit[32] = { 0x00, 0x10, 0x08, 0x18, 0x04, 0x14, 0x0C, 0x1C,
		0x02, 0x12, 0x0A, 0x1A, 0x06, 0x16, 0x0E, 0x1E, 0x01, 0x11, 0x09, 0x19, 0x05,
		0x15, 0x0D, 0x1D, 0x03, 0x13, 0x0B, 0x1B, 0x07, 0x17, 0x0F, 0x1F };

/* ----------------------- module procedure declaration ----------------------*/

uint16_t setColor888(unsigned char R,unsigned char G,unsigned char B);

/* ****************************************************************************/
/* End Header : ColorClass.cpp */
/* ****************************************************************************/

ColorClass::ColorClass()
{
	Red = 0;
	Green = 0;
	Blue = 0;
	std::cout << "ColorClass created" << std::endl;
}


ColorClass::ColorClass(unsigned char newRed, unsigned char newGreen, unsigned char newBlue){

	Red = newRed>>3;
	Green = newGreen>>3;
	Blue = newBlue>>3;

	std::cout << "ColorClass created" << std::endl;
}


ColorClass::~ColorClass(){

	std::cout << "ColorClass destroyed" << std::endl;
}

uint16_t ColorClass::getColor(void)
{
	return (((Reverse5Bit[Red]) | ((Reverse5Bit[Green]) << 5)
				| ((Reverse5Bit[Blue]) << 10)));
}

uint16_t ColorClass::getHSV2RGB(long hue, uint8_t sat, uint8_t val) {

  uint8_t r, g, b, lo;
  uint16_t s1, v1;

  // Hue
  hue %= 1536; // -1535 to +1535
  if(hue < 0) hue += 1536; // 0 to +1535
  lo = hue & 255; // Low byte = primary/secondary color mix
  switch(hue >> 8) { // High byte = sextant of colorwheel
    case 0 : r = 255 ; g = lo ; b = 0 ; break; // R to Y
    case 1 : r = 255 - lo; g = 255 ; b = 0 ; break; // Y to G
    case 2 : r = 0 ; g = 255 ; b = lo ; break; // G to C
    case 3 : r = 0 ; g = 255 - lo; b = 255 ; break; // C to B
    case 4 : r = lo ; g = 0 ; b = 255 ; break; // B to M
    default: r = 255 ; g = 0 ; b = 255 - lo; break; // M to R
  }

  // Saturation: add 1 so range is 1 to 256, allowig a quick shift operation
  // on the result rather than a costly divide, while the type upgrade to int
  // avoids repeated type conversions in both directions.
  s1 = sat + 1;
  r = 255 - (((255 - r) * s1) >> 8);
  g = 255 - (((255 - g) * s1) >> 8);
  b = 255 - (((255 - b) * s1) >> 8);

  // Value (brightness) & 16-bit color reduction: similar to above, add 1
  // to allow shifts, and upgrade to int makes other conversions implicit.
  v1 = val + 1;

    r = (r * v1); //>> 8; // 8-bit results
    g = (g * v1);// >> 8;
    b = (b * v1);// >> 8;
	return (((Reverse5Bit[r]) | ((Reverse5Bit[g]) << 5)
				| ((Reverse5Bit[b]) << 10)));
}


/******************************************************************************/
/* Function: setColor888 */
/******************************************************************************/
/*! \brief Convert and set a 888 color to a 555 color
*
* \param[in] parameter1 8bit red value
* \param[in] parameter2 8bit green value
* \param[in] parameter2 8bit blue value
*
* \return None
*
* \author meert1,heimg1
*
* \version 0.0.1
*
* \date 03.04.2014 File Created
*
*******************************************************************************/
void ColorClass::setColor888(unsigned char red,unsigned char green,unsigned char blue){
	Red = red>>3;
	Green = green>>3;
	Blue = blue>>3;
}
/* ****************************************************************************/
/* End : setColor888 */
/* ****************************************************************************/


/******************************************************************************/
/* Function: setColor555 */
/******************************************************************************/
/*! \brief Set a 5 bit color
*
* \param[in] parameter1 5bit red value
* \param[in] parameter2 5bit green value
* \param[in] parameter2 5bit blue value
*
* \return None
*
* \author meert1,heimg1
*
* \version 0.0.1
*
* \date 03.04.2014 File Created
*
*******************************************************************************/
void ColorClass::setColor555(unsigned char red,unsigned char green,unsigned char blue){
	Red = red & 0x1F;
	Green = green & 0x1F;
	Blue = blue & 0x1F;
}
/* ****************************************************************************/
/* End : setColor555 */
/* ****************************************************************************/

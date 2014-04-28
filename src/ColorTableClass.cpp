/******************************************************************************/
/*! \file ColorTableClass.cpp
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
#include "ColorTableClass.hpp"

/* ------------------------- module data declaration -------------------------*/

std::map<std::string,ColorClass*> colorMap;
std::map<std::string,ColorClass*>::iterator mapIterator;

/* ----------------------- module procedure declaration ----------------------*/

/* ****************************************************************************/
/* End Header : ColorTableClass.cpp */
/* ****************************************************************************/

ColorTableClass::ColorTableClass(){

	/* Create a few standart colors */
	colorMap["Black"] = new ColorClass(0,0,0);
	colorMap["White"] = new ColorClass(0xFF,0xFF,0xFF);
	colorMap["Red"] = new ColorClass(0xFF,0x00,0x00);
	colorMap["Green"] = new ColorClass(0x00,0xFF,0x00);
	colorMap["Blue"] = new ColorClass(0x00,0x00,0xFF);

	std::cout << "Color table created" << std::endl;
}


ColorTableClass::~ColorTableClass(){

	for( mapIterator = colorMap.begin(); mapIterator!=colorMap.end(); ++mapIterator)
	{
		(*mapIterator).second->~ColorClass();
	}
	std::cout << "Color table destroyed" << std::endl;
}


void ColorTableClass::PrintColors(void)
{
	/* Print the colors in the color table */
	std::cout << std::endl << "Colors in table:" << std::endl;

	for( mapIterator = colorMap.begin(); mapIterator!=colorMap.end(); ++mapIterator)
	{
		std::cout << (*mapIterator).first << ": " << (*mapIterator).second->getColor() << std::endl;
	}

}


int ColorTableClass::GetColorForKey(std::string key)
{
	if(colorMap.find(key) != colorMap.end())
	{
		/* Print the color */
		std::cout << "Color of " << key << " = " << colorMap[key]->getColor() << std::endl;

		/* Return the color with the given key */
		return colorMap[key]->getColor();
	}
	else
	{
		/* Print error msg */
		std::cout << "Could not find a color with name \"" << key << "\"" << std::endl;

		/* Return the color with the given key */
		return -1;
	}

}


void ColorTableClass::setNew888Color(std::string name, uint8_t red,uint8_t green,uint8_t blue)
{
	colorMap[name] = new ColorClass(red,green,blue);
}

void ColorTableClass::setNew555Color(std::string name, uint8_t red,uint8_t green,uint8_t blue)
{
	colorMap[name] = new ColorClass();
	colorMap[name]->setColor555(red,green,blue);
}

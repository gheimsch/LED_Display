/******************************************************************************/
/*! \file ColorTableClass.cpp
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
#include "ColorTableClass.hpp"

/* ------------------------- module data declaration -------------------------*/

/* A map and it's iterator, used to store color classes */
std::map<std::string,ColorClass*> colorMap;
std::map<std::string,ColorClass*>::iterator mapIterator;

/* ----------------------- module procedure declaration ----------------------*/

/* ****************************************************************************/
/* End Header : ColorTableClass.cpp */
/* ****************************************************************************/


/* Constructor of the class */
ColorTableClass::ColorTableClass(){

	/* Create a few standart colors */
	colorMap["Black"] = new ColorClass(0,0,0);
	colorMap["White"] = new ColorClass(0xFF,0xFF,0xFF);
	colorMap["Red"] = new ColorClass(0xFF,0x00,0x00);
	colorMap["Green"] = new ColorClass(0x00,0xFF,0x00);
	colorMap["Blue"] = new ColorClass(0x00,0x00,0xFF);
}

/* Destructor of the class */
ColorTableClass::~ColorTableClass(){

	for( mapIterator = colorMap.begin(); mapIterator!=colorMap.end(); ++mapIterator)
	{
		(*mapIterator).second->~ColorClass();
	}
}

/* Helper method to write all stored colors to the terminal */
void ColorTableClass::PrintColors(void)
{
	/* Print the colors in the color table */

	for( mapIterator = colorMap.begin(); mapIterator!=colorMap.end(); ++mapIterator)
	{
		std::cout << (*mapIterator).first << ": " << (*mapIterator).second->GetColor() << std::endl;
	}

}

/* Method to get a RGB value for a given key */
uint16_t ColorTableClass::GetColorForKey(std::string key)
{
	if(colorMap.find(key) != colorMap.end())
	{
		/* Print the color */
		std::cout << "Color of " << key << " = " << colorMap[key]->GetColor() << std::endl;

		/* Return the color with the given key */
		return colorMap[key]->GetColor();
	}
	else
	{
		/* Print error msg */
		std::cout << "Could not find a color with name \"" << key << "\"" << std::endl;

		/* Return the color with the given key */
		return 0;
	}

}

/* This Method stores a new true color with the given name in the map */
void ColorTableClass::SetNew888Color(std::string name, uint8_t red,uint8_t green,uint8_t blue)
{
	colorMap[name] = new ColorClass(red,green,blue);
}

/* This Method stores a new 555 bit color with the given name in the map */
void ColorTableClass::SetNew555Color(std::string name, uint8_t red,uint8_t green,uint8_t blue)
{
	colorMap[name] = new ColorClass();
	colorMap[name]->SetColor555(red,green,blue);
}

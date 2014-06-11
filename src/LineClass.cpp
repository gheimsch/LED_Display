/******************************************************************************/
/*! \file LineClass.cpp
******************************************************************************
* \brief Class to draw a line in a array
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
#include "LineClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

/* ****************************************************************************/
/* End Header : LineClass.cpp */
/* ****************************************************************************/

/* Constructor of the class */
LineClass::LineClass(int newXStart, int newYStart, int newXEnd, int newYEnd, uint16_t newCol): XEnd(newXEnd),YEnd(newYEnd), Col(newCol) {

	Position.X = newXStart;
	Position.Y = newYStart;
	std::cout << "LineClass created" << std::endl;
}

/* Destructor of the class */
LineClass::~LineClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

/* Draw method of the class */
void LineClass::Draw(LEDArrayClass *ledArray){

	volatile int x,y,t, dx, dy, incx, incy, pdx, pdy, ddx, ddy, es, el, err;

	// Entfernung in beiden Dimensionen berechnen
	   dx = XEnd - Position.X;
	   dy = YEnd - Position.Y;

	// Vorzeichen des Inkrements bestimmen
	   incx = (dx > 0) ? 1 : ((dx < 0) ? -1 : 0);
	   incy = (dy > 0) ? 1 : ((dy < 0) ? -1 : 0);
	   if(dx<0) dx = -dx;
	   if(dy<0) dy = -dy;

	// feststellen, welche Entfernung größer ist
	   if (dx>dy)
	   {
	      // x ist schnelle Richtung
	      pdx=incx; pdy=0;    // pd. ist Parallelschritt
	      ddx=incx; ddy=incy; // dd. ist Diagonalschritt
	      es =dy;   el =dx;   // Fehlerschritte schnell, langsam
	   } else
	   {
	      // y ist schnelle Richtung
	      pdx=0;    pdy=incy; // pd. ist Parallelschritt
	      ddx=incx; ddy=incy; // dd. ist Diagonalschritt
	      es =dx;   el =dy;   // Fehlerschritte schnell, langsam
	   }

	// Initialisierungen vor Schleifenbeginn
	   x = Position.X;
	   y = Position.Y;
	   err = el/2;
	   ledArray->SetPixel(x,y,Col);

	// Pixel berechnen
	   for(t=0; t<el; ++t) // t zaehlt die Pixel, el ist auch Anzahl
	   {
	      // Aktualisierung Fehlerterm
	      err -= es;
	      if(err<1)
	      {
	          // Fehlerterm wieder positiv (>=0) machen
	          err += el;
	          // Schritt in langsame Richtung, Diagonalschritt
	          x += ddx;
	          y += ddy;
	      } else
	      {
	          // Schritt in schnelle Richtung, Parallelschritt
	          x += pdx;
	          y += pdy;
	      }
	      ledArray->SetPixel(x,y,Col);
	   }


}

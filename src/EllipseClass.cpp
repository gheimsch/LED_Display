/******************************************************************************/
/*! \file EllipseClass.cpp
******************************************************************************
* \brief Class to draw an elipse
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
#include "EllipseClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/

/* ****************************************************************************/
/* End Header : EllipseClass.cpp */
/* ****************************************************************************/

/* Constructor of the class */
EllipseClass::EllipseClass(int newX, int newY, int newA, int newB, uint16_t newCol) : A(newA), B(newB),Col(newCol){

	Position.X = newX;
	Position.Y = newY;

}

/* Destructor of the class */
EllipseClass::~EllipseClass(){

}

/* Draw method of the class */
void EllipseClass::Draw(LEDArrayClass *ledArray){

	   char dx = 0, dy = B; /* im I. Quadranten von links oben nach rechts unten */
	   int a2 = A*A, b2 = B*B;
	   int err = b2-(2*B-1)*a2, e2; /* Fehler im 1. Schritt */

	   do {
	       ledArray->SetPixel(Position.X + dx,Position.Y + dy,Col);/* I. Quadrant */
	       ledArray->SetPixel(Position.X - dx,Position.Y + dy,Col);/* II. Quadrant */
	       ledArray->SetPixel(Position.X - dx,Position.Y - dy,Col);/* III. Quadrant */
	       ledArray->SetPixel(Position.X + dx,Position.Y - dy,Col);/* IV. Quadrant */

	       if(dx == 150){
	    	   dx = 0;
	       }
	       e2 = 2*err;
	       if (e2 <  (2*dx+1)*b2) {

	    	   dx++;
	    	   err += (2*dx+1)*b2;
	       }
	       if (e2 > -(2*dy-1)*a2) {

	    	   dy--;
	    	   err -= (2*dy-1)*a2;
	       }
	   } while (dy >= 0);

	   while (dx++ < A) { /* fehlerhafter Abbruch bei flachen Ellipsen (b=1) */
		   ledArray->SetPixel(Position.X + dx,Position.Y,Col);/* -> Spitze der Ellipse vollenden */
		   ledArray->SetPixel(Position.X - dx,Position.Y,Col);
	   }
}

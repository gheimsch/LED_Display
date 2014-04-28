/******************************************************************************/
/*! \file EllipseClass.cpp
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
#include "EllipseClass.hpp"
#include <iostream>
/* ------------------------- module data declaration -------------------------*/

/* ----------------------- module procedure declaration ----------------------*/
EllipseClass::EllipseClass(int newX, int newY, int newA, int newB, uint16_t newCol) : A(newA), B(newB),Col(newCol){

	Position.X = newX;
	Position.Y = newY;

	std::cout << "LineClass created" << std::endl;
}


EllipseClass::~EllipseClass(){

	std::cout << "LineClass destroyed" << std::endl;
}

void EllipseClass::Draw(LEDArrayClass *ledArray){

	   char dx = 0, dy = B; /* im I. Quadranten von links oben nach rechts unten */
	   int a2 = A*A, b2 = B*B;
	   int err = b2-(2*B-1)*a2, e2; /* Fehler im 1. Schritt */

	   do {
	       ledArray->setPixel(Position.X + dx,Position.Y + dy,Col);/* I. Quadrant */
	       ledArray->setPixel(Position.X - dx,Position.Y + dy,Col);/* II. Quadrant */
	       ledArray->setPixel(Position.X - dx,Position.Y - dy,Col);/* III. Quadrant */
	       ledArray->setPixel(Position.X + dx,Position.Y - dy,Col);/* IV. Quadrant */

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
		   ledArray->setPixel(Position.X + dx,Position.Y,Col);/* -> Spitze der Ellipse vollenden */
		   ledArray->setPixel(Position.X - dx,Position.Y,Col);
	   }
}
/* ****************************************************************************/
/* End Header : EllipseClass.cpp */
/* ****************************************************************************/

/*
 * Arkanoid.hpp
 *
 *  Created on: Jan 28, 2016
 *      Author: Matteo Rotundo
 */

#ifndef ARKANOID_HPP_
#define ARKANOID_HPP_

#define TEST

#ifdef TEST

/* Macros useful in case of testing mode */




#include "Test/MockMatrix.hpp" // Test library

#define A 1
#define B 2
#define C 3
#define D 4

#define BLUE 0, 0, 7
#define BLACK 0, 0, 0


#endif

#ifdef NOTEST

/* When the library is used for the application */

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include "Test/MockMatrix.hpp" // Test library
#define A   A0
#define B   A1
#define C   A2
#define D   A3

#define BLUE matrix.Color333(0, 0, 7)
#define BLACK matrix.Color333(0, 0, 0)

#endif


#define CLK 8
#define OE  9
#define LAT 10

typedef enum Direction{LEFT, RIGHT} Direction;

class Vaus {
public:
	int dimVaus;	// Dimension of the Vaus
	int lastL, lastR; // y coordinates
	int x;	// coordinate x
	Vaus();
};

class MapGame {

#ifdef TEST
public:
	Vaus vaus;
	RGBmatrixPanel matrix;
#endif

#ifdef NOTEST
	RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);
	Vaus vaus;
#endif



public:
	void moveVaus(Direction dir);
	/*
	void resizeVaus(int amount);
	void growVaus(int amount);
	*/
	void displayVaus();

};
#endif /* ARKANOID_HPP_ */

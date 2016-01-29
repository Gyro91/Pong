/*
 * Arkanoid.hpp
 *
 *  Created on: Jan 28, 2016
 *      Author: Matteo Rotundo
 */

#ifndef ARKANOID_HPP_
#define ARKANOID_HPP_

#define NOTEST


// Constants and library for TESTING

#ifdef TEST

#include "Test/MockMatrix.hpp" // Test library

#define BLUE 0, 0, 7
#define BLACK 0, 0, 0


#endif

//  Constants and libraries for the application

#ifdef NOTEST

/* When the library is used for the application */

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library


#endif


typedef enum Direction{LEFT, RIGHT} Direction;

class Vaus {
public:
  int dimVaus;  // Dimension of the Vaus
  int lastL, lastR; // y coordinates
  int x;  // coordinate x
  Vaus();
};

class MapGame {

#ifdef TEST
public:
  Vaus vaus;
  RGBmatrixPanel matrix;
#endif

#ifdef NOTEST
public:
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




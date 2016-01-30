/*
 * Arkanoid.hpp
 *
 *  Created on: Jan 28, 2016
 *      Author: Matteo Rotundo
 */

#ifndef ARKANOID_HPP_
#define ARKANOID_HPP_

/* Starting position for the Vaus */
#define Vaus_yl 11
#define Vaus_yr 17
#define LineVaus 1

/* Rows&Columns for the Matrix */
#define RMATRIX 32
#define CMATRIX 32

/* Rows&Columns for the Wall */
#define RWALL 4
#define CWALL 32

#define NOTEST


// Constants and library for TESTING

#ifdef TEST

#include "Test/MockMatrix.hpp" // Test library

#define BLUE 0, 0, 7
#define BLACK 0, 0, 0


#endif

// Libraries for the application

#ifdef NOTEST

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library


#endif


typedef enum DirectionVaus{LEFT, RIGHT} DirectionVaus;
typedef enum DirectionBall{NL, N, NR, SL, S, SR} DirectionBall;


class Wall {
public:
	bool bricks[RWALL][CWALL];
	Wall();
};

class Vaus {
public:
  int dimVaus;  // Dimension of the Vaus
  int lastL, lastR; // y coordinates
  int x;  // coordinate x
  Vaus();
};

class Ball {
public:
	int x, y;
	DirectionBall dirB;
	Ball();
};

class MapGame {

#ifdef TEST
public:
  RGBmatrixPanel matrix;
#endif


public:
  Vaus vaus;
  Ball ball;

  void checkDirBall();
  void invertDirBall();
  void moveVaus(DirectionVaus dirV);
  void moveBall();
  void shotShore();
  bool checkImpactVaus(int x, int y);
  void modBallDirImpact(int x, int y);
  /*
  void resizeVaus(int amount);
  void growVaus(int amount);
  */
  void displayVaus();

};
#endif /* ARKANOID_HPP_ */




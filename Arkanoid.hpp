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
#define CWALL 20
#define OFFSET 5


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

class Brick {
public:
	int x1, y1, x2, y2;
};

class Pad1 {
public:
  unsigned char lastL, lastR; // y coordinates
  unsigned char x;  // coordinate x
  Pad1();
};

class Pad2 {
public:
  unsigned char lastL, lastR; // y coordinates
  unsigned char x;  // coordinate x
  Pad2();
};

class Ball {
public:
	unsigned char x, y;
	DirectionBall dirB;
	Ball();
};

class MapGame {

#ifdef TEST
public:
  RGBmatrixPanel matrix;
#endif

public:
  Pad1 pad1;
  Pad2 pad2;
  Ball ball;

  void checkDirBall();
  void invertDirBall();
  void movePad1(DirectionVaus dirV);
  void movePad2(DirectionVaus dirV);
  void moveBall();
  void shotShore();
  bool checkImpactPad1(int x, int y);
  bool checkImpactPad2(int x, int y);
  void modBallDirImpact(int x, int y);
  void modBallDirImpact2(int x, int y);
  bool checkImpactWall(int x, int y);

  void displayVaus();

};
#endif /* ARKANOID_HPP_ */




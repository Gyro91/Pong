/*
 * Pong.hpp
 *
 *  Created on: Jan 28, 2016
 *      Author: Matteo Rotundo
 */

#ifndef PONG_HPP_
#define PONG_HPP_

/* Starting position for the Vaus */
#define Pad_yL 11
#define Pad_yR 17
#define Pad1X 1
#define Pad2X 30

/* Rows&Columns for the Matrix */
#define RMATRIX 32
#define CMATRIX 32




#define NOTEST

extern unsigned char t_ball;
extern unsigned char t_pad1;
extern unsigned char t_pad2;

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


typedef enum DirectionPad{LEFT, RIGHT} DirectionPad;
typedef enum DirectionBall{NL, N, NR, SL, S, SR} DirectionBall;



class Pad {
public:
  unsigned char lastL, lastR; // y coordinates
  unsigned char x;  // coordinate x
  void movePad(DirectionPad);
  Pad(int coordx);
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
  Pad pad1 = Pad(1);
  Pad pad2 = Pad(30);
  Ball ball;

  void checkDirBall();
  void invertDirBall();
  void movePad1(DirectionPad dirV);
  void movePad2(DirectionPad dirV);
  void moveBall();
  void shotShore();
  bool checkImpactPad1(int x, int y);
  bool checkImpactPad2(int x, int y);
  void modBallDirImpact(int x, int y);
  void modBallDirImpact2(int x, int y);
  bool checkImpactWall(int x, int y);

  void displayVaus();

};
#endif /* PONG_HPP_ */




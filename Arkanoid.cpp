#include "Arkanoid.hpp"

unsigned char casual = 0;


Pad2::Pad2()
{
	lastL = Vaus_yl;
	lastR = Vaus_yr;
	x = 30;
}



Pad1::Pad1()
{
	lastL = Vaus_yl;
	lastR = Vaus_yr;
	x = LineVaus;
}

/* Constructor for the Ball */

Ball::Ball()
{
	x = LineVaus + 1;
	y = (Vaus_yl + Vaus_yr) / 2;
	dirB = N;
}

/* Useful only for Testing Mode */
void MapGame::displayVaus()
{
	#ifdef TEST
	matrix.drawLine(vaus.x, vaus.lastL,
			vaus.x, vaus.lastR, BLUE);
	#endif
}

/* It checks if there's an impact with the Paddle and assigned value
 * to the direction in order to be modified correctly in checkDirBall
 * If I assigned here a value of SR it's because i want that in that case
 * it will have a value of NL (inverted!)
 * */

void MapGame::modBallDirImpact(int x, int y)
{
	if (y > (pad1.lastL + 1) && y < (pad1.lastR - 1))
				ball.dirB = S;
	else if (y <= (pad1.lastL + 1) || y == (pad1.lastL - 1))
				ball.dirB = SR;
	else if (y >= (pad1.lastR - 1) || y == (pad1.lastR + 1))
				ball.dirB = SL;
}

void MapGame::modBallDirImpact2(int x, int y)
{
	if (y > (pad2.lastL + 1) && y < (pad2.lastR - 1))
				ball.dirB = N;
	else if (y <= (pad2.lastL + 1) || y == (pad2.lastL - 1))
				ball.dirB = NL;
	else if (y >= (pad2.lastR - 1) || y == (pad2.lastR + 1))
				ball.dirB = NR;
}


bool MapGame::checkImpactPad1(int x, int y)
{
bool result = false;
	switch(ball.dirB) {
	case S:
		if ((x - 1) == pad1.x && y <= pad1.lastR
				&& y>= pad1.lastL) {
			result = true;
			modBallDirImpact(x,y);
		}
		break;
	case SL:
		if ((x - 1) == pad1.x && (y - 1) <= pad1.lastR
				&& (y - 1) >= pad1.lastL) {
			result = true;
			modBallDirImpact(x,y);
		}
		break;
	case SR:
		if ((x - 1) == pad1.x && (y + 1) <= pad1.lastR
				&& (y + 1) >= pad1.lastL) {
			result = true;
			modBallDirImpact(x,y);		}
		break;
	}
	return result;
}


bool MapGame::checkImpactPad2(int x, int y)
{
bool result = false;
	switch(ball.dirB) {
	case N:
		if ((x + 1) == pad2.x && y <= pad2.lastR
				&& y>= pad2.lastL) {
			result = true;
			modBallDirImpact2(x,y);
		}
		break;
	case NL:
		if ((x + 1) == pad2.x && (y - 1) <= pad2.lastR
				&& (y - 1) >= pad2.lastL) {
			result = true;
			modBallDirImpact2(x,y);
		}
		break;
	case NR:
		if ((x + 1) == pad2.x && (y + 1) <= pad2.lastR
				&& (y + 1) >= pad2.lastL) {
			result = true;
			modBallDirImpact2(x,y);		}
		break;
	}
	return result;
}


/* It checks if ball must be inverted or it has to be done a hit shore */

void MapGame::checkDirBall()
{
	switch(ball.dirB) {
		case N:
			if ((ball.x + 1) >= RMATRIX ||
					checkImpactPad2(ball.x, ball.y))
				invertDirBall();
			break;
		case NR:
			if	((ball.y + 1) >= CMATRIX )
				shotShore();
			if ((ball.x + 1) >= RMATRIX ||
					checkImpactPad2(ball.x, ball.y))
				invertDirBall();
			break;
		case NL:
			if ((ball.y - 1) < 0)
				shotShore();
			if ((ball.x + 1) >= RMATRIX ||
					checkImpactPad2(ball.x, ball.y))
				invertDirBall();
			break;
		case S:
			if ((ball.x - 1) < 0 ||
					checkImpactPad1(ball.x, ball.y))
				invertDirBall();
			break;
		case SL:
			if ((ball.y - 1) < 0)
						shotShore();
			if ((ball.x - 1) < 0 ||
					checkImpactPad1(ball.x, ball.y))
				invertDirBall();

			break;
		case SR:
			if ((ball.y + 1) >= CMATRIX)
							shotShore();
			if ((ball.x - 1) < 0 ||
					checkImpactPad1((ball.x), (ball.y)))
							invertDirBall();

			break;
	}
}

/* It checks if there's an impact, then moves the ball */

void MapGame::moveBall()
{
	checkDirBall();

	switch(ball.dirB) {
		case N:
			ball.x++;
			break;
		case NR:
			ball.x++;
			ball.y++;
			break;
		case NL:
			ball.x++;
			ball.y--;
			break;
		case S:
			ball.x--;
			break;
		case SL:
			ball.x--;
			ball.y--;
			break;
		case SR:
			ball.x--;
			ball.y++;
			break;
	}
}

/* It changes the direction for a shot shore */

void MapGame::shotShore()
{
	switch(ball.dirB) {
		case N:
			ball.dirB = S;
			break;
		case NR:
			ball.dirB = NL;
			break;
		case NL:
			ball.dirB = NR;
			break;
		case S:
			ball.dirB = N;
			break;
		case SR:
			ball.dirB = SL;
			break;
		case SL:
			ball.dirB = SR;
			break;

	}
}

/* It inverts the direction of the Ball */

void MapGame::invertDirBall()
{
	switch(ball.dirB) {
		case N:
			ball.dirB = S;
			/*
			if (casual == 0) {
				ball.dirB = SR;
				casual = 1;
			}
			else {
				casual = 0;
				ball.dirB = SL;
			}*/
			break;
		case NR:
			ball.dirB = SR;
			break;
		case NL:
			ball.dirB = SL;
			break;
		case S:
			ball.dirB = N;
			break;
		case SL:
			ball.dirB = NR;
			break;
		case SR:
			ball.dirB = NL;
			break;
	}
}


/* Moves the Paddle in the passed direction */

void MapGame::movePad1(DirectionVaus dir)
{
	#ifdef TEST
	matrix.drawLine(vaus.x, vaus.lastL,
			vaus.x, vaus.lastR, BLACK);
	#endif

  if (dir == LEFT && pad1.lastL > 0) {
	  pad1.lastL--;
	  pad1.lastR--;
  }
  else if (dir == RIGHT && pad1.lastR < 31) {
	  pad1.lastL++;
	  pad1.lastR++;
  }

  #ifdef TEST
  displayVaus();
  #endif
}


/* Moves the Paddle in the passed direction */

void MapGame::movePad2(DirectionVaus dir)
{
	#ifdef TEST
	matrix.drawLine(vaus2.x, vaus2.lastL,
			vaus2.x, vaus2.lastR, BLACK);
	#endif

  if (dir == LEFT && pad2.lastL > 0) {
	  pad2.lastL--;
	  pad2.lastR--;
  }
  else if (dir == RIGHT && pad2.lastR < 31) {
	  pad2.lastL++;
	  pad2.lastR++;
  }

  #ifdef TEST
  displayVaus();
  #endif
}

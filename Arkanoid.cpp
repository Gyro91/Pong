#include "Arkanoid.hpp"

int casual = 0;
/* Constructor for the Wall */

Wall::Wall()
{
	for (int i=0; i<RWALL; i++)
		for(int j=0; j<CWALL; j++)
			bricks[i][j] = true;
}

/* Constructor for the Vaus */

Vaus::Vaus()
{
	dimVaus = 5;
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

/* It checks if there's an impact with the Vaus and assigned value
 * to the direction in order to be modified correctly in checkDirBall
 * If I assigned here a value of SR it's because i want that in that case
 * it will have a value of NL (inverted!)
 * */

void MapGame::modBallDirImpact(int x, int y)
{
	if (y > (vaus.lastL + 1) && y < (vaus.lastR - 1))
				ball.dirB = S;
	else if (y <= (vaus.lastL + 1) || y == (vaus.lastL - 1))
				ball.dirB = SR;
	else if (y >= (vaus.lastR - 1) || y == (vaus.lastR + 1))
				ball.dirB = SL;
}


bool MapGame::checkImpactVaus(int x, int y)
{
bool result = false;
	switch(ball.dirB) {
	case S:
		if ((x - 1) == vaus.x && y <= vaus.lastR
				&& y>= vaus.lastL) {
			result = true;
			modBallDirImpact(x,y);
		}
		break;
	case SL:
		if ((x - 1) == vaus.x && (y - 1) <= vaus.lastR
				&& (y - 1) >= vaus.lastL) {
			result = true;
			modBallDirImpact(x,y);
		}
		break;
	case SR:
		if ((x - 1) == vaus.x && (y + 1) <= vaus.lastR
				&& (y + 1) >= vaus.lastL) {
			result = true;
			modBallDirImpact(x,y);		}
		break;
	}
	return result;
}

/* It checks if ball must be inverted or it has to be done a hit shore */

void MapGame::checkDirBall()
{
	switch(ball.dirB) {
		case N:
			if ((ball.x + 1) >= RMATRIX)
				invertDirBall();
			break;
		case NR:
			if	((ball.y + 1) >= CMATRIX)
				shotShore();
			else if ((ball.x + 1) >= RMATRIX)
				invertDirBall();
			break;
		case NL:
			if ((ball.y - 1) < 0)
				shotShore();
			else if ((ball.x + 1) >= RMATRIX)
				invertDirBall();
			break;
		case S:
			if ((ball.x - 1) < 0 ||
					checkImpactVaus((ball.x), ball.y))
				invertDirBall();
			break;
		case SL:
			if ((ball.y - 1) < 0)
						shotShore();
			if ((ball.x - 1) < 0 ||
					checkImpactVaus((ball.x), (ball.y)))
				invertDirBall();

			break;
		case SR:
			if ((ball.y + 1) >= CMATRIX)
							shotShore();
			if ((ball.x - 1) < 0 ||
					checkImpactVaus((ball.x), (ball.y)))
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
			if (casual == 0) {
				ball.dirB = SR;
				casual = 1;
			}
			else {
				casual = 0;
				ball.dirB = SL;
			}
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


/* Moves the Vaus in the passed direction */

void MapGame::moveVaus(DirectionVaus dir)
{
	#ifdef TEST
	matrix.drawLine(vaus.x, vaus.lastL,
			vaus.x, vaus.lastR, BLACK);
	#endif

  if (dir == LEFT && vaus.lastL > 0) {
    vaus.lastL--;
    vaus.lastR--;
  }
  else if (dir == RIGHT && vaus.lastR < 31) {
    vaus.lastL++;
    vaus.lastR++;
  }

  #ifdef TEST
  displayVaus();
  #endif
}


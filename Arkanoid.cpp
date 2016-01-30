#include "Arkanoid.hpp"

#define ROWS 32
#define COLUMNS 32


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
	matrix.drawLine(vaus.x, vaus.lastL, vaus.x, vaus.lastR, BLUE);
	#endif
}

/* It checks if there's an impact with the Vaus and assigned value
 * to the direction in order to be modified correctly in checkDirBall
 * If I assigned here a value of SR it's because i want that in that case
 * it will have a value of NL (inverted!)
 * */

bool MapGame::checkImpactVaus(int x, int y)
{
bool result = false;
	switch(ball.dirB) {
	case S:
		if ((x - 1) == vaus.x && y <= vaus.lastR
				&& y>= vaus.lastL) {
			result = true;
			if (y > vaus.lastL && y < vaus.lastR)
				ball.dirB = S;
			else if (y == vaus.lastL || y == (vaus.lastL - 1))
				ball.dirB = SR;
			else if (y == vaus.lastR || y == (vaus.lastR + 1))
				ball.dirB = SL;
		}
		break;
	case SL:
		if ((x - 1) == vaus.x && (y - 1) <= vaus.lastR
				&& (y - 1) >= vaus.lastL) {
			result = true;
			if (y > vaus.lastL && y < vaus.lastR)
							ball.dirB = S;
			else if (y == vaus.lastL || y == (vaus.lastL - 1))
				ball.dirB = SR;
			else if (y == vaus.lastR || y == (vaus.lastR + 1))
						ball.dirB = SL;
		}
		break;
	case SR:
		if ((x - 1) == vaus.x && (y - 1) <= vaus.lastR
				&& (y + 1) >= vaus.lastL) {
			result = true;
			if (y > vaus.lastL && y < vaus.lastR)
				ball.dirB = S;
			else if (y == vaus.lastL || y == (vaus.lastL - 1))
				ball.dirB = SR;
			else if (y == vaus.lastR || y == (vaus.lastR + 1))
				ball.dirB = SL;
		}
		break;
	}
	return result;
}

void MapGame::checkDirBall()
{
	switch(ball.dirB) {
		case N:
			if ((ball.x + 1) >= ROWS)
				invertDirBall();
			break;
		case NR:
			if	((ball.y + 1) >= COLUMNS)
				shotShore();
			else if ((ball.x + 1) >= ROWS)
				invertDirBall();
			break;
		case NL:
			if ((ball.y - 1) < 0)
				shotShore();
			else if ((ball.x + 1) >= ROWS)
				invertDirBall();
			break;
		case S:
			if ((ball.x - 1) < 0 || checkImpactVaus((ball.x), ball.y))
				invertDirBall();
			break;
		case SL:
			if ((ball.y - 1) < 0)
				shotShore();
			else if ((ball.x - 1) < 0 || checkImpactVaus((ball.x), (ball.y)))
				invertDirBall();
			break;
		case SR:
			if ((ball.y + 1) >= COLUMNS)
				shotShore();
			else if ((ball.x - 1) < 0 || checkImpactVaus((ball.x), (ball.y)))
				invertDirBall();
			break;
	}
}

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


void MapGame::invertDirBall()
{
	switch(ball.dirB) {
		case N:
			ball.dirB = S;
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



void MapGame::moveVaus(DirectionVaus dir)
{
	#ifdef TEST
	matrix.drawLine(vaus.x, vaus.lastL, vaus.x, vaus.lastR, BLACK);
	#endif

  if (dir == LEFT && vaus.lastL > 0) {
    vaus.lastL--;
    vaus.lastR--;
  }
  else if (dir == RIGHT && vaus.lastR < 31) {
    vaus.lastL++;
    vaus.lastR++;
  }

  displayVaus();
}


#include "Arkanoid.hpp"

#define ROWS 32
#define COLUMNS 32

Vaus::Vaus()
{
	dimVaus = 5;
	lastL = Vaus_yl;
	lastR = Vaus_yr;
	x = LineVaus;
}

Ball::Ball()
{
	x = LineVaus + 1;
	y = (Vaus_yl + Vaus_yr) / 2;
	dirB = N;
}

void MapGame::displayVaus()
{
	#ifdef TEST
	matrix.drawLine(vaus.x, vaus.lastL, vaus.x, vaus.lastR, BLUE);
	#endif
}

bool MapGame::checkImpactVaus(int x, int y)
{
bool result = false;
	switch(ball.dirB) {
	case S:
		if ((x - 1) == vaus.x && y <= vaus.lastR
				&& y>= vaus.lastL) {
			result = true;
			if (y < (vaus.lastL + vaus.lastR) / 2)
				ball.dirB = SR;
			else if (y > (vaus.lastL + vaus.lastR) / 2)
				ball.dirB = SL;
		}
		break;
	case SL:
		if ((x - 1) == vaus.x && (y - 1) <= vaus.lastR
				&& (y - 1) >= vaus.lastL) {
			result = true;
			if (y < (vaus.lastL + vaus.lastR) / 2)
				ball.dirB = SR;
			else if (y > (vaus.lastL + vaus.lastR) / 2)
						ball.dirB = SL;
		}
		break;
	case SR:
		if ((x - 1) == vaus.x && (y - 1) <= vaus.lastR
				&& (y + 1) >= vaus.lastL) {
			result = true;
			if (y < (vaus.lastL + vaus.lastR) / 2)
				ball.dirB = SR;
			else if (y > (vaus.lastL + vaus.lastR) / 2)
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
			if ((ball.x + 1) >= ROWS || (ball.y + 1) >= COLUMNS)
				invertDirBall();
			break;
		case NL:
			if ((ball.x + 1) >= ROWS || (ball.y - 1) < 0)
				invertDirBall();
			break;
		case S:
			if ((ball.x - 1) < 0 || checkImpactVaus((ball.x), ball.y))
				invertDirBall();
			break;
		case SL:
			if ((ball.x - 1) < 0 || (ball.y - 1) < 0
					|| checkImpactVaus((ball.x), (ball.y)))
				invertDirBall();
			break;
		case SR:
			if ((ball.x - 1) < 0 || (ball.y + 1) >= COLUMNS
					|| checkImpactVaus((ball.x), (ball.y)))
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

void MapGame::invertDirBall()
{
	switch(ball.dirB) {
		case N:
			ball.dirB = S;
			break;
		case NR:
			ball.dirB = SL;
			break;
		case NL:
			ball.dirB = SR;
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


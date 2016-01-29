#include "Arkanoid.hpp"



Vaus::Vaus()
{
	dimVaus = 5;
	lastL = 13;
	lastR = 17;
	x = 1;
}

void MapGame::displayVaus()
{
 	 matrix.drawLine(vaus.x, vaus.lastL, vaus.x, vaus.lastR, BLUE);
}


void MapGame::moveVaus(Direction dir)
{
	matrix.drawLine(vaus.x, vaus.lastL, vaus.x, vaus.lastR, BLACK);

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

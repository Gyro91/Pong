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
	#ifdef TEST
	matrix.drawLine(vaus.x, vaus.lastL, vaus.x, vaus.lastR, BLUE);
	#endif
}


void MapGame::moveVaus(Direction dir)
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


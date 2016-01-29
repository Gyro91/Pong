#include "MockMatrix.hpp"
#include <iostream>

using namespace std;



void Led::turn_OFF()
{
	state = false;
}

void Led::turn_ON()
{
	state = true;
}

/* It turns OFF an RGB led */

void RGB_Led::turn_OFF()
{
	state = false;
}


/* It turns ON an RGB led with color given by the parameters */

void RGB_Led::turn_ON(int R, int G, int B)
{
	state = true;
	color_R = R;
	color_G = G;
	color_G = B;
}

RGBmatrixPanel::RGBmatrixPanel()
{


	for (int i=0; i<ROWS; i++)
		for (int j=0; j<COLUMNS; j++) {
			matrix[i][j].state = false;
			matrix[i][j].color_R = 0;
			matrix[i][j].color_G = 0;
			matrix[i][j].color_B = 0;
		}
}


void RGBmatrixPanel::drawPixel(int x, int y, int R, int G, int B)
{
	matrix[x][y].turn_ON(R, G, B);
}

void RGBmatrixPanel::drawLine(int x1, int y1, int x2, int y2,
		int R, int G, int B)
{
	if (x1 == x2)
		for (int i=y1; i<=y2; i++)
			matrix[x1][i].turn_ON(R, G, B);
	else if (y1 == y2)
		for (int i=x1; i<=x2; i++)
			matrix[i][y1].turn_ON(R, G, B);
	else {
		int j = y1;
		if (x2 > x1)
			for (int i = x1; i<= x2; i++)
				matrix[i][j++].turn_ON(R, G, B);
		else
			for (int i = x2; i<= x1; i++)
				matrix[i][j--].turn_ON(R, G, B);

	}

}

void RGBmatrixPanel::fill(int R, int G, int B)
{
	bool state = (R == 0 && G == 0 && B == 0) ? false : true;

	for (int i=0; i<ROWS; i++)
		for (int j=0; j<COLUMNS; j++)
			if (state)
				matrix[i][j].turn_ON(R, G, B);
			else
				matrix[i][j].turn_OFF();
}

void RGBmatrixPanel::print()
{
	for (int i= (ROWS - 1); i>=0; i--) {

		for (int j=0; j<COLUMNS; j++) {
			if (matrix[i][j].state)
				cout << "1";
			else
				cout << "0";
		}
		cout << endl;
	}

}

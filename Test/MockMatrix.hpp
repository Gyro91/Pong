#include <iostream>
#define ROWS 32
#define COLUMNS 32
using namespace std;

class Led {
public:
	bool state;
public:
    virtual void turn_ON();
    virtual void turn_OFF();
};


class RGB_Led : public Led {
public:
	int color_R;
	int color_G;
	int color_B;
	void turn_ON(int R, int G, int B);
	void turn_OFF();
};


class MockMatrix {
private:
	 RGB_Led matrix[ROWS][COLUMNS];

public:
	MockMatrix();
	void drawPixel(int x, int y, int R, int G, int B);
	void drawLine(int x1, int y1, int x2, int y2, int R, int G, int B);
	void fill(int R, int G, int B);
	void print();
};


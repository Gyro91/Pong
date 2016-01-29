#include "MockMatrix.hpp"

int main() {
	RGBmatrixPanel m;
	m.drawLine(13, 1, 17, 1, 0, 0, 0);
	m.print();
	cout << endl;

	return 0;
}

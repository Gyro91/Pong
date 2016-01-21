#include "MockMatrix.hpp"

int main() {
	MockMatrix m;
	m.drawLine(0,0, 31, 31, 0, 0, 0);
	m.print();
	m.fill(0, 0 , 0);
	cout << endl;
	m.print();

	return 0;
}

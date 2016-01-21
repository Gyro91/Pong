#include "MockButton.hpp"

// Number of buttons of the pad;
#define NBUTTONS 3
// Indexes of the specific buttons
#define ARROW_L 0
#define ARROW_R 1
#define FIRE 2

class MockPad {
public:
	MockButton pad[NBUTTONS];

	void press(int button);
	void release(int button);
	bool digitalRead(int button);
};

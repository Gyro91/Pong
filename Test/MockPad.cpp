#include "MockPad.hpp"

void MockPad::release(int button)
{
	pad[button].release();
}

void MockPad::press(int button)
{
	pad[button].press();
}

bool MockPad::digitalRead(int button)
{
	return pad[button].state;
}


#include "MockButton.hpp"

void MockButton::press()
{
	state = true;
}

void MockButton::release()
{
	state = false;
}

bool MockButton::digitalRead()
{
	return state;
}


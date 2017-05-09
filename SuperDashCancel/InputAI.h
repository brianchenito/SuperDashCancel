#pragma once
#include "InputDevice.h"
#include <vector>
#include <stdlib.h>     /* srand, rand */

class InputAI :public InputDevice
{private:
	bool pressed[8];
	bool held[8];
	std::vector<std::vector<std::vector<bool>>>Sequences;
	int timer;
	int currentseq;
	int seqstage;
	public:
	InputAI(GLFWwindow * window);
	~InputAI();
	void FixedStep();
	bool Pressed(Input b);
	bool Held(Input b);
};


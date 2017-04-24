#pragma once
#include "InputDevice.h"
class InputKeyboard :public InputDevice
{
private:

	int keybinds[6];
	bool pressed[6];
	bool held[6];
public:
	InputKeyboard(GLFWwindow * window,bool isPlayer1);
	~InputKeyboard();
	 void FixedStep();
	 bool Pressed(Input b);
	 bool Held(Input b);
	  
};


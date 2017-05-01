#pragma once
#ifndef SDC_INPUT_KEYBOARD_H
#define SDC_INPUT_KEYBOARD_H


#include "InputDevice.h"
class InputKeyboard :public InputDevice
{
private:

	int keybinds[8];
	bool pressed[8];
	bool held[8];
public:
	InputKeyboard(GLFWwindow * window,bool isPlayer1);
	~InputKeyboard();
	 void FixedStep();
	 bool Pressed(Input b);
	 bool Held(Input b);
	  
};

#endif // !SDC_INPUT_KEYBOARD_H
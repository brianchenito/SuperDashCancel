#pragma once
#ifndef SDC_INPUT_JOYSTICK_H
#define SDC_INPUT_JOYSTICK_H


#include "InputDevice.h"
class InputJoyStick :public InputDevice
{
private:
	bool pressed[8];
	bool held[8];
public:
	InputJoyStick(GLFWwindow * window, int id);
	~InputJoyStick();
	void FixedStep();
	bool Pressed(Input b);
	bool Held(Input b);
};

#endif // !SDC_INPUT_JOYSTICK_H
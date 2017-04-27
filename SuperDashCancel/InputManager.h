#pragma once
#ifndef SDC_INPUT_MANAGER_H
#define SDC_INPUT_MANAGER_H



#include <vector>
#include <algorithm>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Input.h"
#include "InputKeyboard.h"

class InputManager
{
private:
	std::vector<InputDevice*> Devices;
	InputDevice* Player1Device;
	InputDevice* Player2Device;
	GLFWwindow* window;
public:

	InputManager();
	void Init(GLFWwindow* window);
	~InputManager();
	void FixedStep();
	static void joystickCB(int joy, int event);
	// stuff for polling from all controllers
	bool GlobalPressed(Input b);
	bool GlobalHeld(Input b);
	//stuff for polling from a specific player
	bool Pressed(Input b, bool isPlayer1);
	bool Held(Input b, bool isPlayer1);
};

#endif // !SDC_INPUT_MANAGER_H
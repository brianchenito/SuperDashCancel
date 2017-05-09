#pragma once
#ifndef SDC_INPUT_MANAGER_H
#define SDC_INPUT_MANAGER_H



#include <vector>
#include <algorithm>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Input.h"
#include "InputKeyboard.h"
#include "InputJoyStick.h"
#include "InputAI.h"
class InputManager
{
private:
	static std::vector<InputDevice*> Devices;

	static GLFWwindow* window;
public:
	static InputDevice* Player1Device;
	static InputDevice* Player2Device;
	static InputAI* robot;

	static void Init(GLFWwindow* window);

	static void FixedStep();
	static void Reconnect();
	static void joystickCB(int joy, int event);
	// stuff for polling from all controllers
	static bool GlobalPressed(Input b);
	static bool GlobalHeld(Input b);
	//stuff for polling from a specific player
	static bool Pressed(Input b, bool isPlayer1);
	static bool Held(Input b, bool isPlayer1);
};

#endif // !SDC_INPUT_MANAGER_H
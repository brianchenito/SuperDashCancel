#pragma once
#include "Input.h"
#include <GLFW/glfw3.h>
#include <string>
#include<iostream>
class InputDevice
{
	
public:
	GLFWwindow* window;
	std::string Label;
	InputDevice(GLFWwindow* window);
	~InputDevice();
	 virtual void FixedStep()=0;
	 virtual bool Pressed(Input b)=0;
	 virtual bool Held(Input b)=0;

};


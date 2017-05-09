#include "InputJoyStick.h"




InputJoyStick::InputJoyStick(GLFWwindow * window, int id) :InputDevice(window)
{
	
	Label = glfwGetJoystickName(id);
	FlagID = id;
	for (int i = 0; i < 8; i++)
	{
		pressed[i] = false;
		held[i] = false;
	}
	std::cout << "Joystick " << glfwGetJoystickName(id)<<" "<< id << " Instantiated.\n\n";
}

InputJoyStick::~InputJoyStick()
{
}

void InputJoyStick::FixedStep()
{
	for (int i = 0; i < 8; i++)
	{
		pressed[i] = false;
	}
	inputThisFrame = false;
	if (glfwJoystickPresent(FlagID) == GLFW_TRUE) 
	{
		// do stuff for directionals
		int axiscount;
	
		const  float* axes = glfwGetJoystickAxes(FlagID, &axiscount);
		if (axiscount >= 2)
		{
			/* if your stick doesnt have at least 2 axes
			idk what to say, why are you playing this on
			like a steering wheel dude*/
			if (axes[0] < -0.35f)
			{
				pressed[Input_Left] = !held[Input_Left];
				held[Input_Left] = true;
				inputThisFrame = true;
			}
			else held[Input_Left] = false;

			if (axes[0] > 0.35f)
			{
				pressed[Input_Right] = !held[Input_Right];
				held[Input_Right] = true;
				inputThisFrame = true;
			}
			else held[Input_Right] = false;




			if (((std::string)glfwGetJoystickName(FlagID)).find("360") != std::string::npos)
			{
				if (axes[1] < -0.35f)
				{
					pressed[Input_Down] = !held[Input_Down];
					held[Input_Down] = true;
					inputThisFrame = true;

				}
				else held[Input_Down] = false;

				if (axes[1] > 0.35f)
				{
					pressed[Input_Up] = !held[Input_Up];
					held[Input_Up] = true;
					inputThisFrame = true;
				}
				else held[Input_Up] = false;
			}
			else 
			{
				if (axes[1] > 0.35f)
				{
					pressed[Input_Down] = !held[Input_Down];
					held[Input_Down] = true;
					inputThisFrame = true;

				}
				else held[Input_Down] = false;

				if (axes[1] < -0.35f)
				{
					pressed[Input_Up] = !held[Input_Up];
					held[Input_Up] = true;
					inputThisFrame = true;
				}
				else held[Input_Up] = false;
			}

		}
		int buttoncount;
		const unsigned char* buttons = glfwGetJoystickButtons(FlagID, &buttoncount);
	
		bool lightFlag = false;
		bool heavyFlag = false;
		for (int i = 0; i < buttoncount; i++) 
		{
			if (buttons[i] == GLFW_PRESS) 
			{
				if (i % 2 == 0&&!lightFlag) 
				{
					pressed[Input_Light] = !held[Input_Light];
					held[Input_Light] = true;
					lightFlag = true;
					inputThisFrame = true;
				}
				else if (i % 2 != 0 && !heavyFlag) 
				{
					pressed[Input_Heavy] = !held[Input_Heavy];
					held[Input_Heavy] = true;
					heavyFlag = true;
					inputThisFrame = true;
				}
			}
		}
		if (!lightFlag)	held[Input_Light] = false;
		if (!heavyFlag)	held[Input_Heavy] = false;
	}
}

bool InputJoyStick::Pressed(Input b)
{
	return pressed[(int)b];
}

bool InputJoyStick::Held(Input b)
{
	return held[(int)b];
}

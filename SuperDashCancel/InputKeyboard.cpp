#include "InputKeyboard.h"

InputKeyboard::InputKeyboard(GLFWwindow * window, bool isPlayer1):InputDevice(window)
{
	if (isPlayer1) 
	{
		Label = "Keyboard 0";
		//index corresponds to the value of the Input Enums
		keybinds[0] = GLFW_KEY_W;
		keybinds[1] = GLFW_KEY_S;
		keybinds[2] = GLFW_KEY_A;
		keybinds[3] = GLFW_KEY_D;
		keybinds[4] = GLFW_KEY_V;
		keybinds[5] = GLFW_KEY_B;
		
	}
	else 
	{
		Label = "Keyboard 1";
		keybinds[0] = GLFW_KEY_UP;
		keybinds[1] = GLFW_KEY_DOWN;
		keybinds[2] = GLFW_KEY_LEFT;
		keybinds[3] = GLFW_KEY_RIGHT;
		keybinds[4] = GLFW_KEY_KP_1;
		keybinds[5] = GLFW_KEY_KP_2;
	}
	for (int i = 0; i < 6; i++) 
	{ 
		pressed[i] = false; 
		held[i] = false;
	}
}


InputKeyboard::~InputKeyboard()
{

}

void InputKeyboard::FixedStep()
{
	for (int i = 0; i < 6; i++) 
	{
		if (glfwGetKey(window, keybinds[i]) == GLFW_PRESS) 
		{
			pressed[i] = !held[i];
			
			held[i] =true;
			
			//std::cout << "PRESSED " << keybinds[i] << "\n";
		}
		else held[i] = false;

	}
}

bool InputKeyboard::Pressed(Input b)
{
	return pressed[(int)b];
}

bool InputKeyboard::Held(Input b)
{
	return held[(int)b];

}

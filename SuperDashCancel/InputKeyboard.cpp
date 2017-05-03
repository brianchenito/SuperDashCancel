#include "InputKeyboard.h"

InputKeyboard::InputKeyboard(GLFWwindow * window, bool isPlayer1):InputDevice(window)
{
	FlagID = -1;
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
		keybinds[6] = GLFW_KEY_ENTER;
		keybinds[7] = GLFW_KEY_ESCAPE;

	}
	else 
	{
		Label = "Keyboard 1";
		keybinds[0] = GLFW_KEY_UP;
		keybinds[1] = GLFW_KEY_DOWN;
		keybinds[2] = GLFW_KEY_LEFT;
		keybinds[3] = GLFW_KEY_RIGHT;
		keybinds[4] = GLFW_KEY_PERIOD;
		keybinds[5] = GLFW_KEY_SLASH;
		keybinds[7] = GLFW_KEY_ESCAPE;

	}
	for (int i = 0; i < 8; i++) 
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

	for (int i = 0; i < 8; i++) 
	{
		pressed[i] = false;
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


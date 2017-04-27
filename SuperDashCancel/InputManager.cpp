#include "InputManager.h"

InputManager::InputManager()
{

}
void InputManager::Init(GLFWwindow * window)
{
	this->window = window;
	glfwSetJoystickCallback(joystickCB);
	//instantiate the default controllers, keyboard 1 and keyboard 2.
	Devices.push_back(new InputKeyboard(window, true));
	Devices.push_back(new InputKeyboard(window, false));
	Player1Device = Devices[0];
	Player2Device = Devices[1];
}
InputManager::~InputManager()
{
}

void InputManager::FixedStep()
{
	

	for (int i = 0; i < Devices.size(); i++) 
	{
		//std::cout << Devices[i]->Label << "\n";
		Devices[i]->FixedStep(); 
	}
}

void InputManager::joystickCB(int joy, int event)
{
	std::cout << "joystick event procced\n";
}

bool InputManager::GlobalPressed(Input b)
{
	
	for (int i = 0; i<Devices.size(); i++)
	{
		if (Devices[i]->Pressed(b))return true;
	}
	return false;
}

bool InputManager::GlobalHeld(Input b)
{
	for (int i = 0; i<Devices.size(); i++)
	{
		if (Devices[i]->Held(b))return true;
	}
	return false; 
}



bool InputManager::Pressed(Input b, bool isPlayer1)
{
	if (isPlayer1)return Player1Device->Pressed(b);
	else return Player2Device->Pressed(b);
}

bool InputManager::Held(Input b, bool isPlayer1)
{
	if (isPlayer1)return Player1Device->Held(b);
	else return Player2Device->Held(b);
}


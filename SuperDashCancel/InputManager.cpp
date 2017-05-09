#include "InputManager.h"
std::vector<InputDevice*> InputManager::Devices= std::vector<InputDevice*>();
InputDevice* InputManager::Player1Device = 0;
InputDevice* InputManager::Player2Device = 0;
GLFWwindow* InputManager::window = 0;
InputAI* InputManager::robot = 0;
void InputManager::Init(GLFWwindow * window)
{
	InputManager::window = window;
	robot = new InputAI(window);

	glfwSetJoystickCallback(joystickCB);
	//instantiate the default controllers, keyboard 1 and keyboard 2.
	Devices.push_back(new InputKeyboard(window, true));
	Devices.push_back(new InputKeyboard(window, false));
	//Player1Device = Devices[0];
	//Player2Device = Devices[1];
	for (int i = 0; i <= GLFW_JOYSTICK_LAST;i++) 
	{
		if (glfwJoystickPresent(i) == GLFW_TRUE) 
		{
			Devices.push_back(new InputJoyStick(window, i));
		}
	}
	Reconnect();

}


void InputManager::FixedStep()
{
	

	for (int i = 0; i < Devices.size(); i++) 
	{
		//std::cout << Devices[i]->Label << "\n";
		Devices[i]->FixedStep(); 
	}
	if(Player2Device==robot)robot->FixedStep();
}

void InputManager::Reconnect()
{
	Player1Device = Devices[0];
	Player2Device = Devices[1];
	//try to give player 2 the newest joystick
	int player2track;
	for (int i = Devices.size() - 1; i > 1; i--) 
	{
		if (Devices[i]->FlagID != -1 && glfwJoystickPresent(Devices[i]->FlagID) == GLFW_TRUE) 
		{
			Player2Device = Devices[i];
			player2track = i;
			break;
		}
	}
	// if player 2 has a stick, try to give player 1 a stick
	if (Player2Device != Devices[1]) 
	{
		for (int i = player2track - 1; i > 1; i--) 
		{
			if (Devices[i]->FlagID != -1 && glfwJoystickPresent(Devices[i]->FlagID) == GLFW_TRUE)
			{
				Player1Device = Devices[i];
				break;
			}
		}
	}
}

void InputManager::joystickCB(int joy, int event)
{
	std::cout << "joystick event procced\n";
	if (event == GLFW_CONNECTED) 
	{
		// check if this joystick is already instantiated
		bool alreadexists = false;
		for (int i = 0; i < Devices.size(); i++) 
		{
			if (Devices[i]->FlagID == joy) 
			{
				alreadexists = true;
				break;
			}
		}
		// if not, instantiate.
		if (!alreadexists)Devices.push_back(new InputJoyStick(window, joy));
	}
	Reconnect();

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
	if (isPlayer1&&Player1Device!=0)return Player1Device->Pressed(b);
	else if(!isPlayer1&&Player2Device != 0) return Player2Device->Pressed(b);
	return false;
}

bool InputManager::Held(Input b, bool isPlayer1)
{
	if (isPlayer1&&Player1Device != 0)return Player1Device->Held(b);
	else if (!isPlayer1&&Player2Device != 0) return Player2Device->Held(b);
	return false;
}


#include "ButtonLaunchSP.h"



ButtonLaunchSP::ButtonLaunchSP()
{
}

ButtonLaunchSP::ButtonLaunchSP(App * a, FontEngine * f, std::string s, glm::vec2 Pos, float fontscale, glm::vec3 col):Button(f, s, Pos, fontscale, col)
{
	app = a;
}


void ButtonLaunchSP::Activate()
{
	InputManager::Player2Device = InputManager::robot;
	for (int i = InputManager::Devices.size() - 1; i > 1; i--)
	{
		if (InputManager::Devices[i]->FlagID != -1 && glfwJoystickPresent(InputManager::Devices[i]->FlagID) == GLFW_TRUE)
		{
			InputManager::Player1Device = InputManager::Devices[i];
			break;
		}
	}	
	app->SwitchScene("GameScreen");
}

ButtonLaunchSP::~ButtonLaunchSP()
{
}

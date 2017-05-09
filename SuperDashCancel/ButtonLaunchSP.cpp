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
	app->SwitchScene("GameScreen");
}

ButtonLaunchSP::~ButtonLaunchSP()
{
}

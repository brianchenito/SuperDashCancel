#include "ButtonLaunchSP.h"



ButtonLaunchSP::ButtonLaunchSP()
{
}


ButtonLaunchSP::ButtonLaunchSP(App* a, FontEngine * f, std::string s, glm::vec2 Pos, float fontscale, glm::vec3 col) :Button(f, s, Pos, fontscale, col)
{
	app = a;
}

void ButtonLaunchSP::Activate()
{
	//std::cout << "fire";
	app->SwitchScene("MPReadyUpScreen");
}

ButtonLaunchSP::~ButtonLaunchSP()
{
}

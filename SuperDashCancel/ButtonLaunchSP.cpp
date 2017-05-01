#include "ButtonLaunchSP.h"



ButtonLaunchSP::ButtonLaunchSP()
{
}


ButtonLaunchSP::ButtonLaunchSP(App* a, FontEngine * f, std::string s, Vec2 Pos, float fontscale, Color col) :Button(f, s, Pos, fontscale, col)
{
	app = a;
}

void ButtonLaunchSP::Activate()
{
	std::cout << "fire";
	app->SwitchScene("MPReadyUpScreen");
}

ButtonLaunchSP::~ButtonLaunchSP()
{
}

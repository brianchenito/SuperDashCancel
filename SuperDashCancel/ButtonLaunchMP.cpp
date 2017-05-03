#include "ButtonLaunchMP.h"



ButtonLaunchMP::ButtonLaunchMP()
{
}


ButtonLaunchMP::ButtonLaunchMP(App* a, FontEngine * f, std::string s, glm::vec2 Pos, float fontscale, glm::vec3 col) :Button(f, s, Pos, fontscale, col)
{
	app = a;
}

void ButtonLaunchMP::Activate()
{
	//std::cout << "fire";
	app->SwitchScene("MPReadyUpScreen");
}

ButtonLaunchMP::~ButtonLaunchMP()
{
}

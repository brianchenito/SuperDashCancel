#pragma once
#ifndef SDC_BUTTON_LAUNCHMP_H
#define SDC_BUTTON_LAUNCHMP_H
#include "Button.h"
#include "App.h"
class ButtonLaunchMP :
	public Button
{
	App* app;
public:
	ButtonLaunchMP();
	ButtonLaunchMP(App* a,FontEngine*f, std::string s, glm::vec2  Pos, float fontscale, glm::vec3 col);
	void Activate();
	~ButtonLaunchMP();
};

#endif
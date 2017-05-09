#pragma once
#include "Button.h"
#include "App.h"

class ButtonLaunchSP :public Button
{
	App* app;

public:
	ButtonLaunchSP();
	ButtonLaunchSP(App* a, FontEngine*f, std::string s, glm::vec2  Pos, float fontscale, glm::vec3 col);
	void Activate();
	~ButtonLaunchSP();
};


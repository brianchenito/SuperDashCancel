#pragma once
#include "Button.h"
#include "App.h"
class ButtonLaunchSP :
	public Button
{
	App* app;
public:
	ButtonLaunchSP();
	ButtonLaunchSP(App* a,FontEngine*f, std::string s, Vec2  Pos, float fontscale, Color col);
	void Activate();
	~ButtonLaunchSP();
};


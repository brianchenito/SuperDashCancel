#pragma once
#ifndef SDC_MAINMENUSCENE_H
#define SDC_MAINMENUSCENE_H

#include "App.h"
#include "DrawableTexRect.h"
#include "ButtonLaunchSP.h"
#include "DrawableText.h"
#include <math.h>

class MainMenuScene :public App::Scene
{

	float bgpower;
	Color bgcolor;
	DrawableTexRect bg;
	ButtonLaunchSP buttonsp;
	ButtonLaunchSP buttonmp;
	Button* activeButton;
	Color SelectedButtonColor;
	Color UnselectedButtonColor;
	
public:
	MainMenuScene(App* a, std::string label);
	~MainMenuScene();
	void Init();
	void Terminate();
	void Draw();
	void OnUpdate();
	void OnFixedUpdate();
};
#endif

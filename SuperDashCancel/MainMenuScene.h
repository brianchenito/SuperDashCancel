#pragma once
#ifndef SDC_MAINMENUSCENE_H
#define SDC_MAINMENUSCENE_H

#include "App.h"
#include "DrawableSprite.h"
#include "ButtonLaunchMP.h"
#include "DrawableText.h"
#include <math.h>

class MainMenuScene :public App::Scene
{

	float bgpower;
	DrawableSprite bg;
	ButtonLaunchMP buttonsp;
	ButtonLaunchMP buttonmp;
	Button* activeButton;
	glm::vec3 SelectedButtonColor;
	glm::vec3 UnselectedButtonColor;
	
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

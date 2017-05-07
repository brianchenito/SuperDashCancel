#pragma once
#ifndef SDC_MPREADYUPSCENE_H
#define SDC_MPREADYUPSCENE_H


#include "App.h"
#include "DrawableSprite.h"
#include "DrawableText.h"
class MPReadyUpScene :public App::Scene
{
	DrawableSprite bg;
	DrawableSprite p1Symbol;
	DrawableSprite p2Symbol;
	DrawableSprite p1Blank;
	DrawableSprite p2Blank;
	DrawableText p1text;
	DrawableText p2text;
	DrawableText Instruct;
	DrawableText Back;
	float p1Scale;
	float p2Scale;


public:
	MPReadyUpScene(App* a, std::string label);
	~MPReadyUpScene();
	void Init();
	void Terminate();
	void Draw();
	void OnUpdate();
	void OnFixedUpdate();
};
#endif
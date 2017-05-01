#pragma once
#ifndef SDC_MPREADYUPSCENE_H
#define SDC_MPREADYUPSCENE_H


#include "App.h"
#include "DrawableTexRect.h"
#include "DrawableText.h"
class MPReadyUpScene :public App::Scene
{
	DrawableTexRect bg;
	DrawableTexRect p1Symbol;
	DrawableTexRect p2Symbol;
	DrawableTexRect p1Blank;
	DrawableTexRect p2Blank;
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
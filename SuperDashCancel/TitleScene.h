#pragma once
#include "Scene.h"
#include "DrawableTexRect.h"
#include <math.h>
class TitleScene :public Scene
{
	float bgpower;
	Color bgcolor;
	DrawableTexRect bg;
	DrawableTexRect test;
public:
	TitleScene(InputManager* m);
	~TitleScene();
	void Init();
	void Terminate();
	void Draw();
	void OnUpdate();
	void OnFixedUpdate();
};


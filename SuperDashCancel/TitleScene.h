#pragma once
#include "Scene.h"
#include "DrawableTexRect.h"
class TitleScene :public Scene
{
	DrawableTexRect t;
public:
	TitleScene(InputManager* m);
	~TitleScene();
	void Init();
	void Terminate();
	void Draw();
	void OnUpdate();
	void OnFixedUpdate();
};


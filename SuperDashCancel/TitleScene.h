#pragma once
#include "Scene.h"
class TitleScene :public Scene
{
public:
	TitleScene(InputManager* m);
	~TitleScene();
	void Init();
	void Terminate();
	void Draw();
	void OnUpdate();
	void OnFixedUpdate();
};


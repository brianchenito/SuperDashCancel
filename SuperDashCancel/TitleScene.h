#pragma once
#include "Scene.h"
class TitleScene :public Scene
{
public:
	TitleScene();
	~TitleScene();
	void Draw();
	void OnUpdate();
	void OnFixedUpdate();
	void JoystickPlugUnplugCB(int joy, int event);
};


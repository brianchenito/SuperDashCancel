#pragma once
#ifndef SDC_TITLE_SCENE_H
#define SDC_TITLE_SCENE_H


#include "Scene.h"
#include "DrawableTexRect.h"
#include <math.h>
class TitleScene :public Scene
{
	float bgpower;
	Color bgcolor;
	DrawableTexRect bg;
public:
	TitleScene(InputManager* m, FontEngine* e);
	~TitleScene();
	void Init();
	void Terminate();
	void Draw();
	void OnUpdate();
	void OnFixedUpdate();
};

#endif // !SDC_TITLE_SCENE_H
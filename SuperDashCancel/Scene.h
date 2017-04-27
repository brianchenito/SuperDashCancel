#pragma once
#ifndef SDC_SCENE_H
#define SDC_SCENE_H

#include "FontEngine.h" // figure out how to uncomment this line

#include <iostream>
#include "InputManager.h"
#include <GLFW/glfw3.h>

class Scene
{public:
	InputManager* inputmanager;
	FontEngine* fontengine;
	Scene(InputManager* m, FontEngine* e);
	~Scene();

	virtual void Init() = 0;
	virtual void Terminate() = 0;

	virtual void Draw() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnFixedUpdate() = 0;

};

#endif // !SDC_SCENE_H
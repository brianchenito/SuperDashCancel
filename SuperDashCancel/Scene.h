#pragma once
#ifndef SDC_SCENE_H
#define SDC_SCENE_H


#include <iostream>
#include <GLFW/glfw3.h>
#include "InputManager.h"
//#include "FontEngine.h" // figure out how to uncomment this line
class Scene
{public:
	InputManager* inputmanager;
	Scene(InputManager* m);
	~Scene();

	virtual void Init() = 0;
	virtual void Terminate() = 0;

	virtual void Draw() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnFixedUpdate() = 0;

};

#endif // !SDC_SCENE_H
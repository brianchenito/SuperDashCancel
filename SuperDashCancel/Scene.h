#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include "InputManager.h"
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


#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

class Scene
{public:

	Scene();
	~Scene();

	virtual void Init() = 0;
	virtual void Terminate() = 0;

	virtual void Draw() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnFixedUpdate() = 0;

};


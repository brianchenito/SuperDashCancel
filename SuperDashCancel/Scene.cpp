#include "Scene.h"


Scene::Scene(InputManager* m, FontEngine* e)
{
	this->inputmanager = m;
	this->fontengine = e;
}

Scene::~Scene()
{
}

#include "Scene.h"



void Scene::JoystickPlugUnplugCB(int joy, int event)
{
	std::cout << "joystick event\n";
}

Scene::Scene()
{
	glfwSetJoystickCallback(JoystickPlugUnplugCB);
}

Scene::~Scene()
{
}

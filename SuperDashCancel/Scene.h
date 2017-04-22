#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

class Scene
{
private:
	static void JoystickPlugUnplugCB(int joy, int event);
	/* note that we are intentionally NOT registering keyboard button-down callbacks.
	 * GLFW only provides functionality for querying joystick states, and
	 * for consistency we do that for keyboard input too. 
	 */
public:

	Scene();
	~Scene();

	virtual void Draw() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnFixedUpdate() = 0;

};


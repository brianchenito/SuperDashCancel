#pragma once
class Scene
{
private:
	virtual void JoystickPlugUnplugCB(int joy, int event) = 0;
	/* note that we are intentionally NOT registering keyboard button-down callbacks.
	 * GLFW only provides functionality for querying joystick states, and
	 * for consistency we do that for keyboard input too. 
	 */
public:

	Scene();
	~Scene();
	
	void InitScene();
	void CloseScene();
	virtual void Draw() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnFixedUpdate() = 0;

};


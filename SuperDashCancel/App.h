#pragma once
#ifndef SDC_APP_H
#define SDC_APP_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define TIMESTEP 0.016666666666666667 //60 fps
#define FPSCOUNTERSMOOTH 0.95
#include <iostream>
#include <vector>
#include <algorithm>
#include "FontEngine.h"
#include "InputManager.h"



class App
{
private:
	// the time of the frame last drawn.
	double LastFrameTime;
	double NextFixedTime;
	double FPS;
	//  consumes all currently buffered gl draws and flushes buffers.
	void Render();
	/*Fixedstep fires 60 times a second, and is used for simulation. runs inside Step().*/
	void FixedStep();
	
public:
	/*Scene is embedded to avoid issues with circular dependencies and having to forward declare*/
	class Scene
	{
	public:
		App* app;
		Scene(App* a, std::string Title)
		{
			app = a; 
			app->Scenes.insert(std::pair<std::string, Scene*>(Title, this));
		}
		~Scene() {}
		virtual void Init() = 0;
		virtual void Terminate() = 0;
		virtual void Draw() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	};

	std::map<std::string, Scene*> Scenes;// all scenes that belong to this app

	InputManager inputmanager;
	GLFWwindow* window;
	Scene* ActiveScene;
	FontEngine fontengine;
	App();
	~App();
	void SwitchScene(std::string Scene); //kill current scene, fire up new one
	/*Step fires as fast as your computer will allow, and is used for rendering. main loop.*/
	void Step();
	void GLFWInitialize();
	void GLEWInitialize();
};

#endif // !SDC_APP_H
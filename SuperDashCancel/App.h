#pragma once
#ifndef SDC_APP_H
#define SDC_APP_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define TIMESTEP 0.016666666666666667 //60 fps
#define FPSCOUNTERSMOOTH 0.9
#include <iostream>
#include <vector>
#include <algorithm>
#include "FontEngine.h"
#include "TitleScene.h"
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

	Scene* TitleScreen;
	Scene* MainMenu;
	Scene* GamePlay;
	
public:
	InputManager inputmanager;
	GLFWwindow* window;
	Scene* ActiveScene;
	FontEngine fontengine;
	App();
	~App();
	void SwitchScene(Scene* s); //kill current scene, fire up new one
	/*Step fires as fast as your computer will allow, and is used for rendering. main loop.*/
	void Step();
	void GLFWInitialize();
	void GLEWInitialize();
};

#endif // !SDC_APP_H
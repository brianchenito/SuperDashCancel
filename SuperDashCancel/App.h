#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "TitleScene.h"
#define TIMESTEP 0.01666666666 //60 fps
#define FPSSMOOTHING 0 // fps smooth weight
class App
{
private:
	// the time of the frame last drawn.
	double LastFrameTime;
	// the time elapsed since the last frame drawn.
	double deltaTime;
	//the time the last fixedstep occured
	double LastFixedTime;
	//  consumes all currently buffered gl draws and flushes buffers.
	void Render();
	/*Fixedstep fires 60 times a second, and is used for simulation. runs inside Step().*/
	void FixedStep();

	Scene* TitleScreen;
	Scene* MainMenu;
	Scene* GamePlay;

public:
	GLFWwindow* window;
	Scene* ActiveScene;
	App();
	~App();
	void SwitchScene(Scene* s); //kill current scene, fire up new one
	/*Step fires as fast as your computer will allow, and is used for rendering. main loop.*/
	void Step();

};


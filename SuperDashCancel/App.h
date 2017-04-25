#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#define TIMESTEP 0.016666666666666667 //60 fps
#include <iostream>
#include <vector>
#include "TitleScene.h"
#include "InputManager.h"
#include <algorithm>


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
	
	FT_Library library;
	FT_Face face;
	FT_Error ft_err;
	const char face_path[39] = "../SuperDashCancel/fonts/CODE_Bold.otf";
	FT_GlyphSlot g;
	GLuint fontTex;// index to font texture



	


public:
	InputManager* inputmanager;
	GLFWwindow* window;
	Scene* ActiveScene;
	App();
	~App();
	void SwitchScene(Scene* s); //kill current scene, fire up new one
	/*Step fires as fast as your computer will allow, and is used for rendering. main loop.*/
	void Step();
	void GLFWInitialize();
	void GLUTInitialize();
	void FreeTypeInitialize();
	void render_text(const char *text, float x, float y, float sx, float sy);
};


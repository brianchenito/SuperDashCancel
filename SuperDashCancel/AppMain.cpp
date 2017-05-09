#include "App.h"
#include "TitleScene.h"
#include "MainMenuScene.h"
#include "MPReadyUpScene.h"
#include "GameScene.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
int main()
{
	App Game;
	TitleScene t(&Game,"TitleScreen");
	MainMenuScene m(&Game, "MainMenuScreen");
	MPReadyUpScene mp(&Game, "MPReadyUpScreen");
	GameScene g(&Game, "GameScreen");
	Game.SwitchScene("TitleScreen");
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Game.window))
	{
		Game.Step();
	}
}
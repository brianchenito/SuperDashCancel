#include "App.h"
#include "TitleScene.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
int main()
{
	App Game;
	TitleScene t(&Game,"TitleScreen");
	Game.SwitchScene("TitleScreen");
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Game.window))
	{
		Game.Step();
	}
}
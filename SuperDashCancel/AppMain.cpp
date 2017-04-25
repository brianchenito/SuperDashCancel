#include "App.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
int main()
{
	App Game;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Game.window))
	{
		Game.Step();
	}
}
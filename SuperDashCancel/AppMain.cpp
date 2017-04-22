	#include "App.h"

int main()
{
	App Game;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Game.window))
	{
		Game.Step();
	}
}
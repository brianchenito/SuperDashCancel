#include "App.h"

App::App()
{
	LastFrameTime = 0.0;
	LastFixedTime = 0.0;
	/* Initialize the library */
	if (!glfwInit())
	{
		throw "GLFW Library failed to initialize, we broke something";
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "FITEBOYS WE OUT HERE PLAYMIDAIRDOTCOM", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		throw "Window failed to generate, we broke something";
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	TitleScreen = new TitleScene();
	ActiveScene = TitleScreen;

}

void App::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (ActiveScene)ActiveScene->Draw();


	glfwSwapBuffers(window);

}

void App::Step()
{
	/*flush event buffer*/
	glfwPollEvents();
	/*perform timestamp stuff*/
	deltaTime = glfwGetTime() - LastFrameTime;
	LastFrameTime = glfwGetTime();
	if (ActiveScene)ActiveScene->OnUpdate();
	/* if its time, iterate sim*/
	if (LastFixedTime+TIMESTEP<LastFrameTime) FixedStep();
	Render();	
}

void App::FixedStep()
{
	//std::cout << "ticktest\n";
	LastFixedTime+=TIMESTEP;
	if (ActiveScene)ActiveScene->OnFixedUpdate();
}


App::~App()
{
	glfwTerminate();
}

void App::SwitchScene(Scene * s)
{
	ActiveScene->Terminate();
	ActiveScene = s;
	ActiveScene->Init();
}

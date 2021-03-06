
#include "App.h"

App::App()
{
	LastFrameTime = 0.0;
	NextFixedTime = TIMESTEP;
	
	GLFWInitialize();
	
	GLEWInitialize();

	fontengine.init();
	std::cout << "All OpenGL Libraries Initialized\n\n";
	InputManager::Init(window);


	ActiveScene = 0;
}

void App::Render()
{
	glClearColor(0.5f,0.5f,0.5f,0.5f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (ActiveScene)ActiveScene->Draw();

	// print fps
	fontengine.RenderText("FPS: "+std::to_string((int)round(FPS)), 1200.0f, 25.0f, 0.15f, glm::vec3(0.3f,0.3f,0.3f));

	glFlush();
	glfwSwapBuffers(window);

}

void App::Step()
{
	/*flush event buffer*/
	glfwPollEvents();
	if (ActiveScene)ActiveScene->OnUpdate();
	/* if its time, iterate sim*/
	if (glfwGetTime() >=NextFixedTime) FixedStep();

}

void App::GLFWInitialize()
{/* Initialize the library */
	if (!glfwInit()) std::runtime_error("GLFW Library failed to initialize, we broke something");
	glfwWindowHint(GLFW_SAMPLES, 4);
	glEnable(GL_MULTISAMPLE);
	glDisable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "DASH TILL YOU'RE DEAD", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::runtime_error("Window failed to generate, we broke something");
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSetWindowSizeLimits(window, 1280, 720, 1280, 720);
	std::cout << "GLFW initialized\n";
}

void App::GLEWInitialize() 
{
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err)std::runtime_error("glew broke");

	std::cout << "GLEW initialized\n";

}



void App::FixedStep()
{
	Render();
	InputManager::FixedStep();
	if (ActiveScene)ActiveScene->OnFixedUpdate();
	FPS = (FPSCOUNTERSMOOTH*FPS)+(1-FPSCOUNTERSMOOTH)*(1/(glfwGetTime() - LastFrameTime));
	NextFixedTime += TIMESTEP;
	LastFrameTime= glfwGetTime();
}


App::~App()
{
	//delet this
	glfwTerminate();
}

void App::SwitchScene(std::string scene)
{
	if(ActiveScene)ActiveScene->Terminate();
	ActiveScene = Scenes[scene];
	ActiveScene->Init();
}

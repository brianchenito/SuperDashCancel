
#include "App.h"

App::App()
{
	LastFrameTime = 0.0;
	LastFixedTime = 0.0;
	
	GLFWInitialize();
	GLEWInitialize();

	fontengine.init();
	std::cout << "All OpenGL Libraries Initialized\n\n";

	/* Scene Init */
	inputmanager = new InputManager(window);
	TitleScreen = new TitleScene(inputmanager);
	ActiveScene = TitleScreen;
	ActiveScene->Init();

	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
}

void App::Render()
{
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (ActiveScene)ActiveScene->Draw();

	// print fps
	fontengine.RenderText("FPS: "+std::to_string((int)round(1/deltaTime)), 1200.0f, 25.0f, 0.3f, glm::vec3(0.3f,0.3f,0.3f));

	glFlush();
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

void App::GLFWInitialize()
{/* Initialize the library */
	if (!glfwInit()) std::runtime_error("GLFW Library failed to initialize, we broke something");

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "FITEBOYS WE OUT HERE PLAYMIDAIRDOTCOM", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::runtime_error("Window failed to generate, we broke something");
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
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
	//std::cout << "ticktest\n";
	LastFixedTime+=TIMESTEP;
	inputmanager->FixedStep();
	if (ActiveScene)ActiveScene->OnFixedUpdate();
}


App::~App()
{
	delete TitleScreen;
	delete MainMenu;
	delete GamePlay;
	//delet this
	delete inputmanager;
	glfwTerminate();
}

void App::SwitchScene(Scene * s)
{
	ActiveScene->Terminate();
	ActiveScene = s;
	ActiveScene->Init();
}

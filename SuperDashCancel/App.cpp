
#include "App.h"

App::App()
{
	LastFrameTime = 0.0;
	LastFixedTime = 0.0;
	
	GLFWInitialize();
	GLUTInitialize();
	FreeTypeInitialize();
	std::cout << "All OpenGL Libraries Initialized\n\n";

	/* Scene Init */
	inputmanager = new InputManager(window);
	TitleScreen = new TitleScene(inputmanager);
	ActiveScene = TitleScreen;
	ActiveScene->Init();
	
}

void App::Render()
{
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (ActiveScene)ActiveScene->Draw();

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

void App::GLUTInitialize() 
{
	GLenum err = glewInit();
	if (err)std::runtime_error("glew broke");

	std::cout << "GLEW initialized\n";

}

void App::FreeTypeInitialize()
{
	ft_err = FT_Init_FreeType(&library);
	if (ft_err) std::runtime_error("FreeType failed to initialize");

	ft_err = FT_New_Face(library, face_path, 0, &face);
	if (ft_err) throw std::runtime_error("FreeType failed to load font at specified location");

	ft_err= FT_Set_Pixel_Sizes(face, 0, 48);
	if (ft_err) std::runtime_error("freetype Scaleset failure ");
	//load glyph images
	for (char i = 32; i < 127; i++) 
	{
		ft_err = FT_Load_Glyph(face, FT_Get_Char_Index(face, i), FT_RENDER_MODE_NORMAL);
	}


}

void App::render_text(const char * text, float x, float y, float sx, float sy)
{
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

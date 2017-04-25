#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
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

void App::GLFWInitialize()
{/* Initialize the library */
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
	std::cout << "GLFW initialized\n";
}

void App::GLUTInitialize()
{
	GLenum err = glewInit();
	if (glewInit())
	{
		throw "glew broke";
	}
	std::cout << "GLEW initialized\n";

}

void App::FreeTypeInitialize()
{
	/* FreeType Init */

	ft_err = FT_Init_FreeType(&library);
	if (ft_err) {
		throw "FreeType failed to initialize";
	}

	ft_err = FT_New_Face(library, face_path, 0, &face);
	if (ft_err) {
		throw "FreeType failed to load font at specified location";
	}
	FT_Set_Pixel_Sizes(face, 0, 48);
	// load all important characters
	FT_GlyphSlot g = face->glyph;
	int w = 0;
	int h = 0;
	for (char c = 0; c <= 126; c++)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			throw "ERROR::FREETYTPE: Failed to load Glyph";
		}
		w += g->bitmap.width;
		h = std::max(h, (int)g->bitmap.rows);
	}
	GLuint tex;
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, w, h, 0, GL_ALPHA, GL_UNSIGNED_BYTE, 0);
	std::cout << "FreeType initialized\n";

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

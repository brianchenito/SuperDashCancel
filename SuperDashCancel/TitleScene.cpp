#include "TitleScene.h"



TitleScene::TitleScene(App* a,std::string label):Scene(a,label)
{

}


TitleScene::~TitleScene()
{
}

void TitleScene::Init() 
{
	bg = DrawableTexRect(&app->SpriteShader, glm::vec2(-1, -1), glm::vec2(2, 2), glm::vec3(0.86f, 0.85f, 0.8f));
	bg.loadTexture("../SuperDashCancel/textures/texture2.png", NOALPHA);

	title = DrawableText(&app->fontengine, "SUPERDASHCANCEL", glm::vec2(-0.545f, 0.3f), 1.0f, glm::vec3(0.3f, 0.3f, 0.3f));
	Continue = DrawableText(&app->fontengine, "Press Button 1 to Start", glm::vec2(-0.30f, 0.0f), 0.4f, glm::vec3(0.3f, 0.3f, 0.3f));
	contvis = -80;
	contswoopin = glm::vec2(-3, 0);
	titleswoopin = glm::vec2(-3, 0);
	std::cout << "Default Controls:\n Player 1: WASD, V,B\n Player 2: Arrow Keys, '.','/'\n\nPlug in Controllers to override\n";
}

void TitleScene::Terminate()
{
}

void TitleScene::Draw()
{
	bg.Draw();
	title.Draw();
	if(contvis<0||(int)glfwGetTime()%2==0)Continue.Draw();
}

void TitleScene::OnUpdate()
{
}

void TitleScene::OnFixedUpdate()
{
	if (InputManager::GlobalPressed(Input_Light) || InputManager::GlobalPressed(Input_Enter))
	{
		app->SwitchScene("MainMenuScreen");
	}
	title.setPos(glm::vec2(-0.545f, 0.3f) + titleswoopin);
	titleswoopin = titleswoopin*0.8f;
	Continue.setPos(glm::vec2(-0.30f, 0.0f) + contswoopin);
	contswoopin = contswoopin*0.9f;
	if (contvis < 0)contvis++;

}


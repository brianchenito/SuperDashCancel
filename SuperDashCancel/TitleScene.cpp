#include "TitleScene.h"



TitleScene::TitleScene(App* a,std::string label):Scene(a,label)
{

}


TitleScene::~TitleScene()
{
}

void TitleScene::Init() 
{
	bg.setPos(Vec2(-1, -1));
	bg.setScale(2, 2);
	bg.setColor(Color(0.86f, 0.85f, 0.8f, 1));
	bg.loadTexture("../SuperDashCancel/textures/texture2.png", NOALPHA);

	title = DrawableText(&app->fontengine, "SUPERDASHCANCEL", Vec2(-0.57f, 0.3f), 1.0f, Color(0.3f, 0.3f, 0.3f, 1.0f));
	Continue = DrawableText(&app->fontengine, "Press Button 1 to Start", Vec2(-0.30f, 0.0f), 0.4f, Color(0.3f, 0.3f, 0.3f, 1.0f));
	contvis = -80;
	contswoopin = Vec2(-3, 0);
	titleswoopin = Vec2(-3, 0);
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
	if (app->inputmanager.GlobalPressed(Input_Light) || app->inputmanager.GlobalPressed(Input_Enter))
	{
		app->SwitchScene("MainMenuScreen");
	}
	title.setPos(Vec2(-0.57f, 0.3f) + titleswoopin);
	titleswoopin = titleswoopin*0.8f;
	Continue.setPos(Vec2(-0.30f, 0.0f) + contswoopin);
	contswoopin = contswoopin*0.9f;
	if (contvis < 0)contvis++;

}


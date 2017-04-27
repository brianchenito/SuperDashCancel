#include "TitleScene.h"



TitleScene::TitleScene(InputManager* m, FontEngine* e):Scene(m,e)
{

}


TitleScene::~TitleScene()
{
}

void TitleScene::Init() 
{
	bg.setPos(Vec2(-1, -1));
	bg.setScale(2, 2);
	bgcolor = Color(1, 0.95f, 0.9f, 1);
	bgpower = 0;
	bg.setColor(bgcolor*bgpower);
	bg.loadTexture("../SuperDashCancel/textures/texture2.png", NOALPHA);
}

void TitleScene::Terminate()
{
}

void TitleScene::Draw()
{
	bg.Draw();
	fontengine->RenderText("SUPERDASHCANCEL", 380.0f, 360.0f, 1.0f, glm::vec3(0.3f, 0.3f, 0.3f));

}

void TitleScene::OnUpdate()
{
}

void TitleScene::OnFixedUpdate()
{
	if (inputmanager->GlobalPressed(Input_Up))std::cout << "Up pressed\n";
	if (inputmanager->GlobalHeld(Input_Down))std::cout << "Down Held\n";
	// do background texture stuff
	if (bgpower < 1) 
	{ bgpower += 0.025f; 	
	bg.setColor(bgcolor*bgpower);
	}



}


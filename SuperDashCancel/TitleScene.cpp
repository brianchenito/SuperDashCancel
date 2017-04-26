#include "TitleScene.h"



TitleScene::TitleScene(InputManager* m):Scene(m)
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
	test.setColor(1, 0.8f, 1, 1);
	test.setPos(Vec2(-0.5, -0.5));
	test.setScale(Vec2(0.5f, 0.25f));
	test.loadTexture("../SuperDashCancel/textures/texture3.png",ALPHA);

}

void TitleScene::Terminate()
{
}

void TitleScene::Draw()
{
	bg.Draw();
	test.Draw();
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


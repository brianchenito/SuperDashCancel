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
	bg.setColor(1, 0.95f, 0.9f, 1);
	bg.loadTexture("../SuperDashCancel/textures/texture2.png");
}

void TitleScene::Terminate()
{
}

void TitleScene::Draw()
{
	bg.Draw();
}

void TitleScene::OnUpdate()
{
}

void TitleScene::OnFixedUpdate()
{
	//std::cout << "mainmenutick\n";
	if (inputmanager->GlobalPressed(Input_Up))std::cout << "Up pressed\n";
	if (inputmanager->GlobalHeld(Input_Down))std::cout << "Down Held\n";

}


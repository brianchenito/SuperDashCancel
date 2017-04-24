#include "TitleScene.h"



TitleScene::TitleScene(InputManager* m):Scene(m)
{

}


TitleScene::~TitleScene()
{
}

void TitleScene::Init() 
{
}

void TitleScene::Terminate()
{
}

void TitleScene::Draw()
{
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


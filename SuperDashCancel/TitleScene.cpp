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

	title = DrawableText(fontengine, "SUPERDASHCANCEL", Vec2(-0.57f, 0.3f), 1.0f, Color(0.3f, 0.3f, 0.3f, 1.0f));

	std::cout << "Default Controls:\n Player 1: WASD, V,B\n Player 2: Arrow Keys, Numpad 1, 2\n\nPlug in Controllers to override\n";
}

void TitleScene::Terminate()
{
}

void TitleScene::Draw()
{
	bg.Draw();
	title.Draw();
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


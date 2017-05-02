#include "MPReadyUpScene.h"






MPReadyUpScene::MPReadyUpScene(App * a, std::string label):Scene(a,label)
{
	bg = DrawableTexRect(glm::vec2(-1, -1), glm::vec2(2, 2), glm::vec3(0.86f, 0.85f, 0.8f));
	bg.loadTexture("../SuperDashCancel/textures/texture2.png", NOALPHA);

	// setup icons
	p1Blank = DrawableTexRect(glm::vec2(-0.4, -0.2f),glm::vec2(0.09,0.16)*3, glm::vec3(0.3f, 0.3f, 0.3f));
	p1Blank.loadTexture("../SuperDashCancel/textures/texture1.png", ALPHA);

	p2Blank = DrawableTexRect(glm::vec2(0.1275f, -0.2f), glm::vec2(0.09, 0.16) * 3, glm::vec3(0.3f, 0.3f, 0.3f));
	p2Blank.loadTexture("../SuperDashCancel/textures/texture1.png", ALPHA);
	p1Scale = 0.0f;
	p2Scale = 0.0f;
	p1Symbol = DrawableTexRect(glm::vec2(-0.4, -0.2f), glm::vec2(0.09, 0.16) * p1Scale, glm::vec3(0.97f, 0.95f, 0.94f));
	p1Symbol.loadTexture("../SuperDashCancel/textures/texture4.png", ALPHA);

	p2Symbol = DrawableTexRect(glm::vec2(0.1275f, -0.2f), glm::vec2(0.09, 0.16) * p2Scale, glm::vec3(0.6f, 0.3f, 0.3f));
	p1Symbol.loadTexture("../SuperDashCancel/textures/texture4.png", ALPHA);
	//setup text
	Instruct = DrawableText(&app->fontengine, "Hold Button 1 to Ready Up", glm::vec2(-0.34f, -0.2f), 0.4f, glm::vec3(0.3f, 0.3f, 0.3f));
	p1text =  DrawableText(&app->fontengine, "Player 1", glm::vec2(-0.36f, 0.6f), 0.4f, glm::vec3(0.6f, 0.3f, 0.3f));
	p2text = DrawableText(&app->fontengine, "Player 2", glm::vec2(0.16f, 0.6f), 0.4f, glm::vec3(0.8f, 0.65f, 0.5f));

}

MPReadyUpScene::~MPReadyUpScene()
{
}

void MPReadyUpScene::Init()
{
	//std::cout << "Default Controls:\n Player 1: WASD, V,B\n Player 2: Arrow Keys, '.','/'\n\nPlug in Controllers to override\n";
	p1Scale = 0.0f;
	p2Scale = 0.0f;
	p1Symbol.setScale(glm::vec2(0.27, 0.16* p1Scale));
	p2Symbol.setScale(glm::vec2(0.27, 0.16* p2Scale));


}

void MPReadyUpScene::Terminate()
{
}

void MPReadyUpScene::Draw()
{
	bg.Draw();
	Instruct.Draw();
	p1Symbol.Draw();
	p2Symbol.Draw();

	p1Blank.Draw();
	p2Blank.Draw();
	p1text.Draw();
	p2text.Draw();

}

void MPReadyUpScene::OnUpdate()
{
}

void MPReadyUpScene::OnFixedUpdate()
{
	if (app->inputmanager.GlobalPressed(Input_Heavy) || app->inputmanager.GlobalPressed(Input_Delete))
	{
		app->SwitchScene("MainMenuScreen");
	}
	if (app->inputmanager.Held(Input_Light, true)&&p1Scale<2.9f) 
	{
		p1Scale += 0.15f;
		p1Symbol.setScale(glm::vec2(0.27, 0.16* p1Scale) );
	}
	else if(p1Scale < 2.9f&&p1Scale>0) 
	{
		p1Scale -= 0.3f;
		p1Symbol.setScale(glm::vec2(0.27, 0.16* p1Scale));

	}

	if (app->inputmanager.Held(Input_Light, false) && p2Scale<2.9f)
	{
		p2Scale += 0.15f;
		p2Symbol.setScale(glm::vec2(0.27, 0.16* p2Scale));
	}
	else if (p2Scale < 2.9f&&p2Scale>0)
	{
		p2Scale -= 0.3f;
		p2Symbol.setScale(glm::vec2(0.27, 0.16* p2Scale));

	}
	if (p1Scale >= 2.9 && p2Scale >= 2.9) 
	{
		std::cout << "LAUNCH\n";
		app->SwitchScene("TitleScreen");
	}

}

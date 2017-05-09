#include "MPReadyUpScene.h"






MPReadyUpScene::MPReadyUpScene(App * a, std::string label):Scene(a,label)
{
	bg = DrawableSprite( glm::vec2(0,0), glm::vec2(1280,720), glm::vec3(0.86f, 0.85f, 0.8f));
	bg.loadTexture("../SuperDashCancel/textures/texture2.png", NOALPHA);

	// setup icons
	p1Blank = DrawableSprite( glm::vec2(400,305),glm::vec2(128,128), glm::vec3(0.3f, 0.3f, 0.3f));
	p1Blank.loadTexture("../SuperDashCancel/textures/texture1.png", ALPHA);

	p2Blank = DrawableSprite( glm::vec2(735, 305), glm::vec2(128, 128), glm::vec3(0.3f, 0.3f, 0.3f));
	p2Blank.loadTexture("../SuperDashCancel/textures/texture1.png", ALPHA);
	p1Scale = 0.0f;
	p2Scale = 0.0f;
	p1Symbol = DrawableSprite( glm::vec2(400, 310), glm::vec2(128, 122) * p1Scale, PLAYER_ONE_COLOR);
	p1Symbol.loadTexture("../SuperDashCancel/textures/texture4.png", ALPHA);

	p2Symbol = DrawableSprite( glm::vec2(735, 310), glm::vec2(128, 122) * p2Scale, PLAYER_TWO_COLOR);
	p1Symbol.loadTexture("../SuperDashCancel/textures/texture4.png", ALPHA);
	//setup text
	Instruct = DrawableText(&app->fontengine, "Hold Button 1 to Ready Up", glm::vec2(422, 200), 0.4f, glm::vec3(0.3f, 0.3f, 0.3f));
	p1text =  DrawableText(&app->fontengine, "Player 1", glm::vec2(408, 400), 0.35f, glm::vec3(0.6f, 0.3f, 0.3f));
	p2text = DrawableText(&app->fontengine, "Player 2", glm::vec2(743, 400), 0.33f, glm::vec3(0.8f, 0.65f, 0.5f));

}

MPReadyUpScene::~MPReadyUpScene()
{
}

void MPReadyUpScene::Init()
{
	//std::cout << "Default Controls:\n Player 1: WASD, V,B\n Player 2: Arrow Keys, '.','/'\n\nPlug in Controllers to override\n";
	p1Scale = 0.0f;
	p2Scale = 0.0f;


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

	if (InputManager::GlobalPressed(Input_Heavy) || InputManager::GlobalPressed(Input_Delete))
	{
		app->SwitchScene("MainMenuScreen");
	}
	if (InputManager::Held(Input_Light, true)&&p1Scale<1) 
	{
		p1Scale += 0.05f;
	}
	else if(p1Scale < 1&&p1Scale>0) 
	{
		p1Scale -= 0.1f;

	}

	if (InputManager::Held(Input_Light, false) && p2Scale<1)
	{
		p2Scale += 0.05f;
	}
	else if (p2Scale < 1&&p2Scale>0)
	{
		p2Scale -= 0.1f;

	}
	if (p1Scale < 0)p1Scale = 0;
	if (p2Scale < 0)p2Scale = 0;
	if (p1Scale > 1)p1Scale = 1;
	if (p2Scale > 1)p2Scale = 1;
	p2Symbol.setScale(glm::vec2(128, 123 * p2Scale));
	p1Symbol.setScale(glm::vec2(128, 123 * p1Scale));
	if (p1Scale >= 1 && p2Scale >= 1) 
	{
		std::cout << "LAUNCH\n";
		app->SwitchScene("GameScreen");
	}

}

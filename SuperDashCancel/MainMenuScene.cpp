#include "MainMenuScene.h"



MainMenuScene::MainMenuScene(App * a, std::string label):Scene(a, label)
{
	bg = DrawableSprite(glm::vec2(0,0), glm::vec2(1280,720), glm::vec3(0.86f, 0.85f, 0.8f));
	bg.loadTexture("../SuperDashCancel/textures/texture2.png", NOALPHA);

	// setup buttons

	UnselectedButtonColor = glm::vec3(0.6f, 0.6f, 0.6f);
	SelectedButtonColor = glm::vec3(0.6f, 0.3f, 0.3f);
	buttonsp = ButtonLaunchSP(app, &app->fontengine, "Single player", glm::vec2(290, 370), 0.55f, SelectedButtonColor);
	buttonmp = ButtonLaunchMP(app, &app->fontengine, "Two Player Vs", glm::vec2(700, 370), 0.50f, UnselectedButtonColor);
	buttonsp.AttachNeighbors(0, 0, 0, &buttonmp);
	buttonmp.AttachNeighbors(0, 0, &buttonsp, 0);
	activeButton = &buttonsp;

}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::Init()
{
	bgpower = 1;
	InputManager::Reconnect();
}

void MainMenuScene::Terminate()
{
}

void MainMenuScene::Draw()
{
	bg.Draw(); 
	buttonsp.Draw();
	buttonmp.Draw();
}

void MainMenuScene::OnUpdate()
{
}

void MainMenuScene::OnFixedUpdate()
{
	/*
	if (bgpower > 0) 
	{
		bgpower -= 0.010f;
		bg.setglm::vec3(glm::vec3(0.98f, 0.75f, 0.88f, 1)*(1-bgpower)+ bgcolor*bgpower);

	}
	*/
	if (InputManager::GlobalPressed(Input_Heavy) || InputManager::GlobalPressed(Input_Delete))
	{
		app->SwitchScene("TitleScreen");
	}
	if (InputManager::GlobalPressed(Input_Light) || InputManager::GlobalPressed(Input_Enter))
	{
		activeButton->Activate();
	}
	if (InputManager::GlobalPressed(Input_Left) )
	{
		if (activeButton->Left) {
			activeButton = activeButton->Left;
			buttonsp.setColor(UnselectedButtonColor);
			buttonmp.setColor(UnselectedButtonColor);
			buttonsp.fontScale = 0.5f;
			buttonmp.fontScale = 0.5f;
			activeButton->setColor(SelectedButtonColor);
			activeButton->fontScale = 0.55f;
		} 
	}
	if (InputManager::GlobalPressed(Input_Right))
	{
		if (activeButton->Right) {
			activeButton = activeButton->Right;
			buttonsp.setColor(UnselectedButtonColor);
			buttonmp.setColor(UnselectedButtonColor);
			buttonsp.fontScale = 0.5f;
			buttonmp.fontScale = 0.5f;
			activeButton->setColor(SelectedButtonColor);
			activeButton->fontScale = 0.55f;
		}
	}
}

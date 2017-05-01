#include "MainMenuScene.h"



MainMenuScene::MainMenuScene(App * a, std::string label):Scene(a, label)
{
	bg.setPos(Vec2(-1, -1));
	bg.setScale(2, 2);
	bgcolor = Color(0.86f, 0.85f, 0.8f, 1);
	bg.setColor(bgcolor);
	bg.loadTexture("../SuperDashCancel/textures/texture2.png", NOALPHA);

	// setup buttons

	UnselectedButtonColor = Color(0.6f, 0.6f, 0.6f, 1.0f);
	SelectedButtonColor = Color(0.6f, 0.3f, 0.3f, 1);
	buttonsp = ButtonLaunchSP(app, &app->fontengine, "Single player", Vec2(-0.53f, 0.35f), 0.55f, SelectedButtonColor);
	buttonmp = ButtonLaunchSP(app, &app->fontengine, "Two Player Vs", Vec2(0.12f, 0.35f), 0.50f, UnselectedButtonColor);
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
		bg.setColor(Color(0.98f, 0.75f, 0.88f, 1)*(1-bgpower)+ bgcolor*bgpower);

	}
	*/
	if (app->inputmanager.GlobalPressed(Input_Heavy) || app->inputmanager.GlobalPressed(Input_Delete))
	{
		app->SwitchScene("TitleScreen");
	}
	if (app->inputmanager.GlobalPressed(Input_Light) || app->inputmanager.GlobalPressed(Input_Enter))
	{
		activeButton->Activate();
	}
	if (app->inputmanager.GlobalPressed(Input_Left) )
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
	if (app->inputmanager.GlobalPressed(Input_Right))
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

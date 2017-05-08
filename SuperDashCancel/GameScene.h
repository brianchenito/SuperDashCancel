#pragma once
#include "App.h"
#include "DrawableSprite.h"
#include "DrawableText.h"
#include "PlayerCharacter.h"
#include "States.h"
#include "presets.h"
#include <stdlib.h>
class GameScene :
	public App::Scene
{
	bool drawWinText;
	int gameTime;
	int winTimeOut;

	DrawableSprite background;
	DrawableSprite floor;

	PlayerCharacter p1;
	PlayerCharacter p2;

	DrawableSprite p1hp;
	DrawableSprite p2hp;
	DrawableSprite p1hp_back;
	DrawableSprite p2hp_back;

	DrawableText winText;
	DrawableText gameTimeText;

public:
	
	GameScene(App* a, std::string label);
	~GameScene();
	void Init();
	void Terminate();
	void Draw();
	void OnUpdate();
	void OnFixedUpdate();

	void PopulateStateMap(PlayerCharacter* p);
};


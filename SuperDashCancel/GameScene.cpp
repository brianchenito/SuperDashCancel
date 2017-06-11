#include "GameScene.h"



GameScene::GameScene(App *a, std::string label):Scene(a, label)
{
	drawWinText = false;
	gameTime = 3600;
	winTimeOut = 300;


	background = DrawableSprite(glm::vec2(0, 0), glm::vec2(1280, 720), glm::vec3(0.6f,0.6f,0.6f));
	background.loadTexture("../SuperDashCancel/textures/texture6.png", NOALPHA);

	floor = DrawableSprite(glm::vec2(0, 0), glm::vec2(1280, 160), glm::vec3(.13f,.17f,.15f));
	floor.loadTexture("../SuperDashCancel/textures/texture5.png", ALPHA);

	decorativeLine1 = DrawableSprite(glm::vec2(500, 670), glm::vec2(280, 2), glm::vec3(0.3f, 0.3f, 0.3f));
	decorativeLine1.loadTexture("../SuperDashCancel/textures/texture5.png", ALPHA);

	decorativeLine2 = DrawableSprite(glm::vec2(550, 665), glm::vec2(180, 2), glm::vec3(0.3f, 0.3f, 0.3f));
	decorativeLine2.loadTexture("../SuperDashCancel/textures/texture5.png", ALPHA);

	p1hp = DrawableSprite(glm::vec2(40, 690), glm::vec2(550, 20), PLAYER_ONE_COLOR);
	p1hp.loadTexture("../SuperDashCancel/textures/texture5.png", ALPHA);

	p1hp_back = DrawableSprite(glm::vec2(36, 686), glm::vec2(550, 20), glm::vec3(0.3f, 0.3f, 0.3f));
	p1hp_back.loadTexture("../SuperDashCancel/textures/texture5.png", ALPHA);

	p2hp = DrawableSprite(glm::vec2(690, 690), glm::vec2(550, 20), PLAYER_TWO_COLOR);
	p2hp.loadTexture("../SuperDashCancel/textures/texture5.png", ALPHA);

	p2hp_back = DrawableSprite(glm::vec2(694, 686), glm::vec2(550, 20), glm::vec3(0.3f, 0.3f, 0.3f));
	p2hp_back.loadTexture("../SuperDashCancel/textures/texture5.png", ALPHA);

	winText = DrawableText(&app->fontengine, "", glm::vec2(520, 380), 1.0f, glm::vec3(0.9f, 0.9f, 0.85f));
	gameTimeText = DrawableText(&app->fontengine, std::to_string(gameTime / 60), glm::vec2(625, 680), 0.4f, glm::vec3(0.9f, 0.9f, 0.85f));

	p1 = PlayerCharacter(true);
	p2 = PlayerCharacter(false);



	p1.enemy = &p2;
	p2.enemy = &p1;

	PopulateStateMap(&p1);
	PopulateStateMap(&p2);
}


GameScene::~GameScene()
{

}

void GameScene::Init() {
	pause = false;

	drawWinText = false;
	warmup = 240;
	gameTime = 3600;
	winTimeOut = 300;
	// reset
	p1.ChangeState(IDLE);
	p2.ChangeState(IDLE);
	p1.setPos(glm::vec2(520, 160));
	p2.setPos(glm::vec2(760, 160));
	p1.skew = 0;
	p2.skew = 0;
	p1.scale = PLAYER_SCALE;
	p2.scale = PLAYER_SCALE;

	p1.health = 1000;
	p2.health = 1000;
	OnFixedUpdate();
}

void GameScene::Terminate() {
	Drawable::projection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f);
	InputManager::Reconnect();
}

void GameScene::Draw() {
	background.Draw();
	floor.Draw();

	p1.Draw();
	p2.Draw();
	if(p1.pos.y<=FLOOR_HEIGHT)p1.dashDust.Draw();
	if (p2.pos.y <= FLOOR_HEIGHT)p2.dashDust.Draw();
	p1.lPunch.Draw();
	p2.lPunch.Draw();// draw spritesheets on top


	p1hp_back.Draw();
	p2hp_back.Draw();
	p1hp.Draw();
	p2hp.Draw();
	decorativeLine1.Draw();
	decorativeLine2.Draw();
	gameTimeText.Draw();
	if (drawWinText) winText.Draw();
}

void GameScene::OnUpdate() {

}

void GameScene::OnFixedUpdate() {
	if (InputManager::GlobalPressed(Input_Delete))pause = !pause;
	if (pause)background.col = glm::vec3(0.3f, 0.3f, 0.3f);
	else background.col = glm::vec3(0.6f, 0.6f, 0.6f);

	if (pause) return;

	// warmup
	if (warmup > 0) 
	{
		drawWinText = true;
		if (warmup > 179) 
		{
			winText.setPos(glm::vec2(520, 380));

			winText.text = "Ready";
		}
		else 
		{
			winText.setPos(glm::vec2(620, 380));
			winText.text = std::to_string((warmup / 60) + 1);

		}
		warmup--;
		return;
	}
	else if (warmup == 0) 
	{
		drawWinText = false;
		winText.setPos(glm::vec2(520, 380));
		warmup--;
	}
	// normal gameplay
	if (gameTime > 0 && !drawWinText) {
		gameTimeText.text = std::to_string(gameTime / 60);
		gameTime--;

		p1.FixedUpdate();
		p2.FixedUpdate();
		p1hp.scale.x = p1.health / 1000.0f * 550;
		p1hp.pos.x = 40 + (1000 - p1.health)/1000.0f*550;
		p2hp.scale.x = p2.health / 1000.0f * 550;

	}
	else {
		if (winTimeOut > 0) {
			if (winTimeOut % 5 == 0) 
			{
				InputManager::Player1Device = 0;
				InputManager::Player2Device = 0;
				p1.FixedUpdate();
				p2.FixedUpdate();
			}
			winTimeOut--;
		}
		else {
			app->SwitchScene("TitleScreen");
			return;
		}
		drawWinText = true;
		if (p1.health < p2.health) 
		{
			p2.hitstop = 20;
			winText.text = "P2 WINS";
			p1.scale.y = PLAYER_SCALE.y / 2;
		}
			
		else if (p1.health > p2.health) 
		{
			p1.hitstop = 20;

			winText.text = "P1 WINS";
			p2.scale.y = PLAYER_SCALE.y / 2;
		}
			
		else 
		{
			winText.text = "DRAW";
			p1.hitstop = 20;
			p2.hitstop = 20;
		}


	}
	
	if (p1.health <= 0 && p1.activeState->currentState == IDLE) {
		p1hp.scale.x = 0;
		winText.text = "P2 WINS";
		p2.hitstop = 20;
		p1.scale.y = PLAYER_SCALE.y / 2;
		drawWinText = true;
		return;
	}
	if (p2.health <= 0 && p2.activeState->currentState == IDLE) {
		p2hp.scale.x = 0;
		winText.text = "P1 WINS";
		p1.hitstop = 20;
		p2.scale.y = PLAYER_SCALE.y / 2;
		drawWinText = true;
		return;
	}



}

void GameScene::PopulateStateMap(PlayerCharacter* p) {
	p->stateMap[IDLE] = new Idle(p, IDLE);
	p->stateMap[MOVE_FORWARD] = new MoveForward(p, MOVE_FORWARD);
	p->stateMap[MOVE_BACKWARD] = new MoveBackward(p, MOVE_BACKWARD);
	p->stateMap[CROUCH] = new Crouch(p, CROUCH);
	p->stateMap[CROUCH_BLOCK] = new CrouchBlock(p, CROUCH_BLOCK);
	p->stateMap[AIRBORNE] = new Airborne(p, AIRBORNE);
	p->stateMap[HIT_STUN] = new HitStun(p, HIT_STUN);
	p->stateMap[LIGHT_ATTACK] = new LightAttack(p, LIGHT_ATTACK);
	p->stateMap[HEAVY_ATTACK] = new HeavyAttack(p, HEAVY_ATTACK);
	p->stateMap[HEAVY_CROUCH_ATTACK] = new HeavyAttack(p, HEAVY_CROUCH_ATTACK);// temp
	p->stateMap[LIGHT_CROUCH_ATTACK] = new LightAttack(p, LIGHT_CROUCH_ATTACK);//temp


	p->stateMap[LIGHT_DASH] = new LightDash(p, LIGHT_DASH);
	p->stateMap[HEAVY_DASH] = new LightDash(p, HEAVY_DASH);
	p->stateMap[LIGHT_SLIDE] = new SlideLight(p, LIGHT_SLIDE);
	p->stateMap[HEAVY_SLIDE] = new SlideHeavy(p, HEAVY_SLIDE);
	p->stateMap[BACK_DASH] = new BackDash(p, BACK_DASH);
	p->stateMap[FORWARD_DASH] = new ForwardDash(p, FORWARD_DASH);

}
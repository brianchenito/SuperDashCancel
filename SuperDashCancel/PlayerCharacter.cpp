#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() {}

PlayerCharacter::PlayerCharacter(bool player1)
{
	isPlayer1 = player1;

	if (isPlayer1) col = PLAYER_ONE_COLOR;
	else col = PLAYER_TWO_COLOR;
	scale = PLAYER_SCALE;

	loadTexture("../SuperDashCancel/textures/texture4.png", ALPHA);

	activeState = 0;
	health = 1000;

}

void PlayerCharacter::Draw() {
	pos.x -= PLAYER_SCALE.x / 2;
	DrawableSprite::Draw();
	pos.x += PLAYER_SCALE.x / 2;
}

void PlayerCharacter::FixedUpdate() {
	if (hitstop > 0) { hitstop--; return; }

	if (activeState) activeState->FixedUpdate();
	PhysicsMove();
}

void PlayerCharacter::ChangeState(PlayerStates pstate) {
	if (stateMap.find(pstate) != stateMap.end()) {
		if (activeState) activeState->Exit();
		activeState = stateMap[pstate];
		activeState->Enter();
	}
	else {
		std::cout << "ChangeState attempt failed: " << pstate << " is not a valid state" << std::endl;
	}
}

PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::Move(glm::vec2 delta) {
	//Movement
	if (isEnemyLeft()) 
		pos -= delta;
	else 
		pos += delta;

	
	//Boundaries
	if (pos.y < FLOOR_HEIGHT) pos.y = FLOOR_HEIGHT;
	if (pos.y > CEILING_HEIGHT) pos.y = CEILING_HEIGHT;
	if (pos.x < WALL_LEFT) pos.x = WALL_LEFT;
	if (pos.x > WALL_RIGHT) pos.x = WALL_RIGHT;
}

void PlayerCharacter::PhysicsMove() {
	//Momentum
	pos += momentum;

	//Friction
	if (momentum.x < 0.01f || momentum.x > -0.01f)
		momentum.x /= 2;
	else
		momentum.x = 0;

	//Gravity
	if (pos.y > FLOOR_HEIGHT) {
		momentum.y += GRAVITY;
	}
	else {
		if (momentum.y < 0)
			momentum.y = 0;
	}

	//Boundaries
	if (pos.y < FLOOR_HEIGHT) pos.y = FLOOR_HEIGHT;
	if (pos.y > CEILING_HEIGHT) pos.y = CEILING_HEIGHT;
	if (pos.x < WALL_LEFT) pos.x = WALL_LEFT;
	if (pos.x > WALL_RIGHT) pos.x = WALL_RIGHT;

}

bool PlayerCharacter::isEnemyLeft() {
	return (enemy->GetPos().x - GetPos().x < 0);
}

void PlayerCharacter::SetEnemyPlayer(PlayerCharacter * e)
{
	enemy = e;
}

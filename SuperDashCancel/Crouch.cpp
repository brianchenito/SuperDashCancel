#include "Crouch.h"



Crouch::Crouch(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


Crouch::~Crouch()
{
}

void Crouch::Enter()
{
	player->scale.y = PLAYER_SCALE.y / 1.5;
}

void Crouch::FixedUpdate()
{
	if (player->isEnemyLeft()) {
		forward = Input_Left;
		back = Input_Right;
	}
	else {
		forward = Input_Right;
		back = Input_Left;
	}

	if (!InputManager::Held(Input_Down, player->isPlayer1))
		player->ChangeState(IDLE);
	else if (InputManager::Held(back, player->isPlayer1))
		player->ChangeState(CROUCH_BLOCK);
}

void Crouch::Exit()
{
	player->scale.y = PLAYER_SCALE.y;
}

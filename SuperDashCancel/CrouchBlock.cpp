#include "CrouchBlock.h"



CrouchBlock::CrouchBlock(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


CrouchBlock::~CrouchBlock()
{
}

void CrouchBlock::Enter()
{
	player->scale.y = PLAYER_SCALE.y / 1.5;
	player->col = player->col - glm::vec3(0.05f, 0.05f, 0.05f);
}

void CrouchBlock::FixedUpdate()
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
	else if (!InputManager::Held(back, player->isPlayer1))
		player->ChangeState(CROUCH);
}

void CrouchBlock::Exit()
{
	player->scale.y = PLAYER_SCALE.y;
	player->col = player->col + glm::vec3(0.05f, 0.05f, 0.05f);
}

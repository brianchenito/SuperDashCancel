#include "CrouchBlock.h"



CrouchBlock::CrouchBlock(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


CrouchBlock::~CrouchBlock()
{
}

void CrouchBlock::Enter()
{
}

void CrouchBlock::FixedUpdate()
{
	player->SmoothScale(glm::vec2(PLAYER_SCALE.x, PLAYER_SCALE.y / 1.25f), 0.7f);
	if (player->isEnemyLeft())player->SmoothSkew(15.0f, 0.7f);
	else player->SmoothSkew(-15.0f, 0.7f);

	if (player->statebuffer.empty()) player->ChangeState(IDLE);
	else if (player->statebuffer.front() == CROUCH_BLOCK)
	{
		player->statebuffer.pop_front();


	}
	else
	{
		player->ChangeState(player->statebuffer.front());
		player->statebuffer.clear();
	}








}

void CrouchBlock::Exit()
{
}

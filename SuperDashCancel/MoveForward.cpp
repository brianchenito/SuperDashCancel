#include "MoveForward.h"


MoveForward::MoveForward(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


MoveForward::~MoveForward()
{
}

void MoveForward::Enter()
{
}

void MoveForward::FixedUpdate()
{
	player->Move(MOVE_SPEED);
	if (player->isEnemyLeft())player->SmoothSkew(20.0f, 0.7f);
	else player->SmoothSkew(-20.0f, 0.7f);

	if (player->statebuffer.empty()) player->ChangeState(IDLE);
	else if (player->statebuffer.front() == MOVE_FORWARD)
	{
		player->statebuffer.pop_front();

	}
	else
	{
		player->ChangeState(player->statebuffer.front());
		player->statebuffer.clear();
	}

}

void MoveForward::Exit()
{
}
#include "MoveBackward.h"


MoveBackward::MoveBackward(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


MoveBackward::~MoveBackward()
{
}

void MoveBackward::Enter()
{
}

void MoveBackward::FixedUpdate()
{
	player->Move(-MOVE_SPEED_BLOCKING);
	if (player->isEnemyLeft())player->SmoothSkew(-5.0f, 0.7f);
	else player->SmoothSkew(5.0f, 0.7f);
	player->SmoothScale(glm::vec2(PLAYER_SCALE.x, PLAYER_SCALE.y - 3.0f), 0.2f);
	if(player->statebuffer.empty()) player->ChangeState(IDLE);
	else if (player->statebuffer.front()==MOVE_BACKWARD)
	{
		player->statebuffer.pop_front();
	}
	else  
	{
		player->ChangeState(player->statebuffer.front());
		player->statebuffer.clear();
	}
}

void MoveBackward::Exit()
{
	//player->skew = 0.0f;
}
#include "BackDash.h"



BackDash::BackDash(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


BackDash::~BackDash()
{
}

void BackDash::Enter()
{
	if (!player->isEnemyLeft())direction = -1;
	else direction = 1;
	duration = 14;
	player->momentum = (glm::vec2(direction*40, 10));
	
}

void BackDash::FixedUpdate()
{
	if (duration > 0) 
	{
		//player->momentum = (glm::vec2(direction * 40, 10));

		player->SmoothSkew(direction*35.0f, 0.6f);
		duration--;
	}
	else 
	{
		player->ChangeState(IDLE);
	}

}

void BackDash::Exit()
{
}

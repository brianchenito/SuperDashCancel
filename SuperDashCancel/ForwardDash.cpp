#include "ForwardDash.h"






ForwardDash::ForwardDash(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}

ForwardDash::~ForwardDash()
{
}

void ForwardDash::Enter()
{
	if (player->isEnemyLeft())direction = -1;
	else direction = 1;
	duration = 10;
	player->momentum = (glm::vec2(direction * 44, 5));
}

void ForwardDash::FixedUpdate()
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

void ForwardDash::Exit()
{
}

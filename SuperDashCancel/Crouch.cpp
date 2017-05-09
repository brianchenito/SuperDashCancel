#include "Crouch.h"



Crouch::Crouch(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


Crouch::~Crouch()
{
}

void Crouch::Enter()
{
}

void Crouch::FixedUpdate()
{
	player->SmoothScale(glm::vec2(PLAYER_SCALE.x, PLAYER_SCALE.y / 1.25f), 0.7f);
	if (player->statebuffer.empty()) player->ChangeState(IDLE);
	else if (player->statebuffer.front() == CROUCH)
	{
		player->statebuffer.pop_front();
	}
	else
	{
		player->ChangeState(player->statebuffer.front());
		player->statebuffer.clear();
	}


}

void Crouch::Exit()
{
}

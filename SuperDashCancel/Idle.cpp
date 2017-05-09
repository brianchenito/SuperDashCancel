#include "Idle.h"



Idle::Idle(PlayerCharacter* p, PlayerStates pstate):PlayerState(p, pstate)
{
}


Idle::~Idle()
{
}

void Idle::Enter()
{
}

void Idle::FixedUpdate()
{
	if (!player->statebuffer.empty()) 
	{
		player->ChangeState(player->statebuffer.front());
		player->statebuffer.clear();
	}

	
}

void Idle::Exit()
{
}

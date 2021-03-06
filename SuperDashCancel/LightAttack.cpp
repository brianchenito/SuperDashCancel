#include "LightAttack.h"



LightAttack::LightAttack(PlayerCharacter* p, PlayerStates pstate) :Attack(p, pstate)
{
}


LightAttack::~LightAttack()
{
}

void LightAttack::Enter()
{

	startup = 4;
	active = 3;
	endlag = 8;
	hitstop = 5;
	hitstun = 17;
	blockstun = 15;
	damage = 25;
	knockback = glm::vec2(5, 0);
	hitbox = glm::vec4(60, 0, 80, 80);
	airborne = (player->pos.y > FLOOR_HEIGHT);
	low = false;
	Attack::Enter();
	player->lPunch.Reset();
	if (player->isEnemyLeft())player->SmoothSkew(20.0f, 0.6f);
	else player->SmoothSkew(-20.0f, 0.6f);
}

void LightAttack::FixedUpdate()
{
	Attack::FixedUpdate();
	
}

void LightAttack::Exit()
{
	Attack::Exit();
}

void LightAttack::EndLag()
{
	if (cancel && !player->statebuffer.empty())
	{
		while (!player->statebuffer.empty())
		{
			if (player->statebuffer.front() > currentState)
			{
				player->ChangeState(player->statebuffer.front());
				player->statebuffer.clear();
				return;
			}
			player->statebuffer.pop_front();
		}
	}
}

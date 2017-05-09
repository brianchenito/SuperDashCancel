#include "SlideHeavy.h"



SlideHeavy::SlideHeavy(PlayerCharacter * p, PlayerStates pstate) :Attack(p, pstate)
{
}


SlideHeavy::~SlideHeavy()
{
}

void SlideHeavy::Enter()
{
	startup = 10;
	active = 8;
	endlag = 28;
	hitstop = 10;
	hitstun = 32;
	blockstun = 10;
	damage = 70;
	knockback = glm::vec2(40, 20);
	hitbox = glm::vec4(0, -5, 160, 10);
	airborne = false;
	low = true;
	if (player->isEnemyLeft())direction = -1;
	else direction = 1;
	player->momentum = (glm::vec2(direction, 0));
	player->dashDust.Reset();
	Attack::Enter();
}

void SlideHeavy::FixedUpdate()
{
	player->SmoothScale(glm::vec2(PLAYER_SCALE.x, PLAYER_SCALE.y*0.5), 0.3f);
	if (player->isEnemyLeft())player->SmoothSkew(40.0f, 0.6f);
	else player->SmoothSkew(-40.0f, 0.6f);
	if (startup <= 0 && active > 0)player->momentum = (glm::vec2(25 * direction, -1));
	Attack::FixedUpdate();
}

void SlideHeavy::Exit()
{
	Attack::Exit();
}

void SlideHeavy::EndLag()
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

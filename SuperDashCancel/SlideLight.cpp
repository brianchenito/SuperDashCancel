#include "SlideLight.h"



SlideLight::SlideLight(PlayerCharacter * p, PlayerStates pstate) :Attack(p, pstate)
{
}


SlideLight::~SlideLight()
{
}

void SlideLight::Enter()
{
	startup = 6;
	active = 12;
	endlag = 24;
	hitstop = 5;
	hitstun = 32;
	blockstun = 20;
	damage = 50;
	knockback = glm::vec2(60, 10);
	hitbox = glm::vec4(0, -5, 120,10);
	airborne = false;
	low = true;
	if (player->isEnemyLeft())direction = -1;
	else direction = 1;
	player->momentum = (glm::vec2(direction, 0));
	player->dashDust.Reset();
	Attack::Enter();
}

void SlideLight::FixedUpdate()
{
	player->SmoothScale(glm::vec2(PLAYER_SCALE.x, PLAYER_SCALE.y*0.3), 0.3f);
	if (player->isEnemyLeft())player->SmoothSkew(35.0f, 0.6f);
	else player->SmoothSkew(-35.0f, 0.6f);
	if (startup <= 0 && active > 0)player->momentum = (glm::vec2(25 * direction, -1));
	Attack::FixedUpdate();
}

void SlideLight::Exit()
{
	Attack::Exit();
}

void SlideLight::EndLag()
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

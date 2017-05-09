#include "LightDash.h"





LightDash::LightDash(PlayerCharacter * p, PlayerStates pstate) :Attack(p, pstate)
{
}

LightDash::~LightDash()
{
}

void LightDash::Enter()
{
	startup = 6;
	active = 12;
	endlag = 16;
	hitstop = 5;
	hitstun = 32;
	blockstun = 24;
	damage = 40;
	knockback = glm::vec2(10, 0);
	hitbox = glm::vec4(0, -10, 100, 100);
	airborne = (player->pos.y > FLOOR_HEIGHT);
	if (player->isEnemyLeft())direction = -1;
	else direction = 1;
	Attack::Enter();

}

void LightDash::FixedUpdate()
{
	if (player->isEnemyLeft())player->SmoothSkew(30.0f, 0.6f);
	else player->SmoothSkew(-30.0f, 0.6f);
	if (startup <= 0 && active > 0)player->momentum = (glm::vec2(20 * direction, -4));
	Attack::FixedUpdate();

}

void LightDash::Exit()
{
	Attack::Exit();

}

void LightDash::EndLag()
{
	Attack::EndLag();

}

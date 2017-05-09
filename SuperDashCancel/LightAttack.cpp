#include "LightAttack.h"



LightAttack::LightAttack(PlayerCharacter* p, PlayerStates pstate) :Attack(p, pstate)
{
}


LightAttack::~LightAttack()
{
}

void LightAttack::Enter()
{

	startup = 5;
	active = 4;
	endlag = 13;
	hitstop = 10;
	hitstun = 18;
	damage = 15;
	knockback = glm::vec2(10, 0);
	hitbox = glm::vec4(60, 0, 80, 80);

	Attack::Enter();
	player->lPunch.Reset();
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
}

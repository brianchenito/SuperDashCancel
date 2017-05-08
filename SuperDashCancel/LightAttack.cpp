#include "LightAttack.h"



LightAttack::LightAttack(PlayerCharacter* p, PlayerStates pstate) :Attack(p, pstate)
{
}


LightAttack::~LightAttack()
{
}

void LightAttack::Enter()
{
	std::cout << "LightAttack->Enter()" << std::endl;

	startup = 3;
	active = 5;
	endlag = 4;
	hitstop = 10;
	hitstun = 6;
	damage = 50;
	knockback = glm::vec2(20, 5);
	hitbox = glm::vec4(40, 0, 80, 80);

	Attack::Enter();
}

void LightAttack::FixedUpdate()
{
	Attack::FixedUpdate();
}

void LightAttack::Exit()
{
	std::cout << "LightAttack->Exit()" << std::endl;
	Attack::Exit();
}

void LightAttack::EndLag()
{
}

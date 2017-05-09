#include "HeavyAttack.h"



HeavyAttack::HeavyAttack(PlayerCharacter* p, PlayerStates pstate) :Attack(p, pstate)
{
}


HeavyAttack::~HeavyAttack()
{
}

void HeavyAttack::Enter()
{

	startup = 8;
	active = 4;
	endlag = 20;
	hitstop = 10;
	hitstun = 24;
	blockstun = 15;
	damage = 70;
	knockback = glm::vec2(3, 20);
	hitbox = glm::vec4(80, 20, 80, 100);
	airborne = (player->pos.y > FLOOR_HEIGHT);
	low = false;
	Attack::Enter();
	player->lPunch.Reset();
	player->lPunch.col /= 1.5f;
	player->lPunch.scale.x *= 3.5f;
	player->lPunch.pos.x *= 3.5f;
	player->col /= 1.1f;
	if (player->isEnemyLeft())player->momentum=glm::vec2(5.0f, -0.6f);
	else player->momentum = glm::vec2(-5.0f, -0.6f);
}

void HeavyAttack::FixedUpdate()
{
	if (player->isEnemyLeft())player->SmoothSkew(30.0f, 0.6f);
	else player->SmoothSkew(-30.0f, 0.6f);

	Attack::FixedUpdate();
}

void HeavyAttack::Exit()
{
	player->lPunch.col *= 1.5f;
	player->lPunch.scale.x /= 3.5f;
	player->lPunch.pos.x /= 3.5f;
	player->col *= 1.1f;
	Attack::Exit();
	
}

void HeavyAttack::EndLag()
{
	std::cout << "endlag";
	if (cancel && !player->statebuffer.empty())
	{
		while (!player->statebuffer.empty())
		{
			std::cout << "statebuffer.front()" << player->statebuffer.front() << "\n";
			if (player->statebuffer.front() > currentState|| player->statebuffer.front()==AIRBORNE)
			{
				player->ChangeState(player->statebuffer.front());
				player->statebuffer.clear();
				return;
			}
			player->statebuffer.pop_front();
		}
	}
}

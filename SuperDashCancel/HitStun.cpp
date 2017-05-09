#include "HitStun.h"



HitStun::HitStun(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


HitStun::~HitStun()
{
}

void HitStun::Enter() {
	player->momentum.y += knockback.y;
	if (player->isEnemyLeft())
		player->momentum.x += knockback.x;
	else
		player->momentum.x -= knockback.x;
}

void HitStun::FixedUpdate() {
	if (stunLength > 0) { stunLength--; return; }
	player->ChangeState(IDLE);
}

void HitStun::Exit() {
}
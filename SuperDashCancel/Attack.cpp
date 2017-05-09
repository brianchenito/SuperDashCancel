#include "Attack.h"



Attack::Attack(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


Attack::~Attack()
{
}

void Attack::Enter() {	
	if (player->isEnemyLeft())
		hitbox.x = -hitbox.x;
	cancel = false;
}

void Attack::FixedUpdate() {
	if (startup > 0) { startup--; return; }
	if (active > 0) { 
		active--;
		if (!cancel&&DetectHit()) {
			player->hitstop = hitstop;
			player->enemy->hitstop = hitstop;
			player->enemy->health -= damage;
			((HitStun*)(player->enemy->stateMap[HIT_STUN]))->stunLength = hitstun;
			((HitStun*)(player->enemy->stateMap[HIT_STUN]))->knockback = knockback;
			player->enemy->ChangeState(HIT_STUN);
			cancel = true;
		}
		return;
	}
	if (endlag > 0) {
		endlag--;
		EndLag();
		return;
	}
	player->ChangeState(IDLE);
}

void Attack::Exit() {
	std::cout << "Attack->Exit()" << std::endl;
}

bool Attack::DetectHit() {
	int px = hitbox.x + player->pos.x - player->enemy->pos.x;
	int py = hitbox.y + player->pos.y - player->enemy->pos.y;
	int sx = (player->enemy->scale.x + hitbox.z) / 2;
	int sy = (player->enemy->scale.y + hitbox.w) / 2;

	px = (px > 0) ? px : -px;
	py = (py > 0) ? py : -py;

	if ((px < sx && py < sy))
		return true;
	else
		return false;
}

void Attack::EndLag()
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

#include "HitStun.h"



HitStun::HitStun(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


HitStun::~HitStun()
{
}

void HitStun::Enter() {
	flash = true;
	flashtimer = 0;
	player->momentum.y += knockback.y;
	if (player->isEnemyLeft())
		player->momentum.x += knockback.x;
	else
		player->momentum.x -= knockback.x;
}

void HitStun::FixedUpdate() {
	if (stunLength > 0) 
	{

		if (flashtimer == 5) 
		{
			player->setColor(player->isPlayer1 ? PLAYER_ONE_COLOR + (glm::vec3(0.2f, 0.2f, 0.2f)*flash) : PLAYER_TWO_COLOR + (glm::vec3(0.2f, 0.2f, 0.2f)*flash));
			flash = !flash;
			flashtimer = 0;
		}
		if (player->isEnemyLeft())player->SmoothSkew(30.0f, 0.7f);
		else player->SmoothSkew(-30.0f, 0.7f);
		player->SmoothScale(glm::vec2(PLAYER_SCALE.x*0.9f, PLAYER_SCALE.y*1.1f),0.9f);
		flashtimer++;
		stunLength--; 
		return; 
	}
	player->ChangeState(IDLE);
}

void HitStun::Exit() {
	player->setColor(player->isPlayer1 ? PLAYER_ONE_COLOR : PLAYER_TWO_COLOR);
}
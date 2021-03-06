#pragma once
#include "PlayerCharacter.h"
class HitStun :
	public PlayerState
{
private:
	bool flash;
	int flashtimer;
public:
	int stunLength;
	glm::vec2 knockback;

	HitStun(PlayerCharacter* p, PlayerStates pstate);
	~HitStun();
	void Enter();
	void FixedUpdate();
	void Exit();
};


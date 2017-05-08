#pragma once
#include "PlayerCharacter.h"
#include "HitStun.h"
class Attack :
	public PlayerState
{
protected:
	int startup;
	int active;
	int endlag;
	int hitstop;
	int hitstun;
	int damage;
	glm::vec2 knockback;

public:
	glm::vec4 hitbox;
	
	Attack(PlayerCharacter* p, PlayerStates pstate);
	~Attack();
	void Enter();
	void FixedUpdate();
	void Exit();
	bool DetectHit();
	virtual void EndLag() = 0;
};


#pragma once
#include "PlayerCharacter.h"
#include "HitStun.h"
class Attack :
	public PlayerState
{
protected:
	// configuration data
	int startup;
	int active;
	int endlag;
	int hitstop;
	int hitstun;
	int blockstun;
	int damage;
	glm::vec2 knockback;
	bool cancel;
	bool airborne;
	bool low;

public:
	glm::vec4 hitbox;
	
	Attack(PlayerCharacter* p, PlayerStates pstate);
	~Attack();
	void Enter();
	void FixedUpdate();
	void Exit();
	bool DetectHit();
	void EndLag();
};


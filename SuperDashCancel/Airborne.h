#pragma once
#include "PlayerCharacter.h"
class Airborne :
	public PlayerState
{
	bool doubleJump;
public:
	Airborne(PlayerCharacter* p, PlayerStates pstate);
	~Airborne();
	void Enter();
	void FixedUpdate();
	void Exit();
};


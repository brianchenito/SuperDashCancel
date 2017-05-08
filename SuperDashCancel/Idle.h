#pragma once
#include "PlayerCharacter.h"
class Idle : public PlayerState
{
public:
	Idle(PlayerCharacter* p, PlayerStates pstate);
	~Idle();
	void Enter();
	void FixedUpdate();
	void Exit();
};


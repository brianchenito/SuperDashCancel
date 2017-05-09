#pragma once
#include "PlayerCharacter.h"
class ForwardDash :
	public PlayerState
{
	int direction;
	int duration;
public:
	ForwardDash(PlayerCharacter* p, PlayerStates pstate);
	~ForwardDash();
	void Enter();
	void FixedUpdate();
	void Exit();
};


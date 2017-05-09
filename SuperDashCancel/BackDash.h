#pragma once
#include "PlayerCharacter.h"
class BackDash :
	public PlayerState
{
	int direction;
	int duration;
public:
	BackDash(PlayerCharacter* p, PlayerStates pstate);
	~BackDash();
	void Enter();
	void FixedUpdate();
	void Exit();
};


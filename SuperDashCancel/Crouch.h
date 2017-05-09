#pragma once
#include "PlayerCharacter.h"
class Crouch :
	public PlayerState
{
public:
	Crouch(PlayerCharacter* p, PlayerStates pstate);
	~Crouch();
	void Enter();
	void FixedUpdate();
	void Exit();
};


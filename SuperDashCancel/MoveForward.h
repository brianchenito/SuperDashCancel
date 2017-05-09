#pragma once
#include "PlayerCharacter.h"

class MoveForward :
	public PlayerState
{
public:

	MoveForward(PlayerCharacter* p, PlayerStates pstate);
	~MoveForward(); 
	void Enter();
	void FixedUpdate();
	void Exit();
};


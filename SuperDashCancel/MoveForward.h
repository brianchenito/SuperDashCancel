#pragma once
#include "PlayerCharacter.h"

class MoveForward :
	public PlayerState
{
public:
	Input direction;

	MoveForward(PlayerCharacter* p, PlayerStates pstate);
	~MoveForward(); 
	void Enter();
	void FixedUpdate();
	void Exit();
};


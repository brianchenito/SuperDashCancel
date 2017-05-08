#pragma once
#include "PlayerCharacter.h"
class MoveBackward :
	public PlayerState
{
public:
	Input direction;

	MoveBackward(PlayerCharacter* p, PlayerStates pstate);
	~MoveBackward();
	void Enter();
	void FixedUpdate();
	void Exit();
};


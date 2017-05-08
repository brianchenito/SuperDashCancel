#pragma once
#include "PlayerCharacter.h"
class Crouch :
	public PlayerState
{
public:
	Input forward;
	Input back;

	Crouch(PlayerCharacter* p, PlayerStates pstate);
	~Crouch();
	void Enter();
	void FixedUpdate();
	void Exit();
};


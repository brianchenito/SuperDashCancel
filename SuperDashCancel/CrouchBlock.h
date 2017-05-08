#pragma once
#include "PlayerCharacter.h"
class CrouchBlock :
	public PlayerState
{
public:
	Input forward;
	Input back;

	CrouchBlock(PlayerCharacter* p, PlayerStates pstate);
	~CrouchBlock();
	void Enter();
	void FixedUpdate();
	void Exit();
};
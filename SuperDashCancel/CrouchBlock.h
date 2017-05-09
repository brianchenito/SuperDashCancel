#pragma once
#include "PlayerCharacter.h"
class CrouchBlock :
	public PlayerState
{
public:

	CrouchBlock(PlayerCharacter* p, PlayerStates pstate);
	~CrouchBlock();
	void Enter();
	void FixedUpdate();
	void Exit();
};
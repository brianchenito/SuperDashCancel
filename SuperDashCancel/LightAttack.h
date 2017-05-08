#pragma once
#include "Attack.h"
class LightAttack :
	public Attack
{
public:
	LightAttack(PlayerCharacter* p, PlayerStates pstate);
	~LightAttack();
	void Enter();
	void FixedUpdate();
	void Exit();
	void EndLag();
};


#pragma once
#include "Attack.h"
class HeavyAttack :
	public Attack
{
public:
	HeavyAttack(PlayerCharacter* p, PlayerStates pstate);
	~HeavyAttack();
	void Enter();
	void FixedUpdate();
	void Exit();
	void EndLag();

};


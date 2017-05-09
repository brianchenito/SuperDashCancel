#pragma once
#include "Attack.h"
class LightDash :
	public Attack
{
private:
	int direction;
public:
	LightDash(PlayerCharacter* p, PlayerStates pstate);
	~LightDash();
	void Enter();
	void FixedUpdate();
	void Exit();
	void EndLag();
};


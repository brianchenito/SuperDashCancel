#pragma once
#include "Attack.h"
class SlideHeavy :
	public Attack
{
	int direction;

public:
	SlideHeavy(PlayerCharacter* p, PlayerStates pstate);
	~SlideHeavy();
	void Enter();
	void FixedUpdate();
	void Exit();
	void EndLag();
};


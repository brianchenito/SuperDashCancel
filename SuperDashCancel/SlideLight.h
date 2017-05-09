#pragma once
#include "Attack.h"
class SlideLight :
	public Attack
{
	int direction;

public:
	SlideLight(PlayerCharacter* p, PlayerStates pstate);
	~SlideLight();
	void Enter();
	void FixedUpdate();
	void Exit();
	void EndLag();
};


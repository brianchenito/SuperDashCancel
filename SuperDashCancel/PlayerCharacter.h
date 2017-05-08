#pragma once
#include "DrawableSprite.h"
#include "InputManager.h"
#include "Input.h"
#include <map>

enum PlayerStates {
	IDLE, MOVE_FORWARD, MOVE_BACKWARD, CROUCH, CROUCH_BLOCK, AIRBORNE, HIT_STUN,
	LIGHT_DASH, LIGHT_ATTACK, LIGHT_CROUCH_ATTACK, LIGHT_SLIDE,
	HEAVY_DASH, HEAVY_ATTACK, HEAVY_CROUCH_ATTACK, HEAVY_SLIDE
};

class PlayerCharacter;

class PlayerState
{
public:
	PlayerStates currentState;

	PlayerCharacter* player;

	PlayerState(PlayerCharacter* p, PlayerStates pstate) {
		player = p;
		currentState = pstate;
	}
	~PlayerState() {}

	virtual void Enter() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Exit() = 0;
};



class PlayerCharacter : public DrawableSprite
{

public:
	int health;
	int hitstop;
	bool isPlayer1; 
	glm::vec2 momentum;
	PlayerCharacter* enemy;
	PlayerState* activeState;
	std::map<PlayerStates, PlayerState*> stateMap;

	PlayerCharacter();
	PlayerCharacter(bool player1);
	~PlayerCharacter();

	void Draw();

	void FixedUpdate();
	void ChangeState(PlayerStates pstate);
	void SetEnemyPlayer(PlayerCharacter* e);

	void Move(glm::vec2 delta);
	void PhysicsMove();
	bool isEnemyLeft();
};

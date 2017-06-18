#pragma once
#include "DrawableSprite.h"
#include "InputManager.h"
#include "DrawableSpriteSheet.h"
#include "Input.h"
#include <map>
#include <deque>
#include <stdlib.h> 
// states are arranged in order of increasing priority
enum PlayerStates {
	IDLE, MOVE_FORWARD, MOVE_BACKWARD, CROUCH, CROUCH_BLOCK, AIRBORNE, HIT_STUN,
	LIGHT_DASH, LIGHT_ATTACK, LIGHT_SLIDE, LIGHT_CROUCH_ATTACK, 
	HEAVY_DASH, HEAVY_ATTACK, HEAVY_SLIDE, HEAVY_CROUCH_ATTACK,
	BACK_DASH, FORWARD_DASH, FIREBALL, UPPERCUT
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
private:
	bool scalechange;
	bool skewchange;
	std::deque<Input> inputbuffer;
	
	int inputtimer;
	int statetimer;
	
public:
	DrawableSpriteSheet lPunch;
	DrawableSpriteSheet dashDust;
	DrawableSpriteSheet block;
	std::deque<PlayerStates> statebuffer;
	int health;
	int hitstop;
	int blockstun;
	bool isPlayer1; 
	float skew;
	glm::vec2 momentum;
	PlayerCharacter* enemy;
	PlayerState* activeState;
	PlayerState* bufferedState;
	std::map<PlayerStates, PlayerState*> stateMap;

	PlayerCharacter();
	PlayerCharacter(bool player1);
	~PlayerCharacter();

	void Draw();
	void DrawSheetsBehind();
	void DrawSheetsInFront();
	void ClearSheets();
	void FixedUpdate();
	void ChangeState(PlayerStates pstate);
	void SetEnemyPlayer(PlayerCharacter* e);

	void Move(glm::vec2 delta);
	void PhysicsMove();
	bool isEnemyLeft();
	void EnqueueStates();
	void SmoothScale(glm::vec2 newscale, float weight);
	void SmoothSkew(float newskew, float weight);
};

#include "Idle.h"



Idle::Idle(PlayerCharacter* p, PlayerStates pstate):PlayerState(p, pstate)
{
}


Idle::~Idle()
{
}

void Idle::Enter()
{
	std::cout << "Idle->Enter()" << std::endl;
}

void Idle::FixedUpdate()
{
	if (InputManager::Held(Input_Down, player->isPlayer1)) {
		if (InputManager::Held(Input_Right, player->isPlayer1) && player->isEnemyLeft()
		 || InputManager::Held(Input_Left, player->isPlayer1) && !player->isEnemyLeft()) {
			player->ChangeState(CROUCH_BLOCK);
		}
		else {
			player->ChangeState(CROUCH);
		}
	}
	else if (InputManager::Pressed(Input_Up, player->isPlayer1)) {
		player->ChangeState(AIRBORNE);
	}
	else if (InputManager::Held(Input_Left, player->isPlayer1)) {
		if (player->isEnemyLeft())
			player->ChangeState(MOVE_FORWARD);
		else
			player->ChangeState(MOVE_BACKWARD);
	}
	else if (InputManager::Held(Input_Right, player->isPlayer1)) {
		if (player->isEnemyLeft())
			player->ChangeState(MOVE_BACKWARD);
		else
			player->ChangeState(MOVE_FORWARD);
	}
	else if (InputManager::Pressed(Input_Light, player->isPlayer1)) {
		player->ChangeState(LIGHT_ATTACK);
	}
	
}

void Idle::Exit()
{
	std::cout << "Idle->Exit()" << std::endl;
}

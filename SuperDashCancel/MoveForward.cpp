#include "MoveForward.h"


MoveForward::MoveForward(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


MoveForward::~MoveForward()
{
}

void MoveForward::Enter()
{
	std::cout << "MoveForward->Enter()" << std::endl;
}

void MoveForward::FixedUpdate()
{

	if (player->isEnemyLeft())
		direction = Input_Left;
	else
		direction = Input_Right;


	if (InputManager::Pressed(Input_Up, player->isPlayer1)) {
		if (direction == Input_Left)
			player->momentum.x = -MOVE_SPEED.x;
		else 
			player->momentum.x = MOVE_SPEED.x;
		player->ChangeState(AIRBORNE);
	}
	else if (!InputManager::Held(direction, player->isPlayer1))
		player->ChangeState(IDLE);
	else
		player->Move(MOVE_SPEED);

}

void MoveForward::Exit()
{
	std::cout << "MoveForward->Exit()" << std::endl;
}
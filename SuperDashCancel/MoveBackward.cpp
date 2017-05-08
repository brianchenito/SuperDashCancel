#include "MoveBackward.h"


MoveBackward::MoveBackward(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


MoveBackward::~MoveBackward()
{
}

void MoveBackward::Enter()
{
	std::cout << "MoveBackward->Enter()" << std::endl;
}

void MoveBackward::FixedUpdate()
{
	if (player->isEnemyLeft())
		direction = Input_Right;
	else
		direction = Input_Left;

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
		player->Move(-MOVE_SPEED);

}

void MoveBackward::Exit()
{
	std::cout << "MoveBackward->Exit()" << std::endl;
}
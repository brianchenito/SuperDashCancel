#include "Airborne.h"



Airborne::Airborne(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


Airborne::~Airborne()
{
}

void Airborne::Enter()
{
	std::cout << "Airborne Enter()" << std::endl;
	player->momentum.y = JUMP_HEIGHT;
}

void Airborne::FixedUpdate()
{

	if (player->pos.y <= FLOOR_HEIGHT)
		player->ChangeState(CROUCH);
	else if (InputManager::Held(Input_Left, player->isPlayer1)) {
		player->momentum.x -= AIRBORNE_CONTROL;
		if (player->momentum.x < -MOVE_SPEED.x) {
			player->momentum.x = -MOVE_SPEED.x;
		}
	}
	else if (InputManager::Held(Input_Right, player->isPlayer1)) {
		player->momentum.x += AIRBORNE_CONTROL;
		if (player->momentum.x > MOVE_SPEED.x) {
			player->momentum.x = MOVE_SPEED.x;
		}
	}
}

void Airborne::Exit()
{
}

#include "Airborne.h"



Airborne::Airborne(PlayerCharacter* p, PlayerStates pstate) :PlayerState(p, pstate)
{
}


Airborne::~Airborne()
{
}

void Airborne::Enter()
{
	doubleJump = true;
	player->momentum.y = JUMP_HEIGHT;
}

void Airborne::FixedUpdate()
{

	if (player->pos.y <= FLOOR_HEIGHT)
		player->ChangeState(CROUCH);
	else
	{
		if(
			!player->statebuffer.empty()
			&& player->statebuffer.front()!=MOVE_FORWARD && player->statebuffer.front() != MOVE_BACKWARD
			&& player->statebuffer.front() != CROUCH && player->statebuffer.front() != CROUCH_BLOCK
			&& player->statebuffer.front()!=AIRBORNE
			) 
		{
			player->ChangeState(player->statebuffer.front());
		}


		if (player->scale.y > PLAYER_SCALE.y)player->scale.y -= PLAYER_SCALE.y/5;
		player->skew = -player->momentum.x*20;
		player->scale.y= PLAYER_SCALE.y+(player->momentum.y/4)*(player->momentum.y / 4);

		if (doubleJump&&InputManager::Pressed(Input_Up, player->isPlayer1)) 
		{
			doubleJump = false;
			player->momentum.y = JUMP_HEIGHT;
		}
		if (InputManager::Held(Input_Left, player->isPlayer1)) {
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
}

void Airborne::Exit()
{
}

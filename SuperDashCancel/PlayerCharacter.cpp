#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() {}

PlayerCharacter::PlayerCharacter(bool player1)
{
	bufferedState = 0;
	isPlayer1 = player1;

	if (isPlayer1) col = PLAYER_ONE_COLOR;
	else col = PLAYER_TWO_COLOR;
	scale = PLAYER_SCALE;

	loadTexture("../SuperDashCancel/textures/texture4.png", ALPHA);

	activeState = 0;
	health = 1000;
	skew = 0;

	lPunch = DrawableSpriteSheet(glm::vec2(0, 0), glm::vec2(64, 120), player1?glm::vec3(0.35f,0.873f,0.93f):glm::vec3(0.96f,0.73f,0.62f), 3, 2);
	lPunch.loadTexture("../SuperDashCancel/textures/Sheet2.png", ALPHA);
	block = DrawableSpriteSheet(glm::vec2(0, 0), glm::vec2(128	, 162), player1?glm::vec3(0.35f,0.873f,0.93f):glm::vec3(0.96f,0.73f,0.62f), 3, 2);
	block.loadTexture("../SuperDashCancel/textures/Sheet3.png", ALPHA);
	dashDust= DrawableSpriteSheet(glm::vec2(0, 0), glm::vec2(180, 79), glm::vec3(1,1,1), 4, 3);
	dashDust.loadTexture("../SuperDashCancel/textures/Sheet1.png", ALPHA);
	enemy = 0;
}

void PlayerCharacter::Draw() {
	// offset pos for draw
	pos.x -= PLAYER_SCALE.x / 2;


	glColor3f(col.r, col.g, col.b);
	glBindTexture(GL_TEXTURE_2D, TexID);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBegin(GL_QUADS);


	glm::vec2 coords = Drawable::projection*glm::vec4(pos.x, pos.y, 0, 1);
	glm::vec2 coords2 = Drawable::projection*glm::vec4(pos.x + scale.x, pos.y + scale.y, 0, 1);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(coords.x, coords.y);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(coords2.x, coords.y);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(coords2.x + skew / 1280.0f, coords2.y);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(coords.x + skew / 1280.0f, coords2.y);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	
	// reset pos to middle
	pos.x += PLAYER_SCALE.x / 2;

	

}

void PlayerCharacter::DrawSheetsBehind()
{
	if(pos.y == FLOOR_HEIGHT)dashDust.Draw();
}

void PlayerCharacter::DrawSheetsInFront()
{
	lPunch.Draw();
	block.Draw();

}

void PlayerCharacter::ClearSheets()
{
	lPunch.Clear();
	dashDust.Clear();
	block.Clear();
}

void PlayerCharacter::FixedUpdate() {
	// 	resolve buffered state changes
	if (bufferedState) 
	{
		if (activeState) activeState->Exit();
		activeState = bufferedState;
		activeState->Enter();
		bufferedState = 0;

	}
	EnqueueStates();
	// dont do gameplay stuff if hitstop
	if (hitstop > 0) 
	{
		// cause hitstop is global
		if(isPlayer1)Drawable::projection = glm::ortho(0.0f, 1280.0f + (rand() % hitstop - hitstop / 2), 0.0f, 720.0f + (rand() % hitstop - hitstop / 2));
		hitstop--; 
		return;

	}
	if (hitstop == 0)
	{
		hitstop--;
		Drawable::projection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f);
	}

	if (pos.y == FLOOR_HEIGHT&&enemy->pos.y == FLOOR_HEIGHT &&
		(fabs(pos.x - enemy->pos.x) < PLAYER_SCALE.x)) 
	{
		if (isEnemyLeft()) 
			pos.x += 5;
		else 
			pos.x -= 5;

		
	}


	if (activeState) activeState->FixedUpdate();
	PhysicsMove();
	if (!scalechange) 
	{
		scale = 0.3f*scale + 0.7*PLAYER_SCALE;
	}
	if(!skewchange)skew = 0.3f*skew;
	scalechange = false;
	skewchange = false;
	
	//position sprites

	lPunch.leftOrigin = !isEnemyLeft();
	lPunch.pos = pos;
	lPunch.pos.y += 40;
	if (isEnemyLeft())lPunch.pos.x -= 70;
	else lPunch.pos.x += 70;
	lPunch.FixedStep();

	block.leftOrigin = !isEnemyLeft();
	block.pos = pos;
	block.pos.y += 40;
	if (isEnemyLeft())block.pos.x -= 40;
	else block.pos.x += 40;
	block.FixedStep();

	dashDust.leftOrigin = (momentum.x > 0);

	dashDust.pos = pos;
	dashDust.pos.y += 38;

	if (momentum.x > 0)dashDust.pos.x -= 130;
	else dashDust.pos.x += 130;
	dashDust.FixedStep();
}

void PlayerCharacter::ChangeState(PlayerStates pstate) {
	if (stateMap.find(pstate) != stateMap.end()) {
		if (pos.y > FLOOR_HEIGHT) // entry restricts for grounded only states
		{
			if (pstate == CROUCH_BLOCK || pstate == CROUCH||pstate == AIRBORNE||pstate==HEAVY_SLIDE||pstate==LIGHT_SLIDE)return;
		}
		bufferedState=stateMap[pstate];

	}
	else {
		std::cout << "ChangeState attempt failed: " << pstate << " is not a valid state" << std::endl;
	}
}

PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::Move(glm::vec2 delta) {
	//Movement
	if (isEnemyLeft()) 
		pos -= delta;
	else 
		pos += delta;

	if (pos.y == FLOOR_HEIGHT&&enemy->pos.y == FLOOR_HEIGHT&&
		(fabs(pos.x-enemy->pos.x)<PLAYER_SCALE.x))
	{
		if(delta.x!=0)
		{
			if (isEnemyLeft()) 
			{
				enemy->pos.x-=delta.x / 2;
				pos.x += delta.x / 2;
			} 
			else 
			{
				enemy->pos.x += delta.x / 2;
				pos.x -= delta.x / 2;
			}
		}
	}
	
	//Boundaries
	if (pos.y < FLOOR_HEIGHT) pos.y = FLOOR_HEIGHT;
	if (pos.y > CEILING_HEIGHT) pos.y = CEILING_HEIGHT;
	if (pos.x < WALL_LEFT) pos.x = WALL_LEFT;
	if (pos.x > WALL_RIGHT) pos.x = WALL_RIGHT;
}

void PlayerCharacter::PhysicsMove() {
	//Momentum
	pos += momentum;

	//Friction
	if (momentum.x < 0.01f || momentum.x > -0.01f)
		momentum.x /= 1.25f;
	else
		momentum.x = 0;

	//Gravity
	if (pos.y > FLOOR_HEIGHT) {
		momentum.y += GRAVITY;
	}
	else {
		if (momentum.y < 0)
			momentum.y = 0;
	}

	if (pos.y == FLOOR_HEIGHT&&enemy->pos.y == FLOOR_HEIGHT &&
		(fabs(pos.x - enemy->pos.x)<PLAYER_SCALE.x))
	{
		if (momentum.x != 0)
		{
			if (isEnemyLeft())
			{
				enemy->pos.x -= momentum.x / 2;
				pos.x += momentum.x / 2;
			}
			else
			{
				enemy->pos.x += momentum.x / 2;
				pos.x -= momentum.x / 2;
			}
		}
	}


	//Boundaries
	if (pos.y < FLOOR_HEIGHT) pos.y = FLOOR_HEIGHT;
	if (pos.y > CEILING_HEIGHT) pos.y = CEILING_HEIGHT;
	if (pos.x < WALL_LEFT) pos.x = WALL_LEFT;
	if (pos.x > WALL_RIGHT) pos.x = WALL_RIGHT;
	

}

bool PlayerCharacter::isEnemyLeft() {
	return ((enemy!=0)&&enemy->GetPos().x - GetPos().x < 0);
}

void PlayerCharacter::EnqueueStates()
{
	// clear input buffer if its time
	if (inputtimer == 0) inputbuffer.clear();
	else inputtimer--;
	if (inputbuffer.size() > 8) inputbuffer.erase(inputbuffer.begin() + 8, inputbuffer.end());
	if (statetimer == 0)statebuffer.clear();
	else statetimer--;
	if (statebuffer.size() > 4) statebuffer.erase(statebuffer.begin() + 4, statebuffer.end());
	int vert = 0; int horz = 0;
	if (InputManager::Pressed(Input_Up, isPlayer1)|| InputManager::Pressed(Input_Down, isPlayer1)|| InputManager::Pressed(Input_Left, isPlayer1)|| InputManager::Pressed(Input_Right, isPlayer1))
	{
		inputtimer = 14;
		statetimer = 14;
		if (InputManager::Held(Input_Up, isPlayer1))vert++;
		if (InputManager::Held(Input_Down, isPlayer1))vert--;

		if (InputManager::Held(Input_Right, isPlayer1))horz++;
		if (InputManager::Held(Input_Left, isPlayer1))horz--;
		//enqueue commands
		if (vert == 0)
		{
			if (horz == 1)inputbuffer.push_front(Input_Right);
			else if (horz == -1)inputbuffer.push_front(Input_Left);
		}
		else if (horz == 0)
		{
			if (vert == 1)inputbuffer.push_front(Input_Up);
			else if (vert == -1)inputbuffer.push_front(Input_Down);
		}
		else 
		{
			if (horz == 1 && vert == 1) inputbuffer.push_front(Input_UpR);
			else if (horz == -1 && vert == 1) inputbuffer.push_front(Input_UpL);
			else if (horz == 1 && vert == -1) inputbuffer.push_front(Input_DownR);
			else if (horz == -1 && vert == -1) inputbuffer.push_front(Input_UpL);
		}
	}


	if (InputManager::Pressed(Input_Light, isPlayer1))
	{
		inputtimer = 14;
		statetimer = 14;
		inputbuffer.push_front(Input_Light);
	}
	if (InputManager::Pressed(Input_Heavy, isPlayer1))
	{
		inputtimer = 14;
		statetimer = 14;
		inputbuffer.push_front(Input_Heavy);
	}
	
	// long ass conditional checks to enqueue state conditions

	if (inputbuffer.size() >= 2 && (inputbuffer[0] == Input_Left&&inputbuffer[1] == Input_Left)) 
	{

		if (!isEnemyLeft())statebuffer.push_front(BACK_DASH);
		else statebuffer.push_front(FORWARD_DASH);
		inputbuffer.clear();
	}
	if (inputbuffer.size() >= 2 && (inputbuffer[0] == Input_Right&&inputbuffer[1] == Input_Right))
	{

		if (isEnemyLeft())statebuffer.push_front(BACK_DASH);
		else statebuffer.push_front(FORWARD_DASH);
		inputbuffer.clear();
	}

	//handle movement and etc.
	if (statebuffer.empty())
	{
		if (InputManager::Held(Input_Up, isPlayer1))statebuffer.push_front(AIRBORNE);
		if (InputManager::Held(Input_Down, isPlayer1))
		{
			if ((isEnemyLeft() && InputManager::Held(Input_Right, isPlayer1)) || (!isEnemyLeft() && InputManager::Held(Input_Left, isPlayer1))) 
			{
				statebuffer.push_front(CROUCH_BLOCK);
			}
			else 
			{
				statebuffer.push_front(CROUCH);
			}
			
		}

		if (InputManager::Held(Input_Left, isPlayer1))
		{
			if (isEnemyLeft())
			{
				if (InputManager::Held(Input_Down, isPlayer1))statebuffer.push_front(CROUCH);
				else statebuffer.push_front(MOVE_FORWARD);
			}
			else
			{
				if (InputManager::Held(Input_Down, isPlayer1))statebuffer.push_front(CROUCH_BLOCK);
				else statebuffer.push_front(MOVE_BACKWARD);
			}
		}
		if (InputManager::Held(Input_Right, isPlayer1))
		{
			if (!isEnemyLeft())
			{
				if (InputManager::Held(Input_Down, isPlayer1))statebuffer.push_front(CROUCH);
				else statebuffer.push_front(MOVE_FORWARD);
			}
			else
			{
				if (InputManager::Held(Input_Down, isPlayer1))statebuffer.push_front(CROUCH_BLOCK);
				else statebuffer.push_front(MOVE_BACKWARD);
			}
		}
	}
	// Light attacks have second priority
	if (InputManager::Pressed(Input_Light, isPlayer1))
	{
		if ((isEnemyLeft() && InputManager::Held(Input_Left, isPlayer1)) || (!isEnemyLeft() && InputManager::Held(Input_Right, isPlayer1)))
		{
			if (InputManager::Held(Input_Down, isPlayer1))statebuffer.push_front(LIGHT_SLIDE);
			else statebuffer.push_front(LIGHT_DASH);
		}
		else
		{
			if (InputManager::Held(Input_Down, isPlayer1))statebuffer.push_front(LIGHT_CROUCH_ATTACK);
			else statebuffer.push_front(LIGHT_ATTACK);
		}
	}
	// heavy attacks have top priority
	if (InputManager::Pressed(Input_Heavy, isPlayer1))
	{
		if ((isEnemyLeft() && InputManager::Held(Input_Left, isPlayer1)) || (!isEnemyLeft() && InputManager::Held(Input_Right, isPlayer1)))
		{
			//std::cout << "Dash Heavy\n";
			if (InputManager::Held(Input_Down, isPlayer1))statebuffer.push_front(HEAVY_SLIDE);
			else statebuffer.push_front(HEAVY_DASH);
		}
		else
		{
			//std::cout << "Neutral Heavy\n";
			if (InputManager::Held(Input_Down, isPlayer1))statebuffer.push_front(HEAVY_CROUCH_ATTACK);
			else statebuffer.push_front(HEAVY_ATTACK);
		}
	}
}

void PlayerCharacter::SmoothScale(glm::vec2 newscale, float weight)
{
	scalechange = true;
	scale = scale*(1-weight) + newscale*(weight);
}

void PlayerCharacter::SmoothSkew(float newskew,float weight)
{
	skewchange = true;
	skew = skew*(1 - weight) + newskew*(weight);

}

void PlayerCharacter::SetEnemyPlayer(PlayerCharacter * e)
{
	enemy = e;
}

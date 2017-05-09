#pragma once
// whenever you make changes to this, literally half of the project recompiles, just a warning
#define PLAYER_ONE_COLOR glm::vec3(0.97f, 0.95f, 0.94f)
#define PLAYER_TWO_COLOR glm::vec3(0.6f, 0.3f, 0.3f)

#define PLAYER_SCALE glm::vec2(80,80)
#define MOVE_SPEED glm::vec2(6, 0)
#define MOVE_SPEED_BLOCKING glm::vec2(4.5f,0)
#define JUMP_HEIGHT 25.0f
#define AIRBORNE_CONTROL 3.0f
#define GRAVITY -1.8f

#define FLOOR_HEIGHT 160.0f
#define CEILING_HEIGHT 660.0f
#define WALL_LEFT 50.0f
#define WALL_RIGHT 1230.0f
#pragma once
#include "DrawableSprite.h"
class DrawableSpriteSheet :public DrawableSprite
{
	int indexh, indexw;
	int h;
	int w;
	bool by2;
public:
	void Reset();
	void Clear();
	bool leftOrigin;
	DrawableSpriteSheet();
	DrawableSpriteSheet(glm::vec2 Pos, glm::vec2 Scale, glm::vec3 Color, int horiz, int vert);
	~DrawableSpriteSheet();
	void Draw();
	void FixedStep();
};


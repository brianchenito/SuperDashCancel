#include "Drawable.h"



void Drawable::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Drawable::setPos(Vec2 pos)
{
	this->pos = pos;
}

void Drawable::setScale(float x, float y)
{
	scale.x = x;
	scale.y = y;
}

void Drawable::setScale(Vec2 Scale)
{
	this->scale = Scale;
}


Drawable::Drawable()
{
}


Drawable::~Drawable()
{
}

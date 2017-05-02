#include "Drawable.h"



void Drawable::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Drawable::setPos(glm::vec2 pos)
{
	this->pos = pos;
}

void Drawable::setScale(float x, float y)
{
	scale.x = x;
	scale.y = y;
}

void Drawable::setScale(glm::vec2 Scale)
{
	this->scale = Scale;
}

void Drawable::setColor(float r, float g, float b, float a)
{
	col.r = r;
	col.g = g;
	col.b = b;
}

void Drawable::setColor(const glm::vec3 c)
{
	col = c;
}

glm::vec2 Drawable::PixelSpaceToScreenSpace(glm::vec2 v)
{
	v.x /= 640;
	v.y /= 360;
	v.x -= 1;
	v.y -= 1;
	return v;
}

glm::vec2 Drawable::ScreenSpaceToPixelSpace(glm::vec2 v)
{
	v.x += 1;
	v.y += 1;
	v.x *= 640;
	v.y *= 260;
	return v;
}



Drawable::Drawable()
{
}

Drawable::Drawable(glm::vec2 Pos, glm::vec2 Scale,glm::vec3 col)
{
	this->pos = Pos;
	this->scale = Scale;
	this->col = col;
}


Drawable::~Drawable()
{
}

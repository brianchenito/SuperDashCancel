#include "Drawable.h"

glm::mat4 Drawable::projection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f);


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

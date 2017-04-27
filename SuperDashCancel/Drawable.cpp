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

void Drawable::setColor(float r, float g, float b, float a)
{
	col.r = r;
	col.g = g;
	col.b = b;
	col.a = a;
}

void Drawable::setColor(const Color & c)
{
	col = c;
}

Vec2 Drawable::PixelSpaceToScreenSpace(Vec2 v)
{
	v.x /= 640;
	v.y / 360;
	v.x -= 1;
	v.y -= 1;
	return v;
}

Vec2 Drawable::ScreenSpaceToPixelSpace(Vec2 v)
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

Drawable::Drawable(Vec2 Pos, Vec2 Scale, Color col)
{
	this->pos = Pos;
	this->scale = Scale;
	this->col = col;
}


Drawable::~Drawable()
{
}

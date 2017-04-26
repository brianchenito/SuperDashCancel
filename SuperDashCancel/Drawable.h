#pragma once
#include <stb_image.h>
#include <GLFW/glfw3.h>
#include "Vec2.h"
#include "Vec3.h"
#include "Color.h"
#include <iostream>


class Drawable
{
protected:
	//Coordinates
	Vec2 pos;
	Vec2 scale;
	Color col;
public:
	void setPos(float x, float y);
	void setPos(Vec2 pos);
	void setScale(float x, float y);
	void setScale(Vec2 Scale);
	void setColor(float r, float g, float b, float a);
	void setColor(const Color& c);
	Drawable();
	~Drawable();
	virtual void Draw()=0;
};


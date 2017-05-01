#pragma once
#ifndef SDC_DRAWABLE_H
#define SDC_DRAWABLE_H


#include <stb_image.h>
#include <GLFW/glfw3.h>
#include "Vec2.h"
#include "Vec3.h"
#include "Color.h"
#include <iostream>



class Drawable
{
protected:
	Vec2 pos;//position and scale are in screenspace :[-1,1]
	Vec2 scale;
	Color col;
public:
	//Coordinates

	void setPos(float x, float y);
	void setPos(Vec2 pos);
	void setScale(float x, float y);
	void setScale(Vec2 Scale);
	void setColor(float r, float g, float b, float a);
	void setColor(const Color& c);

	Vec2 GetPos() { return pos; }

	static Vec2 PixelSpaceToScreenSpace(Vec2 v);
	static Vec2 ScreenSpaceToPixelSpace(Vec2 v);
	Drawable();
	Drawable(Vec2 Pos, Vec2 Scale, Color col);
	~Drawable();
	virtual void Draw()=0;

};
#endif // !SDC_DRAWABLE_H

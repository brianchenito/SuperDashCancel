#pragma once
#ifndef SDC_DRAWABLE_H
#define SDC_DRAWABLE_H


#include <stb_image.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include <iostream>



class Drawable
{
protected:
	glm::vec2 pos;//position and scale are in screenspace :[-1,1]
	glm::vec2 scale;
	glm::vec3 col;
public:
	//Coordinates

	void setPos(float x, float y);
	void setPos(glm::vec2 pos);
	void setScale(float x, float y);
	void setScale(glm::vec2 Scale);
	void setColor(float r, float g, float b, float a);
	void setColor(const glm::vec3 c);

	glm::vec2 GetPos() { return pos; }

	static glm::vec2 PixelSpaceToScreenSpace(glm::vec2 v);
	static glm::vec2 ScreenSpaceToPixelSpace(glm::vec2 v);
	Drawable();
	Drawable(glm::vec2 Pos, glm::vec2 Scale, glm::vec3 c);
	~Drawable();
	virtual void Draw()=0;

};
#endif // !SDC_DRAWABLE_H

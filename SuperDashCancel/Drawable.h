#pragma once
#ifndef SDC_DRAWABLE_H
#define SDC_DRAWABLE_H


#include <stb_image.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "presets.h"
#include <iostream>



class Drawable
{
	

public:
	static glm::mat4 projection;
	glm::vec2 pos;//position and scale are in pixel space
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

	Drawable();
	Drawable(glm::vec2 Pos, glm::vec2 Scale, glm::vec3 c);
	~Drawable();
	virtual void Draw()=0;

};
#endif // !SDC_DRAWABLE_H

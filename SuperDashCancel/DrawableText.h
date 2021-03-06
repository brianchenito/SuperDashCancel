#pragma once
#ifndef SDC_DRAWABLE_TEXT_H
#define SDC_DRAWABLE_TEXT_H
#include <string>
#include "FontEngine.h"
#include "Drawable.h"
class DrawableText :
	public Drawable
{
public:
	std::string text;
	float fontScale;
	FontEngine* f;

	DrawableText();
	DrawableText(FontEngine*f);
	DrawableText(FontEngine*f,std::string s, glm::vec2  Pos, float fontscale , glm::vec3 col);
	~DrawableText();
	void Draw();
};

#endif // !SDC_DRAWABLE_TEXT_H

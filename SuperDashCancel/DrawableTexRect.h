#pragma once
#ifndef SDC_DRAWABLE_TEX_RECT_H
#define SDC_DRAWABLE_TEX_RECT_H


#include "Drawable.h"
enum TEXLOADCONFIG {NOALPHA,ALPHA};
class DrawableTexRect : public Drawable
{
public:
	GLuint TexID;

	DrawableTexRect();
	~DrawableTexRect();
	DrawableTexRect(glm::vec2 Pos, glm::vec2 Scale, glm::vec3 Color);
	void loadTexture(const char* filename, TEXLOADCONFIG t);
	void Draw();

};
#endif // !SDC_DRAWABLE_TEX_RECT_H

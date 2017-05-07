#pragma once
#ifndef SDC_DRAWABLE_SPRITE_H
#define SDC_DRAWABLE_SPRITE_H

#include "Shader.h"
#include "Drawable.h"
enum TEXLOADCONFIG {NOALPHA,ALPHA};
class DrawableSprite : public Drawable
{
public:
	GLuint TexID;
	DrawableSprite();
	~DrawableSprite();
	DrawableSprite(glm::vec2 Pos, glm::vec2 Scale, glm::vec3 Color);
	void loadTexture(const char* filename, TEXLOADCONFIG t);
	void Draw();

};
#endif // !SDC_DRAWABLE_TEX_RECT_H

#pragma once
#include "Drawable.h"
class DrawableTexRect : public Drawable
{
public:
	GLuint TexID;

	DrawableTexRect();
	~DrawableTexRect();
	void loadTexture(const char* filename);
	void Draw();

};


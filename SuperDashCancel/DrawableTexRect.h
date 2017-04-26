#pragma once
#include "Drawable.h"
enum TEXLOADCONFIG {NOALPHA,ALPHA};
class DrawableTexRect : public Drawable
{
public:
	GLuint TexID;

	DrawableTexRect();
	~DrawableTexRect();
	void loadTexture(const char* filename, TEXLOADCONFIG t);
	void Draw();

};


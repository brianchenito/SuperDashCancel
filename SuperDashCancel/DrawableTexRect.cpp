#include "DrawableTexRect.h"


DrawableTexRect::DrawableTexRect()
{
}


DrawableTexRect::~DrawableTexRect()
{
	scale.x = 5;
	scale.y = 5;
}

void DrawableTexRect::loadTexture(const char * filename)
{
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	//glEnable(GL_DEPTH_TEST);
	//////

	int w;
	int h;
	int comp;
	unsigned char* image = stbi_load(filename, &w, &h, &comp, STBI_rgb);

	if (image == nullptr)
		throw "Failed to load texture";

	glGenTextures(1, &TexID);

	glBindTexture(GL_TEXTURE_2D, TexID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (comp == 3)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	else if (comp == 4)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(image);
}

void DrawableTexRect::Draw()
{
	glColor4f(col.getR(),col.getG(),col.getB(),col.getA());
	glBindTexture(GL_TEXTURE_2D, TexID);
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_COLOR_MATERIAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(pos.x, pos.y);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(pos.x+scale.x, pos.y);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(pos.x + scale.x, pos.y+scale.y);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(pos.x, pos.y + scale.y);

	glEnd();

	glDisable(GL_TEXTURE_2D);

}


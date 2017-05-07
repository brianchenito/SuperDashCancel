#include "DrawableSprite.h"


DrawableSprite::DrawableSprite()
{
}


DrawableSprite::~DrawableSprite()
{
	scale.x = 5;
	scale.y = 5;
}

DrawableSprite::DrawableSprite( glm::vec2 Pos, glm::vec2 Scale, glm::vec3 Color)
{

	this->pos=Pos;
	this->scale=Scale;
	this->col =Color;
}

void DrawableSprite::loadTexture(const char * filename, TEXLOADCONFIG t)
{
	glShadeModel(GL_FLAT);
	//glEnable(GL_DEPTH_TEST);

	int w;
	int h;
	int comp;
	unsigned char* image;
	if(t)image= stbi_load(filename, &w, &h, &comp, STBI_rgb_alpha);
	else image = stbi_load(filename, &w, &h, &comp, STBI_rgb);
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

void DrawableSprite::Draw()
{

	
	glColor3f(col.r,col.g,col.b);
	glBindTexture(GL_TEXTURE_2D, TexID);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0);
	glm::vec2 coords = projection*glm::vec4(pos.x,pos.y,0,1);
	glm::vec2 coords2 = projection*glm::vec4(pos.x+scale.x, pos.y+scale.y, 0, 1);

	std::cout << coords.x << " " << coords.y << "\n";
	glVertex2f(coords.x, coords.y);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(coords2.x, coords.y);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(coords2.x,coords2.y);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(coords.x, coords2.y);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	
}


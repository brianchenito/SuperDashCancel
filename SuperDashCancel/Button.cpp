#include "Button.h"



Button::Button()
{
}

Button::Button(Vec2 _pos, Vec2 _scale, const GLFWimage& defaultImage, const GLFWimage& selectedImage, void(*callback_func)() = 0) {
	pos = _pos;
	scale = _scale;
	im_default = &defaultImage;
	im_selected = &selectedImage;
	OnPress = callback_func;
}

void Button::SetTextAttr(string _text, Color _color, float _size) {
	text = _text;
	color = _color;
	size = _size;
}

Button::~Button()
{
}

void Button::AttachCallback(void(*callback_func)()) {
	OnPress = callback_func;
}

void Button::Draw() {
	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if(selected) glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, im_selected->width, im_selected->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, im_selected->pixels);
	else glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, im_default->width, im_default->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, im_default->pixels);

	glEnable(GL_TEXTURE_2D);
	glColor4b(color.r, color.g, color.b, color.a);
	glBegin(GL_QUADS);
	glBindTexture(GL_TEXTURE_2D, tex);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(pos.x, pos.y);
	glTexCoord2f(1.0f, 1.0f);	glVertex2f(pos.x + scale.x, pos.y);
	glTexCoord2f(1.0f, 0.0f);	glVertex2f(pos.x + scale.x, pos.y + scale.y);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(pos.x, pos.y + scale.y);
	glEnd();

}

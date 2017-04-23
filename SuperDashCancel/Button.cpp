#include "Button.h"



Button::Button()
{
}

Button::Button(Vec2 _pos, Vec2 _scale, GLuint _tex_id, GLuint _alt_tex_id, void(*callback_func)()) {
	pos = _pos;
	scale = _scale;
	tex_id = _tex_id;
	alt_tex_id = _alt_tex_id;
	OnPress = callback_func;
}

Button::~Button()
{
}

void Button::AttachCallback(void(*callback_func)()) {
	OnPress = callback_func;
}

void Button::AttachNeighbors(const Button* above, const Button* below, const Button* left, const Button* right) {
	Above = above;
	Below = below;
	Left = left;
	Right = right;
}

void Button::SetTextAttr(string _text, Color _color, float _size) {
	text = _text;
	color = _color;
	size = _size;
}

void Button::Draw() {

	glEnable(GL_TEXTURE_2D);
	glColor4b(color.r, color.g, color.b, color.a);
	glBegin(GL_QUADS);

	if (selected) glBindTexture(GL_TEXTURE_2D, alt_tex_id);
	else glBindTexture(GL_TEXTURE_2D, tex_id);
	
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(pos.x, pos.y);
	glTexCoord2f(1.0f, 1.0f);	glVertex2f(pos.x + scale.x, pos.y);
	glTexCoord2f(1.0f, 0.0f);	glVertex2f(pos.x + scale.x, pos.y + scale.y);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(pos.x, pos.y + scale.y);
	glEnd();

}

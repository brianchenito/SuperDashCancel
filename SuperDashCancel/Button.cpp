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
	
}

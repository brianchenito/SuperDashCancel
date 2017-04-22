#pragma once

#include <string>
#include "Drawable.h"

class Button : public Drawable
{ public:
	//Coordinates
	Vec2 pos;
	Vec2 scale;
	
	//Text attributes
	string text;
	Color color;
	float size;

	//Pointers to adjacent buttons
	Button* Above;
	Button* Below;
	Button* Left;
	Button* Right;

	//Background images
	const GLFWimage* im_default;
	const GLFWimage* im_selected;
	bool selected;

	//OnPress delegate
	void(*OnPress)() = 0;

	void AttachCallback(void(*callback_func)());
	void SetTextAttr(string _text, Color _color, float _size);
	void Draw();

	Button();
	Button(Vec2 _pos, Vec2 _scale, const GLFWimage& defaultImage, const GLFWimage& selectedImage, void(*callback_func)() = 0);
	~Button();
};


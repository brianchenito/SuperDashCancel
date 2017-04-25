#pragma once

#include <string>
#include "Drawable.h"

class Button : public Drawable
{ public:

	
	//Text attributes
	std::string text;
	Color color;
	float size;

	//Pointers to adjacent buttons
	const Button* Above;
	const Button* Below;
	const Button* Left;
	const Button* Right;

	//Background images
	GLuint tex_id;
	GLuint alt_tex_id;
	bool selected;

	//OnPress delegate
	void(*OnPress)() = 0;

	void AttachCallback(void(*callback_func)());
	void AttachNeighbors(const Button* above = 0, const Button* below = 0, const Button* left = 0, const Button* right = 0);
	void SetTextAttr(std::string _text, Color _color, float _size);
	void Draw();

	Button();
	Button(Vec2 _pos, Vec2 _scale, GLuint _tex_id, GLuint _alt_tex_id, void(*callback_func)() = 0);
	~Button();
};


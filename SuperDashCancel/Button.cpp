#include "Button.h"


Button::Button()
{
}

Button::Button(FontEngine * f):DrawableText(f)
{
}

Button::Button(FontEngine * f, std::string s, glm::vec2 Pos, float fontscale, glm::vec3 col):DrawableText(f,s, Pos, fontscale,col)
{
	
}

Button::~Button()
{
}

void Button::AttachNeighbors( Button* above,  Button* below,  Button* left,  Button* right) {
	Above = above;
	Below = below;
	Left = left;
	Right = right;
}

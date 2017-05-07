#include "DrawableText.h"


DrawableText::DrawableText()
{
}

DrawableText::DrawableText(FontEngine*f)
{
	this->f = f;
}

DrawableText::DrawableText(FontEngine*f,std::string s, glm::vec2 Pos, float fontscale, glm::vec3 col):Drawable(Pos,glm::vec2(0,0),col)
{
	this->f = f;
	this->text = s;
	this->fontScale = fontscale;
}


DrawableText::~DrawableText()
{
}

void DrawableText::Draw()
{
	f->RenderText(text, pos.x, pos.y, fontScale, glm::vec3(col.r, col.g, col.b));
}

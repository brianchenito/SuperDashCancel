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
	glm::vec2 coords = Drawable::ScreenSpaceToPixelSpace(pos);
	f->RenderText(text, coords.x, coords.y, fontScale, glm::vec3(col.r, col.g, col.b));
}

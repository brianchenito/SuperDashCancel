#include "Color.h"



Color::Color()
{
}

Color::Color(const Color & copy)
{
	r = copy.r;
	g = copy.g;
	b = copy.b;
	a = copy.a;
}

Color::Color(float _r, float _b, float _g, float _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}





Color::~Color()
{
}

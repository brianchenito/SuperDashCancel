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

Color::Color(GLbyte _r, GLbyte _b, GLbyte _g, GLbyte _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}


Color::~Color()
{
}

#include "Color.h"



Color::Color()
{
}

Color::Color(const Color & copy)
{
	r = copy.r;
	g = copy.g;
	b = copy.b;
}

Color::Color(unsigned char _r, unsigned char _b, unsigned char _g)
{
	r = _r;
	g = _g;
	b = _b;
}


Color::~Color()
{
}

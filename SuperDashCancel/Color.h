#pragma once
class Color
{
public:
	unsigned char r, b, g;

	Color();
	Color(const Color& copy);
	Color(unsigned char _r, unsigned char _b, unsigned char _g);
	~Color();
};


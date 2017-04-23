#pragma once
#include <GLFW/glfw3.h>
class Color
{
public:
	GLbyte r, b, g, a;

	Color();
	Color(const Color& copy);
	Color(GLbyte _r, GLbyte _b, GLbyte _g, GLbyte _a);
	~Color();
};


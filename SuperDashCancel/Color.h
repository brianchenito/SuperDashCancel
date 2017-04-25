#pragma once
#include <GLFW/glfw3.h>
struct Color
{
	GLbyte r, g, b, a;

	Color();
	Color(const Color& copy);
	Color(GLbyte _r, GLbyte _g, GLbyte _b, GLbyte _a);
	Color(int _r, int _g, int _b, int _a);
	~Color();
};


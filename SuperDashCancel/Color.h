#pragma once
#include <GLFW/glfw3.h>
struct Color
{
	float r, g, b, a;

	Color();
	Color(const Color& copy);
	Color(float _r, float _g, float _b, float _a);
	Color operator*(const float& f);
	~Color();
};


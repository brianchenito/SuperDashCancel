#pragma once
#include <GLFW/glfw3.h>
struct Color
{
	float r, g, b, a;

	Color();
	Color(const Color& copy);
	Color(float _r, float _g, float _b, float _a);
	const float& getR() { return r; }
	const float& getG() { return g; }
	const float& getB() { return b; }
	const float& getA() { return a; }
	~Color();
};


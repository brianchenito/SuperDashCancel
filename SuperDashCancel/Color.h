#pragma once
#ifndef SDC_COLOR_H
#define	SDC_COLOR_H


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

#endif // !SDC_COLOR_H
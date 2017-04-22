#include "Vec2.h"



Vec2::Vec2()
{
}

Vec2::Vec2(const Vec2 & copy)
{
	x = copy.x;
	y = copy.y;
}

Vec2::Vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}


Vec2::~Vec2()
{
}

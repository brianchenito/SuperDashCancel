#include "Vec3.h"



Vec3::Vec3()
{
}

Vec3::Vec3(const Vec3 & copy)
{
	x = copy.x;
	y = copy.y;
	z = copy.z;
}

Vec3::Vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}


Vec3::~Vec3()
{
}

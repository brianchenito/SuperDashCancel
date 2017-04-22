#pragma once
class Vec3
{
public:
	float x, y, z;

	Vec3();
	Vec3(const Vec3& copy);
	Vec3(float _x, float _y, float _z);
	~Vec3();
};


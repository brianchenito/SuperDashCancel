#pragma once
#ifndef SDC_VEC3_H
#define SDC_VEC3_H


#include <math.h>

struct Vec3
{

	float x, y, z;

	Vec3();
	Vec3(const Vec3& copy);
	Vec3(float _x, float _y, float _z);
	~Vec3();

	Vec3 operator+(const Vec3& v) {
		return Vec3(x + v.x, y + v.y, z + v.z);
	}

	Vec3 operator-(const Vec3& v) {
		return Vec3(x - v.x, y - v.y, z - v.z);
	}

	float operator*(const Vec3& v) {
		return x*v.x + y*v.y + z*v.z;
	}

	Vec3 operator*(float f) {
		return Vec3(x*f, y*f, z*f);
	}

	Vec3 operator/(float f) {
		return Vec3(x/f, y/f, z/f);
	}

	Vec3 cross(const Vec3& v) {
		return Vec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.z);
	}

	float norm() {
		return sqrtf(x*x + y*y + z*z);
	}
};

#endif // !SDC_VEC3_H
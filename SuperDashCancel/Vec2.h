#pragma once
#include <math.h>

struct Vec2
{
	float x, y;

	Vec2();
	Vec2(const Vec2& copy);
	Vec2(float _x, float _y);
	~Vec2();

	Vec2 operator+(const Vec2& v) {
		return Vec2(x + v.x, y + v.y);
	}

	Vec2 operator-(const Vec2& v) {
		return Vec2(x - v.x, y - v.y);
	}

	float operator*(const Vec2& v) {
		return x*v.x + y*v.y;
	}

	Vec2 operator*(float f) {
		return Vec2(x*f, y*f);
	}

	Vec2 operator/(float f) {
		return Vec2(x / f, y / f);
	}

	Vec2 perp(const Vec2& v) {
		return Vec2(-y, x);
	}

	float norm() {
		return sqrtf(x*x + y*y);
	}
};


#pragma once
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include "Vec2.h"
#include "Vec3.h"
#include "Color.h"

using namespace std;

class Drawable
{
public:
	Drawable();
	~Drawable();
	virtual void Draw();
};


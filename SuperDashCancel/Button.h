#pragma once
#ifndef SDC_BUTTON_H
#define SDC_BUTTON_H


#include <string>
#include "DrawableText.h"
class Button : public DrawableText
{ 

public:

	//Pointers to adjacent buttons
	 Button* Above;
	 Button* Below;
	 Button* Left;
	 Button* Right;
	
	glm::vec3 altCol;
	virtual void Activate()=0;// callbacks dont work for our use case, needs to be nonstatic
	void AttachNeighbors( Button* above = 0,  Button* below = 0,  Button* left = 0,  Button* right = 0);

	Button();
	Button(FontEngine*f);
	
	Button(FontEngine*f, std::string s, glm::vec2  Pos, float fontscale, glm::vec3 col);

	~Button();
	
};

#endif // !SDC_BUTTON_H
#include "DrawableSpriteSheet.h"



void DrawableSpriteSheet::Reset()
{
	indexh = 0;
	indexw = 0;
	by2 = false;

}

DrawableSpriteSheet::DrawableSpriteSheet()
{
}

DrawableSpriteSheet::DrawableSpriteSheet(glm::vec2 Pos, glm::vec2 Scale, glm::vec3 Color, int horiz, int vert):DrawableSprite(Pos,Scale,Color)
{
	h = vert;
	w = horiz;
	by2 = false;
	indexh = h;
}


DrawableSpriteSheet::~DrawableSpriteSheet()
{
}

void DrawableSpriteSheet::Draw()
{

	if (indexh < h) 
	{
		//std::cout << "Drawing " << indexw << " " << indexh << "\n";
		glColor3f(col.r, col.g, col.b);
		glBindTexture(GL_TEXTURE_2D, TexID);
		glEnable(GL_TEXTURE_2D);
		glm::vec2 coords = projection*glm::vec4(pos.x+(leftOrigin?-scale.x/2: scale.x/2), pos.y-scale.y/2, 0, 1);
		glm::vec2 coords2 = projection*glm::vec4(pos.x + (leftOrigin ? scale.x/2 : -scale.x/2), pos.y + scale.y/2, 0, 1);
		glBegin(GL_QUADS);
		

		glTexCoord2f((float)indexw/w, (float)(indexh+1)/h);
		glVertex2f(coords.x, coords.y);

		glTexCoord2f((float)(indexw +1)/ w, (float)(indexh + 1) / h);

		glVertex2f(coords2.x, coords.y);

		glTexCoord2f((float)(indexw + 1) / w, (float)(indexh ) / h);

		glVertex2f(coords2.x, coords2.y);

		glTexCoord2f((float)(indexw) / w, (float)(indexh) / h);
		glVertex2f(coords.x, coords2.y);

		glEnd();

		glDisable(GL_TEXTURE_2D);

	}
	
}

void DrawableSpriteSheet::FixedStep()
{
	by2 = !by2;
	if (by2)
	{
		indexw++;
		if (indexw == w)
		{
			indexh++;
			indexw = 0;
		}
		//if (indexh == h)Reset();
	}
}

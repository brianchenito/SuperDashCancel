#pragma once
#ifndef SDC_FONT_ENGINE_H
#define SDC_FONT_ENGINE_H


#include <ft2build.h>
#include "glm/ext.hpp"
#include "glm/glm.hpp"
#include FT_FREETYPE_H
#include <map>
#include "Shader.h"
struct Character {
	GLuint     TextureID;  // ID handle of the glyph texture
	glm::ivec2 Size;       // Size of glyph
	glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
	GLuint     Advance;    // Offset to advance to next glyph
};
class FontEngine
{
private:

	FT_Library library;
	FT_Face face;
	FT_Error ft_err;
	const char face_path[39] = "../SuperDashCancel/fonts/CODE_Bold.otf";
	std::map<GLchar, Character> Characters;
	Shader* shader;
	GLuint VAO, VBO; //vertex buffs for text rendering
	glm::mat4 projection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f);

public:




	FontEngine();
	void init();
	void RenderText( std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
	~FontEngine();
};

#endif // !SDC_FONT_ENGINE_H
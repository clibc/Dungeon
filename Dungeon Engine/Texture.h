#pragma once
#include <iostream>
#include "GL/glew.h"
#include "stb_image.h"

class Texture
{
public:
	Texture(char* const imagePath);
	~Texture();
private:
	GLuint _texture;
};


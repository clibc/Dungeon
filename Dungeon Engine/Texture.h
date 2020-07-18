#pragma once
#include "Renderer.h"
#include "stb_image.h"

class Texture
{
public:
	Texture(char* const imagePath);
	~Texture();
private:
	GLuint _texture;
};


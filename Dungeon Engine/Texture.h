#pragma once
#include "Renderer.h"
#include "stb_image.h"

class Texture
{
public:
	Texture(char* const imagePath);
	void Bind(unsigned int slot = 0) const;
	inline int GetWidth() const { return _width; }
	inline int GetHeight() const { return _height; }

	~Texture();
private:
	GLuint _texture;
	int _width;
	int _height;
	int _channels;
};


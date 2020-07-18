#include "Texture.h"

Texture::Texture(char* const imagePath)
{

	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);

	int width, height, channels;
	stbi_set_flip_vertically_on_load(true); // Texture is upside down without this
	unsigned char* data = stbi_load(imagePath, &width, &height, &channels, 0);

	if (!data)
	{
		std::cout << "Unable to load texture" << "\n";
		stbi_image_free(data);
		return;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	

	stbi_image_free(data);

	std::cout << "texture generated" << "\n";
}

Texture::~Texture()
{
	glDeleteTextures(1, &_texture);
}

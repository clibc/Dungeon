#include "Texture.h"

Texture::Texture(char* const imagePath)
{

	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);

	stbi_set_flip_vertically_on_load(true); // Texture is upside down without this
	unsigned char* data = stbi_load(imagePath, &_width, &_height, &_channels, 0);

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

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	

	stbi_image_free(data);

	DG_ENGINE_INFO("Texture Generated");
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, _texture);	
}

Texture::~Texture()
{
	glDeleteTextures(1, &_texture);
}

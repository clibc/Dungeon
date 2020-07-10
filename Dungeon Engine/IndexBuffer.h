#pragma once
#include <cstdint>
#include "GL/glew.h"

class IndexBuffer
{
public:
	IndexBuffer(unsigned int* indicies, uint32_t count);
	~IndexBuffer();

	void Bind();
	void Unbind();

private:
	uint32_t _count;
	GLuint _bufferID;
};


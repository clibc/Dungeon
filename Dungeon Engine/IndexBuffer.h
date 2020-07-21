#pragma once
#include <cstdint>
#include "GL/glew.h"

class IndexBuffer
{
public:
	IndexBuffer(unsigned int* indicies, uint32_t count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
	uint32_t GetCount() const { return _count; }

private:
	uint32_t _count;
	GLuint _bufferID;
};


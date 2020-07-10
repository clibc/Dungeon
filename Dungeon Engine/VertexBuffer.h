#pragma once
#include "GL/glew.h"
#include <cstdint>

class VertexBuffer
{
public:	
	VertexBuffer(float * vertices, uint32_t	size);
	~VertexBuffer();
	void Bind();
	void Unbind();

private:
	GLuint _bufferID;

};


#pragma once
#include "Renderer.h"
#include <cstdint>


class VertexBuffer
{
public:	
	VertexBuffer(float * vertices, uint32_t	size);
	~VertexBuffer();
	void SetVertexAttribArray(GLuint index, GLint size, size_t stride, const GLvoid* pointer);
	void Bind();
	void Unbind();

private:
	GLuint _bufferID;

};


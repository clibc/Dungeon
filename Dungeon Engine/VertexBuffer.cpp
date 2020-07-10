#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(float* vertices, uint32_t size)
{
	glCreateBuffers(1, &_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &_bufferID);
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
}

void VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

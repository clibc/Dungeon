#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(unsigned int* indicies, uint32_t count)
	:_count(count)
{
	glGenBuffers(1, &_bufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count * sizeof(unsigned int), indicies, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &_bufferID);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

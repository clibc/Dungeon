#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(float* vertices, uint32_t size)
	:_vertexCount((size / sizeof(float))/3)
{
	glCreateBuffers(1, &_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0)
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &_bufferID);
}

void VertexBuffer::SetVertexAttribArray(GLuint index, GLint size, size_t stride, const GLvoid* pointer)
{
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
	glEnableVertexAttribArray(index);
	DG_ENGINE_INFO("VertexAtrrib Setted");
}

void VertexBuffer::SetIndexBuffer(const IndexBuffer& ib)
{
	glBindVertexArray(_bufferID);
	ib.Bind();
	_indexBuffer = &ib;
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
}

void VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

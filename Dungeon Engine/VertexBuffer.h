#pragma once
#include "IndexBuffer.h"
#include <iostream>
#include <cstdint>


class VertexBuffer
{
public:	
	VertexBuffer(float * vertices, uint32_t	size);
	~VertexBuffer();
	void SetVertexAttribArray(GLuint index, GLint size, size_t stride, const GLvoid* pointer);
	void SetIndexBuffer(const IndexBuffer& ib);
	inline uint32_t GetVertexCount() const { return _vertexCount; }
	void Bind() const;
	void Unbind();

private:
	GLuint _bufferID;
	unsigned int _vertexCount;
public:
	const IndexBuffer* _indexBuffer;

};


#pragma once
#include <vector>
#include <iostream>
#include "GL/glew.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"
#include "Shader.h"
#include "VertexBuffer.h"
#include "Log.h"


#define LOG(x) std::cout << x << "\n";

class Renderer
{
public:
	Renderer();
	void SetClearColor(const glm::vec4& color);
	void Clear();
	void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
	void Draw(const Shader& shader, const VertexBuffer& vertexBuffer);
	void DrawVertices(const Shader& shader, const VertexBuffer& vertexBuffer);
};


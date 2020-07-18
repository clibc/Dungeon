#pragma once
#include "GL/glew.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"
#include <iostream>
#include <vector>

#define LOG(x) std::cout << x << "\n";

class Renderer
{
public:
	void SetClearColor(const glm::vec4& color);
	void Clear();
	void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
	void Draw(unsigned int count);
};


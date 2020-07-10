#pragma once
#include <GL\glew.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Shader
{
public:

	Shader(const char* vertexShader, const char* fragmentShader);
	void Bind();
	~Shader();

private:
	GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
	GLuint _program;
};


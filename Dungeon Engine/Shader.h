#pragma once
#include "GL/glew.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Log.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

struct ShaderPaths
{
	ShaderPaths(const char* vs, const char* fs)
		:vertexPath(vs), fragmentPath(fs)
	{}

	const char* vertexPath;
	const char* fragmentPath;

};

class Shader
{
public:	
	Shader(ShaderPaths sp);
	~Shader();
	void Bind() const;
	GLuint LoadShaders(const char* vs, const char* fs);
	void SetUniform1f(const std::string& name, glm::float32 value);
	void SetUniform2f(const std::string& name, glm::vec2 value);
	void SetUniform3f(const std::string& name, glm::vec3 value);
	void SetUniform4f(const std::string& name, glm::vec4 value);
	void SetUniformMat4(const std::string& name, const glm::mat4& value);
private:
	GLuint _programID;
};


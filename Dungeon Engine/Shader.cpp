#include "Shader.h"


Shader::Shader(ShaderPaths sp)
{
	_programID = LoadShaders(sp.vertexPath , sp.fragmentPath);
}

Shader::~Shader()
{
	glDeleteProgram(_programID);
}

void Shader::Bind() const
{
	glUseProgram(_programID);
}


GLuint Shader::LoadShaders(const char* vs, const char* fs)
{
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vs, std::ios::in);
	if (VertexShaderStream.is_open())
	{
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		VertexShaderCode = sstr.str();
		VertexShaderStream.close();
	}
	else
	{
		DG_ENGINE_ERROR("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !");
		getchar();
		return 0;
	}

	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fs, std::ios::in);
	if (FragmentShaderStream.is_open())
	{
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	DG_ENGINE_TRACE("Compiling shader : {0}",vs);
	char const* VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		DG_ENGINE_ERROR("{0}", &VertexShaderErrorMessage[0]);
	}

	DG_ENGINE_TRACE("Compiling shader : {0}", fs);
	char const* FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		DG_ENGINE_ERROR("{0}", &FragmentShaderErrorMessage[0]);
	}

	DG_ENGINE_TRACE("Linking program");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		DG_ENGINE_ERROR("{0}", &ProgramErrorMessage[0]);
	}

	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}

void Shader::SetUniform1f(const std::string& name, glm::float32 value)
{
	glUseProgram(_programID);
	GLuint loc = glGetUniformLocation(_programID, name.c_str());
	glUniform1f(loc, value);
}

void Shader::SetUniform2f(const std::string& name, glm::vec2 value)
{
	glUseProgram(_programID);
	GLuint loc = glGetUniformLocation(_programID, name.c_str());
	glUniform2f(loc, value.x, value.y);
}

void Shader::SetUniform3f(const std::string& name, glm::vec3 value)
{
	glUseProgram(_programID);
	GLuint loc = glGetUniformLocation(_programID, name.c_str());
	glUniform3f(loc, value.x, value.y, value.z);

}

void Shader::SetUniform4f(const std::string& name, glm::vec4 value)
{
	glUseProgram(_programID);
	GLuint loc = glGetUniformLocation(_programID, name.c_str());
	glUniform4f(loc, value.x, value.y, value.z, value.w);
}

void Shader::SetUniformMat4(const std::string& name, const glm::mat4& value)
{
	glUseProgram(_programID);
	GLuint loc = glGetUniformLocation(_programID, name.c_str());
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

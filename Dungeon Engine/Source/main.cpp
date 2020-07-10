#include "../Window.h"
#include "../Source/LoadShader.hpp"
#include "../VertexBuffer.h"
#include "../IndexBuffer.h"
#include "../Shader.h"

void main()
{
	Window w(800, 600, "Dungeon");

	static GLfloat g_vertex_buffer_data[] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.0f,  0.5f,
		-1.0f ,0.5
	};

	static GLuint g_index_buffer_data[] = {
		0,1,2,0,3,2
	};

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create VBO and pass it to OpenGL
	VertexBuffer vb(g_vertex_buffer_data , sizeof(g_vertex_buffer_data));
	IndexBuffer ib(g_index_buffer_data, sizeof(g_index_buffer_data) / sizeof(GLuint));

	vb.Bind();


	
	Shader sh("./Shaders/vertexShader.glsl", "./Shaders/fragmentShader.glsl");

	while (glfwGetKey(w.GetWindowInstance(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(w.GetWindowInstance()) == 0)
	{
		w.Clear();
		sh.Bind();


		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		//glDrawArrays(GL_TRIANGLES, 0, 4);
		w.Update();
	}
}
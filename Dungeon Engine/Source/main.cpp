#include "Window.h"
#include "Source/LoadShader.hpp"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"

void main()
{

	Window w(800, 600, "Dungeon");
	Renderer renderer;
	glm::vec4 clearColor = { 0.0f, 0.0f, 0.0f, 1.0f };

	renderer.SetClearColor(clearColor);
	static GLfloat g_vertex_buffer_data[] = {
		// positions          // colors           // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
	   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	static GLuint g_index_buffer_data[] = {
		0,1,2,0,3,2
	};


	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create VBO and pass it to OpenGL
	VertexBuffer vb(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	IndexBuffer ib(g_index_buffer_data, sizeof(g_index_buffer_data) / sizeof(GLuint));
	Texture tex((char*)"Source/wall.jpg");
	ShaderPaths shaderPaths("Shaders/vertexShader.glsl", "Shaders/fragmentShader.glsl"); // This path is for shader.h not for main.

	Shader shader(shaderPaths);

	vb.Bind();


	glm::vec3 colors = { 0.5,0.6,0 };

	vb.SetVertexAttribArray(0, 3, 8 * sizeof(float), 0);
	vb.SetVertexAttribArray(1, 2, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	shader.Bind();

	while (glfwGetKey(w.GetWindowInstance(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(w.GetWindowInstance()) == 0)
	{
		renderer.Clear();
		shader.SetUniform3f("u_Color", colors); //Required to be called every draw call!

		renderer.Draw(6);

		w.Update();
	}
}
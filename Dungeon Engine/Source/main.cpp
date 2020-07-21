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

	vb.SetIndexBuffer(ib);

	//Set Matrices
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(120.0f), glm::vec3(1.0f, 0.0f, 0.0f)); //Rotate
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	shader.SetUniformMat4("model", model);
	shader.SetUniformMat4("view", view);
	shader.SetUniformMat4("projection", projection);

	vb.SetVertexAttribArray(0, 3, 8 * sizeof(float), 0);
	vb.SetVertexAttribArray(1, 2, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	while (glfwGetKey(w.GetWindowInstance(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(w.GetWindowInstance()) == 0)
	{
		renderer.Clear();

		renderer.Draw(shader, vb);


		w.Update();
	}
}
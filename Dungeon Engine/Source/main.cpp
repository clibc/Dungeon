#include "Window.h"
#include "Source/LoadShader.hpp"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"

void main()
{

	Window w(800, 600, "Dungeon Engine");
	Renderer renderer;

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	renderer.SetClearColor(glm::vec4(0.4f, 0.5f, 1.0f, 1.0f));
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
	VertexBuffer vb(vertices, sizeof(vertices));
	//IndexBuffer ib(g_index_buffer_data, sizeof(g_index_buffer_data) / sizeof(GLuint));
	Texture tex((char*)"Source/wall.jpg");
	ShaderPaths shaderPaths("Shaders/vertexShader.glsl", "Shaders/fragmentShader.glsl"); // This path is for shader.h not for main.

	Shader shader(shaderPaths);

	//vb.SetIndexBuffer(ib);
	tex.Bind();

	//Set Matrices
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-50.0f), glm::vec3(1.0f, 1.0f, 0.0f)); //Rotate
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	shader.SetUniformMat4("model", model);
	shader.SetUniformMat4("view", view);
	shader.SetUniformMat4("projection", projection);

	vb.SetVertexAttribArray(0, 3, 5 * sizeof(float), 0); //Vertex positions 
	vb.SetVertexAttribArray(1, 2, 5 * sizeof(float), (void*)(3 * sizeof(float))); // Texture position

	while (glfwGetKey(w.GetWindowInstance(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(w.GetWindowInstance()) == 0)
	{
		renderer.Clear();

		renderer.DrawVertices(shader, vb);

		if (w.GetKeyPressed(GLFW_KEY_R))
			DG_ENGINE_INFO("Key Pressed : {}" ,GLFW_KEY_R);

		model = glm::rotate(model, glm::radians(-1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
		shader.SetUniformMat4("model", model);
		w.Update();
	}
}
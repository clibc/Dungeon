#include "Window.h"
#include "Source/LoadShader.hpp"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"
#include "Gui.h"


void main()
{

	Window w(1000, 800, "Dungeon Engine");
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
	Texture tex((char*)"../Dungeon Engine/Source/wood.jpg");
	ShaderPaths shaderPaths("../Dungeon Engine/Shaders/vertexShader.glsl", "../Dungeon Engine/Shaders/fragmentShader.glsl"); // This path is for shader.h not for main.
	Shader shader(shaderPaths);

	//vb.SetIndexBuffer(ib);
	tex.Bind();

	//Set transform
	glm::vec3 rotation = glm::vec3(1.0f);
	glm::vec3 transformation = glm::vec3(0.0f);
	glm::vec3 scale = glm::vec3(1.0f);

	//Set Matrices
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	model = glm::translate(model, transformation);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	shader.SetUniformMat4("model", model);
	shader.SetUniformMat4("view", view);
	shader.SetUniformMat4("projection", projection);

	vb.SetVertexAttribArray(0, 3, 5 * sizeof(float), 0); //Vertex positions 
	vb.SetVertexAttribArray(1, 2, 5 * sizeof(float), (void*)(3 * sizeof(float))); // Texture position

	// ImGui stuff
	Gui gui(w.GetWindowInstance(), true);
	GuiObjectWindow objectWindow("Cube",transformation);
	GuiEnviromentWindow envWindow;
	gui.GuiAddWindow(&objectWindow);
	gui.GuiAddWindow(&envWindow);


	while (glfwGetKey(w.GetWindowInstance(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(w.GetWindowInstance()) == 0)
	{

		renderer.Clear();
		
		shader.SetUniformMat4("model", glm::translate(glm::mat4(1.0f), transformation));
		renderer.DrawVertices(shader, vb);
		gui.Update();
		w.Update();

	}
}
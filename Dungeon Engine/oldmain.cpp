//#include <iostream>
//#include <GL\glew.h>
//#include <GLFW/glfw3.h>
//#include "./Source/LoadShader.hpp"
//
//int mainOld(void)
//{
//	if (!glfwInit())
//	{
//		std::cout << "Init failed !" << "\n";
//		return 1;
//	}
//
//	glfwWindowHint(GLFW_SAMPLES, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window;
//	window = glfwCreateWindow(800, 600, "Dungeon Engine", NULL, NULL);
//
//
//	if (window == NULL)
//	{
//		std::cout << stderr << " Failed to open Window" << "\n";
//		glfwTerminate();
//		return 1;
//	}
//
//	glfwMakeContextCurrent(window);
//
//	if (glewInit() != GLEW_OK)
//	{
//		std::cout << "Failed to init glew" << "\n";
//		return 1;
//	}
//
//	// Create VAO
//	GLuint VertexArrayID;
//	glGenVertexArrays(1, &VertexArrayID);
//	glBindVertexArray(VertexArrayID);
//	//
//
//
//
//	//Triangle
//	static const GLfloat g_vertex_buffer_data[] = {
//		-0.9f, -0.5f, 0.0f,
//		0.5f, -0.5f, 0.0f,
//		0.0f,  0.5f, 0.0f,
//	};
//
//	static const GLfloat g_vertex_buffer_data2[] = {
//		-0.5f, -0.5f, 0.0f,
//		0.5f, -0.5f, 0.0f,
//		0.0f,  0.5f, 0.0f,
//	};
//
//
//	// Create VBO and pass it to OpenGL
//	GLuint VertexBuffer;
//	glGenBuffers(1, &VertexBuffer);
//	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//	//
//
//	GLuint VertexBuffer2;
//	glGenBuffers(1, &VertexBuffer2);
//
//
//	GLuint shaderID = LoadShaders("./Shaders/vertexShader.glsl", "./Shaders/fragmentShader.glsl");
//
//	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0)
//	{
//
//		glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
//
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glUseProgram(shaderID);
//
//		//Draw
//		glEnableVertexAttribArray(0);
//		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
//		glVertexAttribPointer(
//			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
//			3,                  // size
//			GL_FLOAT,           // type
//			GL_FALSE,           // normalized?
//			0,                  // stride
//			(void*)0            // array buffer offset
//		);
//		// Draw the triangle !
//		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
//		glDisableVertexAttribArray(0);
//
//		//
//
//
//		glfwSwapBuffers(window);
//
//		glfwPollEvents();
//	}
//}
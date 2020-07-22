#pragma once
#include "Renderer.h"

#define MAX_KEYS 1024

class Window
{
public:
	Window(int width, int height, const char* title);
	~Window();

	GLFWwindow* GetWindowInstance() const;

	void Init();
	void Update();
	bool GetKeyPressed(int keycode);
	glm::vec2 GetMousePos();

	
private:
	GLFWwindow* _window;
	const char* _title;
	unsigned int _width;
	unsigned int _height;

	static bool _Keys[MAX_KEYS];

	double _mouseY;
	double _mouseX;

	static void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int m);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};


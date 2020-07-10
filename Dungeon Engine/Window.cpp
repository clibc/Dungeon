#include "Window.h"

#define LOG(x) std::cout << x << "\n"; 

Window::Window(int width, int height, const char* title)
{
	_width = width;
	_height = height;
	_title = title;
	Init();
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Init()
{
	if (glfwInit() != GLFW_TRUE)
	{
		std::cout << "glfwInit() Failed" << "\n";
		glfwTerminate();
		return;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);

	if (_window == NULL)
	{
		std::cout << stderr << " Failed to open Window" << "\n";
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(_window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << stderr << "glewInin() failed!" << "\n";
		glfwTerminate();
		return;
	}
	LOG("OpenGL version : " << glGetString(GL_VERSION))
	glfwSetKeyCallback(_window, keyboard_callback);
	
}

void Window::Clear()
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Update()
{
	glfwSwapBuffers(_window);
	glfwPollEvents();
}

GLFWwindow* Window::GetWindowInstance()
{
	return _window;
}

Vector2* Window::GetMousePos()
{
	glfwGetCursorPos(_window, &_mouseX, &_mouseY);
	Vector2 pos(_mouseX, _mouseY);

	return &pos;
}

void Window::keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int m)
{
	if (key == GLFW_KEY_E && action == GLFW_REPEAT | GLFW_PRESS)
		std::cout << "E pressed" << "\n";
}

//void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	Window* winl = (Window*)glfwGetWindowUserPointer(window);
//	winl->_mouseX = xpos;
//	winl->_mouseY = ypos;
//}
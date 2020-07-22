#include "Window.h"

#define LOG(x) std::cout << x << "\n"; 

bool Window::_Keys[MAX_KEYS];

Window::Window(int width, int height, const char* title)
{
	_width = width;
	_height = height;
	_title = title;
	Init();

	for (unsigned int i=0; i < MAX_KEYS; i++)
	{
		Window::_Keys[i] = false;
	}
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
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << stderr << "glewInin() failed!" << "\n";
		glfwTerminate();
		return;
	}
	LOG("OpenGL version : " << glGetString(GL_VERSION))
	glfwSetKeyCallback(_window, keyboard_callback);
	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

}

void Window::Update()
{
	glfwSwapBuffers(_window);
	glfwPollEvents();
}

bool Window::GetKeyPressed(int keycode)
{
	return Window::_Keys[keycode];
}

GLFWwindow* Window::GetWindowInstance() const
{
	return _window;
}

glm::vec2 Window::GetMousePos()
{
	glfwGetCursorPos(_window, &_mouseX, &_mouseY);
	glm::vec2 pos(_mouseX, _mouseY);
	return pos;
}

void Window::keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int m)
{
	if (action == GLFW_PRESS)
		Window::_Keys[key] = true;
	else if (action == GLFW_RELEASE)
		Window::_Keys[key] = false;
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


#pragma once

#include "Renderer.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

class MyGuiWindow
{
public:
	virtual void Update() = 0;

};


class GuiObjectWindow : public MyGuiWindow
{
public:
	GuiObjectWindow(const char* name ,glm::vec3& coords)
		:_name(name), _coords(coords)
 	{}

	virtual void Update() override
	{
		ImGui::Begin("Object");
		ImGui::Text(_name);
		ImGui::DragFloat3("Position", (float*)&_coords);
		ImGui::End();
	}

private:
	const char* _name;
	glm::vec3& _coords;
};


class GuiEnviromentWindow : public MyGuiWindow
{
public:
	GuiEnviromentWindow(glm::vec4& color)
		:_color(color)
	{
	}

	virtual void Update() override
	{
		ImGui::Begin("Environment");
		ImGui::DragFloat4("Color", (float*)&_color);
		ImGui::End();
	}

private:
	glm::vec4& _color;
};


class Gui
{
public:
	Gui() = default;
	Gui(GLFWwindow* window, bool install_callbacks);
	void GuiAddWindow(MyGuiWindow* window);
	void GuiRemoveWindow(MyGuiWindow* window);

	void Update() const;

private:
	GLFWwindow* _window;
	Renderer& _renderer;
	ImGuiIO _io;
	std::vector<MyGuiWindow*> _guiWindows;
};

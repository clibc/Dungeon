#pragma once

#include "Renderer.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

class MyGuiWindow
{
public:
	virtual void Update() = 0;
	Renderer _renderer = Renderer::GetInstance();

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
	GuiEnviromentWindow() = default;

	virtual void Update() override
	{
		ImGui::Begin("Environment");
		ImGui::ColorEdit4("BG Color", (float*)&_color);
		if (ImGui::Button("Change Color"))
			_renderer.SetClearColor(_color);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

		ImGui::End();
	}

private:
	glm::vec4 _color = glm::vec4(0.0f);
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

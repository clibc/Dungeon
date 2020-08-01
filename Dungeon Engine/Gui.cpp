#include "Gui.h"


Gui::Gui(GLFWwindow* window, bool install_callbacks)
	:_window(window), _renderer(Renderer::GetInstance())
{

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	_io = ImGui::GetIO();
	(void)_io;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, install_callbacks);
	ImGui_ImplOpenGL3_Init("#version 330 core");
}


void Gui::GuiAddWindow(MyGuiWindow* window)
{
	_guiWindows.push_back(window);
}

void Gui::GuiRemoveWindow(MyGuiWindow* window)
{
	if (_guiWindows.size() <= 0)
		return;

	std::vector<MyGuiWindow*>::iterator it = std::find(_guiWindows.begin(), _guiWindows.end(), window);

	_guiWindows.erase(it);
}

void Gui::Update() const
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	for (MyGuiWindow* w : _guiWindows)
		w->Update();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

}

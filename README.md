# Dungeon
The non-commercial game engine that I build for learning purposes. I am currently working on the renderer (using OpenGL). For future work planning to add Log system, Entity-Component System, etc.

![](https://github.com/62bit/Dungeon/blob/master/Dungeon%20Engine/Source/dungeon.gif)

# Getting Started
Project is only available on Windows atm.
First clone the repositiory. (Don't forget to put '--recursive' flag.)
```
git clone https://github.com/62bit/Dungeon.git --recursive
```
Then, start Premake and it will build solution files for you.
```
premake5.exe vs2019
```

**Helper Libraries**
- [GLFW](https://www.glfw.org/)
- [GLEW](http://glew.sourceforge.net/)
- [stb](https://github.com/nothings/stb/)
- [GLM](https://glm.g-truc.net/)
- [spdlog](https://github.com/gabime/spdlog)
- [ImGui](https://github.com/ocornut/imgui/)

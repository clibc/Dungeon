# Dungeon
The non-commercial game engine that I build for learning purposes. I am currently working on the renderer (using OpenGL). For future work planning to add Log system, Entity-Component System, etc.

![](https://github.com/62bit/Dungeon/blob/master/Dungeon%20Engine/Source/dungeon.gif)

# Getting Started
The project contains Visual Studio Solution file(.sln) which means you can clone and open with. So it is only available on Windows atm. (I will add Premake or CMake to make the building process easier)

```
1. git clone https://github.com/62bit/Dungeon.git
2. C\C++ -> General - Additional Include Directories "$(ProjectDir);$(ProjectDir)Dependencies\glfw\include;$(ProjectDir)Dependencies\;$(ProjectDir)Dependencies\glew\include;$(ProjectDir)Source"
3. C\C++ -> Preprocessor - Preprocessor Definitions - "GLEW_STATIC;WIN32;<different options>"  
4. Linker-> General - Additional Library Directories "$(ProjectDir)Dependencies\glfw\lib-vc2019;$(ProjectDir)Dependencies\glew\lib;%(AdditionalLibraryDirectories)"
5. Linker-> Input - Additional Dependences "glfw3.lib;glew32s.lib;opengl32.lib;user32.lib;gdi32.lib;shell32.lib" 
```

**Helper Libraries**
- [GLFW](https://www.glfw.org/)
- [GLEW](http://glew.sourceforge.net/)
- [stb](https://github.com/nothings/stb/)
- [GLM](https://glm.g-truc.net/)
- [spdlog](https://github.com/gabime/spdlog)
- [ImGui](https://github.com/ocornut/imgui/)

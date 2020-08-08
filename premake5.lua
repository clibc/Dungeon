workspace "Dungeon"
	filename "DungeonEngine"
	configurations {"Debug", "Release"}
	platforms { "x64" , "x86" }
	targetdir "bin"

project "DungeonEngine"
	kind "ConsoleApp"
	language "C++"

debugdir "Dungeon Engine/"

files {
	"Dungeon Engine/*.h",
	"Dungeon Engine/*.cpp",
	"Dungeon Engine/Source/*.cpp",
	"Dungeon Engine/Source/*.hpp",
	"Dungeon Engine/Source/*.h",
	"Dungeon Engine/Events/*.h",
	"Dungeon Engine/Dependencies/imgui/*.cpp",
	"Dungeon Engine/Dependencies/imgui/*.h"
}

includedirs {
	"Dungeon Engine",
	"Dungeon Engine/Source",
	"Dungeon Engine/Dependencies/glew/include",
	"Dungeon Engine/Dependencies/glfw/include",
	"Dungeon Engine/Dependencies/spdlog/include",
	"Dungeon Engine/Dependencies"	
}

defines {
	"GLEW_STATIC",
	"WIN32"
}

libdirs {
	"Dungeon Engine/Dependencies/glfw/lib-vc2019",
	"Dungeon Engine/Dependencies/glew/lib"
}

links {
	"glfw3.lib",
	"glew32s.lib",
	"user32.lib",
	"opengl32.lib",
	"gdi32.lib",
	"shell32.lib",
}

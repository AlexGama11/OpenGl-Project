workspace "OpenGl Project"
	location "./solution/"
	startproject "OpenGl Project"

	targetdir "./Build/bin/%{cfg.buildcfg}/%{cfg.platform}/"
	objdir "./Build/obj/%{cfg.buildcfg}/%{cfg.platform}/"
	buildlog "./Build/obj/%{cfg.platform}/%{cfg.buildcfg}/%{prj.name}.log"

	largeaddressaware "on"
	editandcontinue "off"
	staticruntime "on"

	systemversion "latest"
	characterset "unicode"
	warnings "extra"

	flags {
		"shadowedvariables",
		"multiprocessorcompile",
		"undefinedidentifiers",
	}

	platforms {
		"Win32",
	}

	configurations {
		"Release",
		"Debug",
	}

	--x86
	filter "platforms:Win32"
		architecture "x86"
	--end

	filter "Release"
		defines "NDEBUG"
		optimize "full"
		runtime "release"
		symbols "off"

	filter "Debug"
		defines "DEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	project "OpenGL Project"
		targetname "OpenGl Project"
		language "c++"
		cppdialect "c++20"
		warnings "off"

		kind "consoleapp"

		filter "platforms:Win32"
			syslibdirs {
			"./DevLib/SDL/lib/",
			"./DevLib/SDL/dlls/",
			}
		filter {}

		links {
			"SDL2",
			"SDL2main",
			"opengl32",
		}
		
		includedirs {
			"./DevLib/SDL/include/",
			"./OpenGL/",
		}

		files {
			"./OpenGL/**",
			"./**.md",
			"./**.lua",
			"./**.gitignore",
			"./**.gitattributes",
			"./**.txt",
		}

		
		vpaths {
   			["Headers"] = {"**.h", "**.hpp"},
   			["Sources"] = {"**.c", "**.cpp"},
   			["Docs"] = {"**.txt", "**.md", "**.lua", "**.gitignore", "**.gitattributes"}
		}

	postbuildcommands{ 
		{"{COPY} ../DevLib/SDL/dlls/**.dll ../Build//bin//%{cfg.buildcfg}//%{cfg.platform}//"}
	}
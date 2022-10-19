workspace "OpenGl Project"
	location ".\\sln\\"

	targetdir ".\\Builds\\bin\\%{cfg.buildcfg}\\"
	objdir ".\\Builds\\obj\\%{cfg.buildcfg}\\%{prj.name}\\"
	buildlog ".\\Builds\\obj\\%{cfg.buildcfg}\\%{prj.name}.log"

	largeaddressaware "on"
	editandcontinue "off"
	staticruntime "on"

	systemversion "latest"
	characterset "ascii"
	architecture "x86"
	warnings "extra"

	buildoptions {
		"/std:c++17",
	}

	syslibdirs {
		".\\DevLib\\SDL\\lib\\",
	}

	includedirs {
		".\\OpenGL\\",
		".\\DevLib\\SDL\\include\\",
	}

	postbuildcommands{ 
		"{COPY} ../DevLib/SDL/dlls/**.dll ../Builds//bin//%{cfg.buildcfg}//"
	}

	platforms {
		"x86",
	}

	configurations {
		"Release",
		"Debug",
	}

	configuration "Release"
		defines "NDEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	configuration "Debug"
		defines "DEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	project "OpenGL Project"
		targetname "OpenGl Project"
		language "c++"
		kind "consoleapp"
		warnings "off"

		libdirs {
			".\\DevLib\\SDL\\dlls\\",
		}

		links {
			"SDL2",
			"SDL2main",
			"opengl32",
			"SDL2.dll",
		}
		
		files {
			".\\OpenGL\\**",
		}

		includedirs {
			".\\OpenGL\\",
		}
		
		vpaths {
   			["Headers"] = "**.h",
   			["Sources"] = "**.cpp",
   			["Docs"] = "**.txt"
		}

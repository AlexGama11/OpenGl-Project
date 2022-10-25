workspace "OpenGl Project"
	location ".\\sln\\"

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
		"Win-x86",
	}

	configurations {
		"Release",
		"Debug",
	}

	--x86
	filter "platforms:Win-x86"
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
		cppdialect "c++17"
		warnings "off"

		kind "consoleapp"

		filter "platforms:Win-x86"
			syslibdirs {
			".\\DevLib\\SDL\\lib\\",
			".\\DevLib\\SDL\\dlls\\",
			}
		filter {}

		links {
			"SDL2",
			"SDL2main",
			"opengl32",
		}
		
		includedirs {
			".\\DevLib\\SDL\\include\\",
			".\\OpenGL\\",
		}

		files {
			".\\OpenGL\\**",
		}

		
		vpaths {
   			["Headers"] = "**.h",
   			["Sources"] = "**.c, **.cpp",
   			["Docs"] = "**.txt"
		}

	postbuildcommands{ 
		{"{COPY} ../DevLib/SDL/dlls/**.dll ../Build//bin//%{cfg.buildcfg}//%{cfg.platform}//"}
	}
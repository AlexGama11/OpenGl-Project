#include "Screen.h"

Screen* Screen::Instance()
{
	static Screen* screen = new Screen;
	return screen;
}

bool Screen::Initialize(int width, int height, int posX, int posY, std::string contextVersions, bool isCore)
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == -1)
	{
		Utility::Log("SDL did not initialize properly.", Utility::Severity::Failure);
		return 0;
	}

	majorContext = contextVersions.substr(0, 1);
	majorVer = std::stoi(majorContext);
	minorContext = contextVersions.substr(2, 3);
	minorVer = std::stoi(minorContext);

	//set OpenGL context and profile using values assigned earlier

	if (isCore)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	}
	else
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, majorVer);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minorVer);

	window = SDL_CreateWindow("OpenGL Project", posX, posY, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (!window)
	{
		Utility::Log("OpenGL Window was not created properly.", Utility::Severity::Failure);
		return false;
	}

	context = SDL_GL_CreateContext(window);
	Utility::DisplayOpenGLVersion(majorVer, minorVer);
	

	if (!context)
	{
		do
		{
			Utility::Log("OpenGL context could not be created properly. The context is either invalid or not supported by your graphics card!", Utility::Severity::Warning);
			Utility::Log("Trying one minor version down!", Utility::Severity::Warning);

			VersionDecrement(minorVer);

			if (minorVer == 0 && majorVer >= 0)
			{
				Utility::Log("Trying one major version down!", Utility::Severity::Warning);

				VersionDecrement(majorVer);

				minorVer = 9;

				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, majorVer);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minorVer);

				context = SDL_GL_CreateContext(window);
				Utility::DisplayOpenGLVersion(majorVer, minorVer);
			}

			else
			{
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minorVer);

				context = SDL_GL_CreateContext(window);
				Utility::DisplayOpenGLVersion(majorVer, minorVer);
			}

			
		}

		while (!context);
	}

	if (!gladLoaderLoadGL())
	{
		Utility::Log("Error loading OpenGl extensions.", Utility::Severity::Failure);
		return false;
	}

	Utility::Log("Screen Initialized Successfully! Displaying Graphics Card Information...", Utility::Severity::Success);
	Utility::DisplayGraphicsProfile();
	return true;
}

void Screen::SwapBuffer()
{

	SDL_GL_SwapWindow(window);

}

void Screen::ClearBuffer()
{

	glClear(GL_COLOR_BUFFER_BIT);

}

void Screen::ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	glClearColor(red / 255.0f, green / 255.0f, blue / 255.0f, alpha / 255.0f);
}

void Screen::Shutdown()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit;
}

int Screen::VersionDecrement(int& Version)
{
	Version--;
	return Version;
}
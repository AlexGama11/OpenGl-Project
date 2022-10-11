#include "Screen.h"

bool Screen::Initialize(int width, int height, int posX, int posY, std::string contextVersions)
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == -1)
	{
		std::cout << "SDL did not initialize properly." << std::endl;
		return 0;
	}

	majorContext = contextVersions.substr(0, 1);
	majorVer = std::stoi(majorContext);
	minorContext = contextVersions.substr(2, 3);
	minorVer = std::stoi(minorContext);

	//set OpenGL context and profile using values assigned earlier
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, majorVer);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minorVer);

	window = SDL_CreateWindow("OpenGL Project", posX, posY, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (!window)
	{
		std::cout << "OpenGL Window was not created properly." << std::endl;
		return 0;
	}

	context = SDL_GL_CreateContext(window);

	if (!context)
	{
		std::cout << "OpenGL context could not be created properly. The context is either invalid or not supported by your graphics card" << std::endl;
		return 0;
	}

	return false;
}

void Screen::SwapBuffer()
{
	
	SDL_GL_SwapWindow(window);

}

void Screen::ClearBuffer()
{

	glClear(GL_COLOR_BUFFER_BIT);

}

void Screen::Shutdown()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit;
}

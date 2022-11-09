#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Utility.h"
#include "gl.h"

class Screen
{

public:

	static Screen* Instance();

	/**
	Initialize the screen, by inputting width, height, X position, Y position, and the string for the context version written, for example as "4.6".
	To make the screen centered, set the X position as a quarter of the screen width and the Y position as a quarter of the screen height.
	isCore will define if the program runs in core or compatibility mode.
	*/
	bool Initialize(int width, int height, int posX, int posY, std::string contextVersions, bool isCore);

	void SwapBuffer();

	void ClearBuffer();
	
	void ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

	void Shutdown();

	int VersionDecrement(int& Version);

private:

	Screen() {};
	Screen(const Screen&);
	Screen& operator = (const Screen&);


	SDL_Window* window{ nullptr };
	SDL_Surface* icon{ nullptr };
	SDL_GLContext context{ nullptr };

	std::string majorContext;
	std::string minorContext;

	int majorVer;
	int minorVer;

	bool minorVersionLoop{ true };

};

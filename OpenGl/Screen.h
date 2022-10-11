#pragma once
#include <Windows.h>
#include <gl/GL.h>

#include <SDL.h>
#include <iostream>
#include <string>

class Screen
{

public:

	/**
	Initialize the screen, by inputting width, height, X position, Y position, and the string for the context version written, for example as "4.6".
	To make the screen centered, set the X position as a quarter of the screen width and the Y position as a quarter of the screen height.
	*/ 
	bool Initialize(int width, int height, int posX, int posY, std::string contextVersions);

	void SwapBuffer();

	void ClearBuffer();

	void Shutdown();

private:

	SDL_Window* window{ nullptr };
	SDL_GLContext context{ nullptr };

	std::string majorContext;
	std::string minorContext;
	
	int majorVer;
	int minorVer;

};


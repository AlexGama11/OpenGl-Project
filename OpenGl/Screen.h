#pragma once
#include <Windows.h>
#include <gl/GL.h>

#include <SDL.h>
#include <iostream>
#include <string>

class Screen
{

public:

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


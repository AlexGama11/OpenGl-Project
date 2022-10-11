#include <Windows.h>
#include <gl/GL.h>

#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include "Input.h"


bool isAppRunning{ true };
Uint32 num{ 0 };

int main(int argc, char* argv[])
{
	Screen screen;
	Input input;

	system("Color 09");

	screen.Initialize(1280, 720, 640, 360, "4.6");

	while (isAppRunning)
	{

		input.Update();

		auto num = SDL_GetTicks();

		if (num % 50 == 0)
		{
			float redValue = std::abs(std::sin(num));

			float blueValue = std::abs(std::sin(num * 0.5));

			float greenValue = std::abs(std::cos(num));

			screen.ClearBuffer();


			glBegin(GL_QUADS);

			//top right corner
			glColor3f(redValue, 0.0f, 0.0f);
			glVertex3f(input.GetMousePositionX() + input.GetMouseWheel(), input.GetMousePositionY() + input.GetMouseWheel(), input.GetMousePositionZ() + 0.0f);

			//bottom right corner
			glColor3f(0.0f, greenValue, 0.0f);
			glVertex3f(input.GetMousePositionX() + input.GetMouseWheel(), input.GetMousePositionY() - input.GetMouseWheel(), input.GetMousePositionZ() + 0.0f);

			//bottom left corner
			glColor3f(0.0f, 0.0f, blueValue);
			glVertex3f(input.GetMousePositionX() - input.GetMouseWheel(), input.GetMousePositionY() - input.GetMouseWheel(), input.GetMousePositionZ() + 0.0f);

			//top left corner
			glColor3f(redValue, 0.0f, blueValue);
			glVertex3f(input.GetMousePositionX() - input.GetMouseWheel(), input.GetMousePositionY() + input.GetMouseWheel(), input.GetMousePositionZ() + 0.0f);

			glEnd();

			screen.SwapBuffer();

		}

		if (!input.GetQuit())
		{
			screen.Shutdown();
			isAppRunning = false;
		}
	}

	return 0;
}
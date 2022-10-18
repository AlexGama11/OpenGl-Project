#include <iostream>
#include "Screen.h"
#include "Input.h"
#include "Objects.h"


bool isAppRunning{ true };

int main(int argc, char* argv[])
{
	Objects object;

	system("Color 09");

	Screen::Instance()->Initialize(1280, 720, 320, 180, "4.6");

	while (isAppRunning)
	{

		Input::Instance()->Update();

		Screen::Instance()->ClearBuffer();

		object.Draw();

		Screen::Instance()->SwapBuffer();

		if (Input::Instance()->GetQuit())
		{
			isAppRunning = false;
		}
	}

	Screen::Instance()->Shutdown();

	return 0;
}
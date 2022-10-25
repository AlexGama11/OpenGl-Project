#include <iostream>
#include "Screen.h"
#include "Input.h"
#include "Objects.h"


bool isAppRunning{ true };

int main(int argc, char* argv[])
{
	Objects object;

	Utility::Initialize();

	Screen::Instance()->Initialize(1280, 720, 320, 180, "4.6", false);

	while (isAppRunning)
	{

		Input::Instance()->Update();

		Screen::Instance()->ClearColor(41, 37, 38, 173.4);

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
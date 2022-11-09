#include <iostream>
#include "Header Files/Screen.h"
#include "Header Files/Input.h"
#include "Header Files/Shader.h"
//#include "Objects.h"

Shader shader;
bool isAppRunning{ true };

int main(int argc, char* argv[])
{
	//Objects object;

	Utility::Initialize();

	Screen::Instance()->Initialize(1280, 720, 320, 180, "4.6", false);

	Shader::Initialize();

	shader.Create("../OpenGl/Shader Files/Shader.vert", "../OpenGl/Shader Files/Shader.frag");

	while (isAppRunning)
	{
		Input::Instance()->Update();

		Screen::Instance()->ClearColor(37, 41, 138, 255);

		Screen::Instance()->ClearBuffer();

		//object.Draw();

		Screen::Instance()->SwapBuffer();

		if (Input::Instance()->GetQuit())
		{
			isAppRunning = false;
		}
	}

	shader.Destroy();

	Shader::Shutdown();
	Screen::Instance()->Shutdown();

	return 0;
}
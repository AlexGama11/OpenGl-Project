#include <iostream>
#include "Header Files/Screen.h"
#include "Header Files/Input.h"
#include "Header Files/Shader.h"
#include "Header Files/Objects.h"

Shader shader;
bool isAppRunning{ true };

int main(int argc, char* argv[])
{
	Objects object;

	Utility::Initialize();

	Screen::Instance()->Initialize(1280, 720, 320, 180, "4.6", true);

	Shader::Initialize();

	shader.Create("../OpenGl/Shader Files/RGB.vert", "../OpenGl/Shader Files/RGB.frag");
	shader.Use();

	GLfloat vertices[] = { -0.5f,  0.5f, 0.0f,
							0.5f,  0.5f, 0.0f,
							0.5f, -0.5f, 0.0f,
						   -0.5f, -0.5f, 0.0f };

	/*GLfloat colors[] = { 1.0f, 0.7f, 0.3f,
						 0.4f, 0.8f, 1.0f,
						 0.9f, 1.0f, 0.2f,
						 0.1f, 1.0f, 1.0f };*/

	GLuint indices[] = { 0, 1, 3,
						 3, 1, 2 };

	auto vertexAttributeID = shader.GetAttributeID("position");
	auto timeUniformID = shader.GetUniformID("time");
	//auto colorAttributeID = shader.GetAttributeID("colorIn");

	object.CreateBuffers(vertexAttributeID, /*colorAttributeID,*/ vertices, /*colors,*/ indices);

	while (isAppRunning)
	{
		Input::Instance()->Update();

		if (Input::Instance()->GetQuit())
		{
			isAppRunning = false;
		}

		Screen::Instance()->ClearColor(15, 50, 171, 255);

		Screen::Instance()->ClearBuffer();

		object.Draw(timeUniformID);

		Screen::Instance()->SwapBuffer();
	}

	object.Shutdown(vertexAttributeID/*, colorAttributeID*/);

	shader.Destroy();

	Shader::Shutdown();
	Screen::Instance()->Shutdown();

	return 0;
}
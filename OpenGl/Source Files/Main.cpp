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

	Screen::Instance()->Initialize(1280, 720, 320, 180, "4.6", false);

	Shader::Initialize();

	shader.Create("../OpenGl/Shader Files/Shader.vert", "../OpenGl/Shader Files/Shader.frag");
	shader.Use();

	GLfloat vertices[] = { -0.5f,  0.5f, 0.0f,
							0.5f,  0.5f, 0.0f,
							0.5f, -0.5f, 0.0f,
						   -0.5f, -0.5f, 0.0f };

	GLfloat colors[] = { 1.0f, 0.0f, 0.0f,
						 0.0f, 0.0f, 1.0f,
						 0.0f, 1.0f, 0.0f,
						 0.0f, 1.0f, 1.0f };

	GLuint indices[] = { 0, 1, 3,
						 3, 1, 2 };

	auto vertexAttributeID = shader.GetAttributeID("vertexIn");
	auto colourAttributeID = shader.GetAttributeID("colorIn");

	object.CreateBuffers(vertexAttributeID, colourAttributeID, vertices, colors, indices);

	while (isAppRunning)
	{
		Input::Instance()->Update();

		Screen::Instance()->ClearColor(0, 0, 0, 255);

		Screen::Instance()->ClearBuffer();

		object.Draw();

		Screen::Instance()->SwapBuffer();

		if (Input::Instance()->GetQuit())
		{
			isAppRunning = false;
		}
	}

	object.Shutdown(vertexAttributeID, colourAttributeID);

	shader.Destroy();

	Shader::Shutdown();
	Screen::Instance()->Shutdown();

	return 0;
}
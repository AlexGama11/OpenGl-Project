#include <iostream>
#include "Header Files/Managers/Screen.h"
#include "Header Files/Managers/Input.h"
#include "Header Files/Shader.h"
#include "Header Files/Components/Buffer.h"

Shader shader;
bool isAppRunning{true};

int main(int argc, char* argv[])
{
	Utility::Initialize();

	Screen::Instance()->Initialize(1280, 720, 320, 180, "4.6", true);

	Shader::Initialize();

	shader.Create("../OpenGl/Shader Files/RGB.vert", "../OpenGl/Shader Files/RGB.frag");
	shader.Use();

	Buffer buffer(6, true);

	GLfloat vertices[] = {
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};

	/*GLfloat colors[] = { 1.0f, 0.7f, 0.3f,
						 0.4f, 0.8f, 1.0f,
						 0.9f, 1.0f, 0.2f,
						 0.1f, 1.0f, 1.0f };*/

	GLuint indices[] = {
		0, 1, 3,
		3, 1, 2
	};

	auto vertexAttributeID = shader.GetAttributeID("position");
	auto timeUniformID = shader.GetUniformID("time");
	//auto colorAttributeID = shader.GetAttributeID("colorIn");

	buffer.FillVBO(Buffer::VBO::VertexBuffer, vertices, sizeof(vertices));
	buffer.FillEBO(indices, sizeof(indices));
	buffer.LinkEBO();
	buffer.LinkVBO(vertexAttributeID, Buffer::VBO::VertexBuffer, Buffer::ComponentSize::XYZ,
	               Buffer::DataType::FloatData);

	while (isAppRunning)
	{
		Input::Instance()->Update();

		if (Input::Instance()->GetQuit())
		{
			isAppRunning = false;
		}

		Screen::Instance()->ClearColor(15, 50, 171, 255);

		Screen::Instance()->ClearBuffer();

		buffer.SetTime(timeUniformID);
		buffer.Render(Buffer::RenderMode::Triangles);

		Screen::Instance()->SwapBuffer();
	}

	shader.Destroy();

	Shader::Shutdown();
	Screen::Instance()->Shutdown();

	return 0;
}

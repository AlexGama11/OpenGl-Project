#include "Shader.h"

Shader* Shader::Instance()
{
	static Shader* shader = new Shader;
	return shader;
}

bool Shader::Initialize()
{
	shaderProgramID = glCreateProgram();

	if (shaderProgramID == 0)
	{
		Utility::Log("Error! Shader program could not be created!", Utility::Severity::Failure);
		return false;
	}

	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

	if (vertexShaderID == 0)
	{
		Utility::Log("Error! Vertex Shader could not be created!", Utility::Severity::Failure);
		return false;
	}

	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if (fragmentShaderID == 0)
	{
		Utility::Log("Error! Fragment Shader could not be created!", Utility::Severity::Failure);
		return false;
	}

	return true;
}

void Shader::CompileShaders()
{
	file.open("Main.frag");

	if (!file)
	{
		Utility::Log("Error opening shader frag file! File non-existent or unreachable!", Utility::Severity::Failure);
	}

	while (!file.eof())
	{
		std::getline(file, linetext);
		finalString += linetext + "\n";
	}

	file.close();

	file.open("Main.vert");

	if (!file)
	{
		Utility::Log("Error opening shader vert file! File non-existent or unreachable!", Utility::Severity::Failure);
	}

	while (!file.eof())
	{
		std::getline(file, linetext);
		finalString += linetext + "\n";
	}

	file.close();

	const GLchar* finalCode = (const GLchar*)(finalString.c_str());

	//bind shader code with object
	glShaderSource(vertexShaderID, 1, &finalCode, nullptr);

	//compile shader code
	glCompileShader(vertexShaderID);

	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_TRUE)
	{
		Utility::Log("Shader compiled successfully!", Utility::Severity::Success);
	}

	else
	{
		glGetShaderInfoLog(vertexShaderID, 1000, &length, error);

		Utility::Log("Error! Shader did not compile successfully! Error information down below: ", Utility::Severity::Failure);

		Utility::Log(error, Utility::Severity::Failure);
	}

	glShaderSource(fragmentShaderID, 1, &finalCode, nullptr);

	glCompileShader(fragmentShaderID);

	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_TRUE)
	{
		Utility::Log("Shader compiled successfully!", Utility::Severity::Success);
	}

	else
	{
		glGetShaderInfoLog(fragmentShaderID, 1000, &length, error);

		Utility::Log("Error! Shader did not compile successfully! Error information down below: ", Utility::Severity::Failure);

		Utility::Log(error, Utility::Severity::Failure);
	}

}

void Shader::AttachShaders()
{
	glAttachShader(shaderProgramID, vertexShaderID);
	glAttachShader(shaderProgramID, fragmentShaderID);
}

void Shader::LinkShaderProgram()
{
	glLinkProgram(shaderProgramID);

	glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &linkResult);

	if (linkResult == GL_FALSE)
	{
		glGetShaderInfoLog(shaderProgramID, 1000, &length, error);

		Utility::Log("Error! Program did not link successfully! Error information down below: ", Utility::Severity::Failure);

		Utility::Log(error, Utility::Severity::Failure);
	}

	else
	{
		Utility::Log("Program Linked Successfully!", Utility::Severity::Success);
	}
}

void Shader::ActivateShaders()
{
	glUseProgram(shaderProgramID);
}

void Shader::Detach()
{
	glUseProgram(0);

	glDetachShader(shaderProgramID, vertexShaderID);
	glDetachShader(shaderProgramID, fragmentShaderID);
}

void Shader::Destroy()
{
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	glDeleteProgram(shaderProgramID);
}

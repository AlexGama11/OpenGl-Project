#include "Header Files/Shader.h"

GLint Shader::vertexShaderID = 0;
GLint Shader::fragmentShaderID = 0;

bool Shader::Initialize()
{
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

	if (vertexShaderID == 0)
	{
		Utility::Log("Error! Vertex Shader could not be created! This could be because of your Graphics Card not supporting modern OpenGL!", Utility::Severity::Failure);
		return false;
	}

	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if (fragmentShaderID == 0)
	{
		Utility::Log("Error! Fragment Shader could not be created! This could be because of your Graphics Card not supporting modern OpenGL!", Utility::Severity::Failure);
		return false;
	}

	return true;
}

void Shader::Shutdown()
{
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

GLuint Shader::GetUniformID(const std::string& uniform) const
{
	auto ID = glGetUniformLocation(programID, uniform.c_str());
	assert(ID != -1);
	return ID;
}

GLuint Shader::GetAttributeID(const std::string& attribute) const
{
	auto ID = glGetAttribLocation(programID, attribute.c_str());
	assert(ID != -1);
	return ID;
}


bool Shader::Create(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename)
{
	programID = glCreateProgram();

	if (programID == 0)
	{
		Utility::Log("Error! Shader Program could not be created! This could be because of your Graphics Card not supporting modern OpenGL!", Utility::Severity::Failure);
		return false;
	}

	if (!CompileShaders(vertexShaderFilename))
	{
		return false;
	}

	if (!CompileShaders(fragmentShaderFilename))
	{
		return false;
	}

	if (!LinkProgram())
	{
		return false;
	}

	return true;
}

bool Shader::SendData(const std::string& uniform, GLint data)
{
	glUniform1i(GetUniformID(uniform), data);
	return true;
}

bool Shader::SendData(const std::string& uniform, GLuint data)
{
	glUniform1ui(GetUniformID(uniform), data);
	return true;
}

bool Shader::SendData(const std::string& uniform, GLfloat data)
{
	glUniform1f(GetUniformID(uniform), data);
	return true;
}

bool Shader::SendData(const std::string& uniform, GLfloat x, GLfloat y)
{
	glUniform2f(GetUniformID(uniform), x, y);
	return true;
}

bool Shader::SendData(const std::string& uniform, GLfloat x, GLfloat y, GLfloat z)
{
	glUniform3f(GetUniformID(uniform), x, y, z);
	return true;
}

bool Shader::SendData(const std::string& uniform, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	glUniform4f(GetUniformID(uniform), x, y, z, w);
	return true;
}

void Shader::Use() const
{
	glUseProgram(programID);
}

void Shader::Destroy() const
{
	glDeleteProgram(programID);
}

bool Shader::LinkProgram()
{
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);

	GLint linkResult = 0;

	glGetProgramiv(programID, GL_LINK_STATUS, &linkResult);

	if (linkResult == GL_FALSE)
	{
		GLchar error[1000];
		GLsizei bufferSize = 1000;

		glGetProgramInfoLog(programID, bufferSize, &bufferSize, error);

		Utility::Log("Error! Program did not link successfully! Error information down below: ", Utility::Severity::Failure);
		Utility::Log(error, Utility::Severity::Failure);
		return false;
	}

	Utility::Log("Program Linked Successfully!", Utility::Severity::Success);

	return true;
}

bool Shader::CompileShaders(const std::string& filename)
{

	std::ifstream file(filename);

	//file.open(filename);

	if (!file)
	{
		Utility::Log("Error opening \"" + (filename)+"\"! File non - existent or unreachable! Make sure to check the spelling or the path!", Utility::Severity::Failure);
		return false;
	}

	std::string line;
	std::string sourceCode;

	while (!file.eof())
	{
		std::getline(file, line);
		sourceCode += line + "\n";
	}

	//file.close();

	auto shaderID = (filename.find(".vert")) ? vertexShaderID : fragmentShaderID;

	const GLchar* finalCode = reinterpret_cast<const GLchar*>(sourceCode.c_str());

	//bind shader code with object
	glShaderSource(shaderID, 1, &finalCode, nullptr);

	//compile shader code
	glCompileShader(shaderID);

	GLint compileResult;

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_FALSE)
	{
		GLchar error[1000];
		GLsizei bufferSize = 1000;

		glGetShaderInfoLog(shaderID, bufferSize, &bufferSize, error);

		Utility::Log("Error! Shader did not compile successfully! Error information down below: ", Utility::Severity::Failure);

		Utility::Log(error, Utility::Severity::Failure);
		return false;
	}

	Utility::Log("Shader compiled successfully!", Utility::Severity::Success);

	return true;
}


#pragma once
#include <fstream>
#include "Utility.h"
#include "gl.h"

class Shader
{
public:

	static Shader* Instance();

	bool CreateShaderProgram();

	void CreateShaders();

	void CompileShaders();

	void AttachShaders();

	void LinkShaderProgram();

	void ActivateShaders();

	void Detach();

	void Destroy();




private:
	Shader() {};
	Shader(const Shader&);
	Shader& operator = (const Shader&);

	std::fstream file;
	std::string linetext = "";
	std::string finalString = "";

	GLuint vertexShaderID;
	GLuint fragmentShaderID;
	GLuint shaderProgramID;

	GLchar error[1000];
	GLsizei length = 1000;

	GLint compileResult;
	GLint linkResult;

};
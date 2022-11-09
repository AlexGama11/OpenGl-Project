#pragma once
#include <fstream>
#include "Utility.h"

class Shader
{
public:

	static bool Initialize();

	static void Shutdown();

	bool Create(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);

	void Use() const;
	void Destroy() const;


private:

	static GLint vertexShaderID;
	static GLint fragmentShaderID;

	GLuint programID{ 0 };

	bool LinkProgram();
	
	bool CompileShaders(const std::string& filename);
};
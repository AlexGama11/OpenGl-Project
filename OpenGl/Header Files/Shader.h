#pragma once
#include <assert.h>
#include <fstream>
#include "Header Files/Core/Utility.h"

class Shader
{
public:

	static bool Initialize();

	static void Shutdown();

	GLuint GetUniformID(const std::string& uniform) const;
	GLuint GetAttributeID(const std::string& attribute) const;

	bool Create(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);

	bool SendData(const std::string& uniform, GLint data);
	bool SendData(const std::string& uniform, GLuint data);
	bool SendData(const std::string& uniform, GLfloat data);

	bool SendData(const std::string& uniform, GLfloat x, GLfloat y);
	bool SendData(const std::string& uniform, GLfloat x, GLfloat y, GLfloat z);
	bool SendData(const std::string& uniform, GLfloat x, GLfloat y, GLfloat z, GLfloat w);

	void Use() const;
	void Destroy() const;


private:

	static GLint vertexShaderID;
	static GLint fragmentShaderID;

	GLuint programID{ 0 };

	bool LinkProgram();
	
	bool CompileShaders(const std::string& filename);
};
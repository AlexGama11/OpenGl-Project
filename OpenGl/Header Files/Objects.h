#pragma once
#include <math.h>
#include <chrono>
#include "gl.h"
#include "Input.h"
#include "Utility.h"


class Objects
{

public:

	void CreateBuffers(GLuint vertexAttributeID, /*GLuint colourAttributeID,*/ GLfloat(&vertices)[12], /*GLfloat(&colours)[12],*/ GLuint (&indices)[6]);

	void Draw(GLuint timeUniformID);

	void Shutdown(GLuint vertexAttributeID/*, GLuint colourAttributeID*/);

private:

	GLuint VAO{ 0 };
	GLuint EBO{ 0 };
	GLuint vertexVBO{ 0 };
	GLuint colorVBO{ 0 };
};


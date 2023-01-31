#pragma once
#include <math.h>
#include "gl.h"
#include "Input.h"
#include "Utility.h"


class Objects
{

public:

	void CreateBuffers(GLuint vertexAttributeID, GLuint colourAttributeID, GLfloat vertices[], GLfloat colours[], GLuint indices[]);

	void Draw();

	void Shutdown(GLuint vertexAttributeID, GLuint colourAttributeID);

private:

	GLuint VAO{ 0 };
	GLuint EBO{ 0 };
	GLuint vertexVBO{ 0 };
	GLuint colorVBO{ 0 };
};


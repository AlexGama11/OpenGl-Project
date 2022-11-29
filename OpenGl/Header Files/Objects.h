#pragma once
#include <math.h>
#include "gl.h"
#include "Input.h"
#include "Utility.h"


class Objects
{

public:

	void InitializeVBO();

	void SendData(auto vertexAttributeID, auto colourAttributeID);

	void Draw();

	void Shutdown(auto vertexAttributeID, auto colourAttributeID);

private:

	GLuint vbo{};
};


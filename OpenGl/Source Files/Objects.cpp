#include "Header Files/Objects.h"

void Objects::InitializeVBO()
{
	GLfloat vboData[] = { -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
						   0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
						  -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
						  -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
						   0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
						   0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f };

	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vboData), vboData, GL_STATIC_DRAW);
}

void Objects::SendData(auto vertexAttributeID, auto colourAttributeID)
{
	glVertexAttribPointer(vertexAttributeID, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
	glVertexAttribPointer(colourAttributeID, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

	glEnableVertexAttribArray(vertexAttributeID);
	glEnableVertexAttribArray(colourAttributeID);
}

void Objects::Draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Objects::Shutdown(auto vertexAttributeID, auto colourAttributeID)
{
	glDeleteBuffers(1, &vbo);
	glDisableVertexAttribArray(colorAttributeID);
	glDisableVertexAttribArray(vertexAttributeID);
}

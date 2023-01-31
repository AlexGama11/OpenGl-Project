#include "Header Files/Objects.h"

void Objects::CreateBuffers(GLuint vertexAttributeID, GLuint colourAttributeID, GLfloat vertices[], GLfloat colours[], GLuint indices[])
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vertexVBO);
	glGenBuffers(1, &colorVBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(vertexAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertexAttributeID);

	glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_STATIC_DRAW);
	glVertexAttribPointer(colourAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(colourAttributeID);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void Objects::Draw()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Objects::Shutdown(GLuint vertexAttributeID, GLuint colourAttributeID)
{
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &colorVBO);
	glDeleteBuffers(1, &vertexVBO);
	glDeleteVertexArrays(1, &VAO);

	glDisableVertexAttribArray(colourAttributeID);
	glDisableVertexAttribArray(vertexAttributeID);
}

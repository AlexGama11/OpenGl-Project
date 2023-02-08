#include "Header Files/Objects.h"

void Objects::CreateBuffers(GLuint vertexAttributeID, /*GLuint colourAttributeID,*/ GLfloat(&vertices)[12], /*GLfloat(&colours)[12],*/ GLuint(&indices)[6])
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vertexVBO);
	glGenBuffers(1, &colorVBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	
	/*for (float i : vertices)
	{
		Utility::Log(Utility::NumtoStr(i), Utility::Severity::Warning);
	}*/

	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(vertexAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertexAttributeID);

	/*glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_STATIC_DRAW);
	glVertexAttribPointer(colourAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(colourAttributeID);*/

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void Objects::Draw(GLuint timeUniformID)
{
	// Get the current time point
	auto currentTime = std::chrono::high_resolution_clock::now();

	// Convert the time point to a duration in seconds
	auto duration = std::chrono::duration_cast<std::chrono::duration<float>>(currentTime.time_since_epoch());

	//Make it a float
	float timeInSeconds = duration.count();

	glUniform1f(timeUniformID, timeInSeconds);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Objects::Shutdown(GLuint vertexAttributeID/*, GLuint colourAttributeID*/)
{
	glDeleteBuffers(1, &EBO);
	/*glDeleteBuffers(1, &colorVBO);*/
	glDeleteBuffers(1, &vertexVBO);
	glDeleteVertexArrays(1, &VAO);

	/*glDisableVertexAttribArray(colourAttributeID);*/
	glDisableVertexAttribArray(vertexAttributeID);
}

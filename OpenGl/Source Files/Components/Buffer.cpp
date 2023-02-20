#include "Header Files/Components/Buffer.h"

Buffer::Buffer(GLsizei totalVertices, bool hasEBO) : hasEBO(hasEBO), totalVertices(totalVertices)
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(4, VBOs.data());

	if (hasEBO)
	{
		glGenBuffers(1, &EBO);
	}
}

Buffer::~Buffer()
{
	if (hasEBO)
	{
		glDeleteBuffers(1, &EBO);
	}

	glDeleteBuffers(4, VBOs.data());
	glDeleteVertexArrays(1, &VAO);
}

void Buffer::FillVBO(VBO vbo, const void* data, GLsizeiptr bufferSize, Fill fill) const
{
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[static_cast<int>(vbo)]);
	glBufferData(GL_ARRAY_BUFFER, bufferSize, data, static_cast<GLenum>(fill));
}

void Buffer::FillEBO(const GLuint* data, GLsizeiptr bufferSize, Fill fill) const
{
	glBindBuffer(GL_ARRAY_BUFFER, EBO);
	glBufferData(GL_ARRAY_BUFFER, bufferSize, data, static_cast<GLenum>(fill));
}

void Buffer::LinkEBO() const
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBindVertexArray(0);
}

void Buffer::LinkVBO(GLint attributeID, VBO vbo, ComponentSize componentSize, DataType dataType) const
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[static_cast<int>(vbo)]);

	glVertexAttribPointer(attributeID, static_cast<GLint>(componentSize), static_cast<GLenum>(dataType), GL_FALSE, 0,
	                      nullptr);

	glEnableVertexAttribArray(attributeID);
	glBindVertexArray(0);
}

void Buffer::SetTime(GLuint timeUniformID)
{
	// Get the current time point
	auto currentTime = std::chrono::high_resolution_clock::now();

	// Convert the time point to a duration in seconds
	auto duration = std::chrono::duration_cast<std::chrono::duration<float>>(currentTime.time_since_epoch());

	//Make it a float
	float timeInSeconds = duration.count();

	glUniform1f(timeUniformID, timeInSeconds);
}

void Buffer::Render(RenderMode renderMode) const
{
	glBindVertexArray(VAO);

	if (hasEBO)
	{
		glDrawElements(static_cast<GLenum>(renderMode), totalVertices, GL_UNSIGNED_INT,
		               static_cast<const void*>(nullptr));
	}

	else
	{
		glDrawArrays(static_cast<GLenum>(renderMode), 0, totalVertices);
	}

	glBindVertexArray(0);
}

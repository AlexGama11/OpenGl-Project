#pragma once
#include <math.h>
#include <array>
#include <chrono>
#include "Header Files/Core/gl.h"
#include "Header Files/Managers/Input.h"
#include "Header Files/Core/Utility.h"


class Buffer
{
public:
	enum class Fill
	{
		Once = GL_STATIC_DRAW,
		Ongoing = GL_DYNAMIC_DRAW
	};

	enum class ComponentSize
	{
		XY = 2,
		XYZ = 3,
		XYZW = 4,
		RGB = 3,
		RGBA = 4,
		UV = 2
	};

	enum class DataType
	{
		IntData = GL_INT,
		FloatData = GL_FLOAT,
		DoubleData = GL_DOUBLE,
		UIntData = GL_UNSIGNED_INT
	};

	enum class VBO
	{
		VertexBuffer,
		ColorBuffer,
		TextureBuffer,
		NormalBuffer
	};

	enum class RenderMode
	{
		Lines = GL_LINES,
		Points = GL_POINTS,
		Triangles = GL_TRIANGLES,
		LineLoop = GL_LINE_LOOP,
		LineStrip = GL_LINE_STRIP,
		TriangleFan = GL_TRIANGLE_FAN
	};

	//RAII - Resource Acquisition In Initialization

	Buffer(GLsizei totalVertices, bool hasEBO = false);

	~Buffer();

	void FillVBO(VBO vbo, const void* data, GLsizeiptr bufferSize, Fill fill = Fill::Once) const;

	void FillEBO(const GLuint* data, GLsizeiptr bufferSize, Fill fill = Fill::Once) const;

	void LinkEBO() const;

	void LinkVBO(GLint attributeID, VBO vbo, ComponentSize componentSize, DataType dataType) const;

	void SetTime(GLuint timeUniformID);

	void Render(RenderMode renderMode) const;

private:
	GLuint VAO{0};
	GLuint EBO{0};
	std::array<GLuint, 4> VBOs{0, 0, 0, 0};

	bool hasEBO{false};
	GLsizei totalVertices{0};
};

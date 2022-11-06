#version 460

uniform mat4 projection_matrix;
uniform mat4 modelview_matrix;

in vec3 a_Vertex;
in vec3 a_Colour;
out vec4 colour;

void main(void)
{
	vec4 pos = modelview_matrix * vec4(a_Vertex, 1.0);
	gl_Position = projection_matrix * pos;
	colour = vec4(a_Colour, 1.0);
	//TODO
}
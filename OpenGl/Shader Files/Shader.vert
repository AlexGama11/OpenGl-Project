#version 450

//input vector 3 vertex input.
in vec3 vertexIn;

//input vector 3 colour input.
in vec3 colourIn;

//output vector 3 colour output.
out vec3 colourOut;

void main(void)
{
    //colour output = colour input
    colourOut = colourIn;

    //glPosition equals a vector 4 of vertex input + 1.0
    gl_Position = vec4(vertexIn, 1.0);
}
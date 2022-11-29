#version 450

//input vector 3 colour output
in vec3 colorOut;

//output vector 4 pixelColour
out vec4 pixelColour;

//float for the time
uniform float time;

void main(void)
{
  //pixelColour equals a vector4 of colourOut's rgb * a sin or cos of time.
  pixelColour = vec4(colorOut.r * abs(sin(time)), 
                      colorOut.g * abs(cos(time)), 
                      colorOut.b * abs(sin(time)), 
                      1.0);
}
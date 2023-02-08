#version 460

uniform float time;

layout(location = 0) in vec3 position;

out vec3 color;

void main() {
    vec3 rainbow = vec3(sin(time + position.x), sin(time + position.y), sin(time + position.z));
    color = 0.5 * (rainbow + 1.0);
    gl_Position = vec4(position, 1.0);
}

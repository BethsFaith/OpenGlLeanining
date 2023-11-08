#version 330 core
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 a_pos;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main() {
    TexCoords = a_pos;
    gl_Position = projection * view * vec4(a_pos, 1.0);
}

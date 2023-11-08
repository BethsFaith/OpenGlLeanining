#version 330 core
out vec4 FragColor;

in vec3 texture_dir;

uniform samplerCube cube_map;

void main() {
    FragColor = texture(cube_map, texture_dir);
}

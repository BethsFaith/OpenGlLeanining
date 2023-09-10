#version 330 core
out vec4 FragColor;

uniform vec4 ourColor; // попробуем изменить значение данной переменной через OpenGL-код

void main()
{
    FragColor = ourColor;
}
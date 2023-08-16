#version 330 core
out vec4 FragColor;

in vec4 vertexColor; // входная переменная из вершинного шейдера (такое же имя и такой же тип)

void main()
{
    FragColor = vertexColor;
}
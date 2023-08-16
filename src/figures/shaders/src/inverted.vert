#version 330 core
layout (location = 0) in vec3 aPos;   // позиция атрибута, содержащего переменные координаты, устанавливается равной 0
layout (location = 1) in vec3 aColor; // позиция атрибута, содержащего переменные цвета, устанавливается равной 1

uniform float horizon_offset; // попробуем изменить значение данной переменной через OpenGL-код

out vec3 ourColor; // на выходе – значение цвета, передаваемое во фрагментный шейдер

void main()
{
//    vec3 inverted = vec3(aPos.x, -aPos.y, aPos.z); // перевернуть верх ногами
    vec3 inverted = vec3(aPos.x + horizon_offset, -aPos.y, aPos.z);
    gl_Position = vec4(inverted, 1.0);
    ourColor = aPos; // присваиваем переменной ourColor значение цвета, которое мы получили из данных вершины
}
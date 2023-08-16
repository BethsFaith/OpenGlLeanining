//
// Created by VerOchka on 16.08.2023.
//

#include "Triangles.hpp"

Triangles::Triangles() : _uniform_shader_program(ShaderSources::vertex_shader_source, ShaderSources::uniform_fragment_shader_source),
      _color_shader_program(ShaderSources::inverted_vertex_shader_source, ShaderSources::color_fragment_shader_source) {
    // Указывание вершин (и буферов) и настройка вершинных атрибутов
    float vertices[] = {
        0.6f, -0.5f, 0.0f,  // нижняя правая вершина
        0.2f, 0.1f, 0.0f,  // нижняя левая вершина
        0.6f,  0.8f, 0.0f   // верхняя вершина
    };

    // Указывание вершин (и буферов) и настройка вершинных атрибутов
    float vertices_with_color[] = {
        // координаты                   // цвета
        -0.2f, -0.3f, 0.0f,  1.0f, 0.0f, 0.0f,   // нижняя правая вершина
        -0.9f, 0.4f, 0.0f,  0.0f, 1.0f, 0.0f,   // нижняя левая вершина
        -0.5f,  0.8f, 0.0f,  0.0f, 0.0f, 1.0f    // верхняя вершина
    };

    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);

    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_with_color), vertices_with_color, GL_STATIC_DRAW);

    // Координатный атрибут
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Цветовой атрибут
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    _color_shader_program.use();
    _color_shader_program.setFloat("horizon_offset", 0.4f);
}

Triangles::~Triangles() {
    glDeleteVertexArrays(2, VAO);
    glDeleteBuffers(2, VBO);
}

void Triangles::draw() {
    // Рендеринг
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(VAO[0]);
    // Убеждаемся, что активировали шейдерную программу (прежде, чем вызывать glUniform())
    _uniform_shader_program.use();

    // Обновление шейдерных uniform-переменных
    float timeValue = glfwGetTime();
    float greenValue = sin(timeValue) / 2.0f + 0.5f;
    _uniform_shader_program.set4FloatVector("ourColor", 0.0f, greenValue, 0.0, 1.0f);

    // Рендеринг треугольника
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(VAO[1]);
    _color_shader_program.use();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

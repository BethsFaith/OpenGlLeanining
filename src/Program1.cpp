//
// Created by VerOchka on 16.08.2023.
//

#include "Program1.hpp"

Program1::Program1() {
    std::shared_ptr<ShaderProgram> shader_program = std::make_shared<ShaderProgram>(ShaderSources::vertex_shader_source, ShaderSources::uniform_fragment_shader_source);
    std::shared_ptr<ShaderProgram> color_shader_program = std::make_shared<ShaderProgram>(ShaderSources::color_vertex_shader_source, ShaderSources::color_fragment_shader_source);

    auto triangle = std::make_shared<Triangle>(shader_program);
    auto color_triangle = std::make_shared<Triangle>(color_shader_program);

    triangle->bindVerticesToCoordinates(
        {
            0.6f,
            0.8f,
            0.0f,    // верхняя вершина
            0.6f,
            -0.5f,
            0.0f,    // нижняя правая вершина
            0.2f,
            0.1f,
            0.0f,    // нижняя левая вершина
        },
        GL_STATIC_DRAW);
    color_triangle->bindVerticesToCoordinatesAndColor({
                                                          // координаты        // цвета
                                                          -0.2f, -0.3f, 0.0f,  1.0f, 0.0f, 0.0f,   // нижняя правая вершина
                                                          -0.9f, 0.4f, 0.0f,  0.0f, 1.0f, 0.0f,   // нижняя левая вершина
                                                          -0.5f,  0.8f, 0.0f,  0.0f, 0.0f, 1.0f    // верхняя вершина
                                                      },GL_STATIC_DRAW);

    triangle->setDrawCallback([&](){
        // Обновление шейдерных uniform-переменных
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        shader_program->set4FloatVector("ourColor", 0.0f, greenValue, 0.0, 1.0f);
    });

    drawer = new Drawer;
    drawer->addPrimitive(color_triangle);
    drawer->addPrimitive(triangle);

    color_triangle.reset();
    triangle.reset();
}

void Program1::run() {
    drawer->draw();
}

Program1::~Program1() {
    delete drawer;
}

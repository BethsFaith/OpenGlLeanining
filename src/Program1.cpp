//
// Created by VerOchka on 16.08.2023.
//

#include "Program1.hpp"

#include "figures/buffers/Vbo.hpp"

Program1::Program1() {
    _shader_program = std::make_shared<ShaderProgram>(ShaderSources::vertex_shader_source, ShaderSources::uniform_fragment_shader_source);
    _color_shader_program = std::make_shared<ShaderProgram>(ShaderSources::color_vertex_shader_source, ShaderSources::color_fragment_shader_source);

    auto triangle = std::make_shared<Triangle>(_shader_program, std::vector<float>{
                                                                                                        0.6f, 0.8f, 0.0f,    // верхняя вершина
                                                                                                        0.6f, -0.5f, 0.0f,    // нижняя правая вершина
                                                                                                        0.2f, 0.1f, 0.0f,    // нижняя левая вершина
                                                                                                        });
    auto color_triangle = std::make_shared<Triangle>(_color_shader_program, std::vector<float>{
                                                                                -0.2f, -0.3f, 0.0f,  1.0f, 0.0f, 0.0f,   // нижняя правая вершина
                                                                                -0.9f, 0.4f, 0.0f,  0.0f, 1.0f, 0.0f,   // нижняя левая вершина
                                                                                -0.5f,  0.8f, 0.0f,  0.0f, 0.0f, 1.0f    // верхняя вершина
                                                                            });

    triangle->bind(Settings{.bind_flag = GL_STATIC_DRAW});
    color_triangle->bind(Settings{.bind_flag = GL_STATIC_DRAW, .with_color = true});

    triangle->setDrawCallback([this](){
        // Обновление шейдерных uniform-переменных
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        _shader_program->set4FloatVector("ourColor", 0.0f, greenValue, 0.0, 1.0f);
    });

    drawer = new Drawer;
    drawer->addPrimitive(color_triangle);
    drawer->addPrimitive(triangle);

    color_triangle.reset();
    triangle.reset();
}

Program1::~Program1() {
    delete drawer;
}

void Program1::run() {
    drawer->draw();
}

void Program1::processUserInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

//
// Created by VerOchka on 16.08.2023.
//

#include "Program1.hpp"

#include "tools/objects/figures/buffers/Vbo.hpp"

Program1::Program1() {
    using namespace Figures;
    using namespace Constants;

    _shader_program = std::make_shared<ShaderProgram>(Shaders::getPath(Shaders::Sources::SIMPLE_VERT),
                                                      Shaders::getPath(Shaders::Sources::UNIF_FRAG));

    _color_shader_program = std::make_shared<ShaderProgram>(Shaders::getPath(Shaders::Sources::COLOR_VERT),
                                                      Shaders::getPath(Shaders::Sources::COLOR_FRAG));

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

void Program1::processKeyboardInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Program1::processMouseInput(double x_pos, double y_pos) {}

void Program1::processMouseScroll(double x_offset, double y_offset) {}

void Program1::setDeltaTime(const float& delta_time) {}

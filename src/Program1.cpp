//
// Created by VerOchka on 16.08.2023.
//

#include "Program1.hpp"

Program1::Program1() {
    using namespace Tools;
    using namespace Constants;

    _shader_program = std::make_shared<Tools::Shaders::ShaderProgram>(
        Constants::Shaders::getPath(Constants::Shaders::Sources::SIMPLE_VERT),
        Constants::Shaders::getPath(Constants::Shaders::Sources::UNIF_FRAG));

    _color_shader_program = std::make_shared<Tools::Shaders::ShaderProgram>(
        Constants::Shaders::getPath(Constants::Shaders::Sources::COLOR_VERT),
        Constants::Shaders::getPath(Constants::Shaders::Sources::COLOR_FRAG));

    auto coords = std::vector<float>{
        0.6f, 0.8f, 0.0f,    // верхняя вершина
            0.6f, -0.5f, 0.0f,    // нижняя правая вершина
            0.2f, 0.1f, 0.0f,    // нижняя левая вершина
    };
    auto coords2 = std::vector<float>{
        // координаты       // цвета
        -0.2f, -0.3f, 0.0f,  1.0f, 0.0f, 0.0f,   // нижняя правая вершина
        -0.9f, 0.4f, 0.0f,  0.0f, 1.0f, 0.0f,   // нижняя левая вершина
        -0.5f,  0.8f, 0.0f,  0.0f, 0.0f, 1.0f    // верхняя вершина
    };

    auto triangle = std::make_shared<Objects::Faces::Triangle>();
    auto color_triangle = std::make_shared<Objects::Faces::Triangle>();

    triangle->bind(GL_STATIC_DRAW);
    color_triangle->bind(GL_STATIC_DRAW);

    triangle->setDrawCallback([this](){
        // Обновление шейдерных uniform-переменных
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        _shader_program->set4FloatVector("ourColor", 0.0f, greenValue, 0.0, 1.0f);
    });

    drawer = new Drawer;
    drawer->addPrimitive(color_triangle, _shader_program);
    drawer->addPrimitive(triangle, _color_shader_program);

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

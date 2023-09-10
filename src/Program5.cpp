//
// Created by VerOchka on 10.09.2023.
//

#include "Program5.hpp"

Program5::Program5() {
    using namespace Figures;
    using namespace Constants;

    _shader_program = std::make_shared<ShaderProgram>(Shaders::getPath(Shaders::Sources::THIRDD_UNIF_TEXTURE_VERT),
                                                      Shaders::getPath(Shaders::Sources::TEXTURE_FRAG));

    std::vector<float> coords = {-0.5f, -0.5f, -0.5f,
                                    0.5f, -0.5f, -0.5f,
                                    0.5f,  0.5f, -0.5f,
                                    0.5f,  0.5f, -0.5f,
                                    -0.5f,  0.5f, -0.5f,
                                    -0.5f, -0.5f, -0.5f,

                                    -0.5f, -0.5f,  0.5f,
                                    0.5f, -0.5f,  0.5f,
                                    0.5f,  0.5f,  0.5f,
                                    0.5f,  0.5f,  0.5f,
                                    -0.5f,  0.5f,  0.5f,
                                    -0.5f, -0.5f,  0.5f,

                                    -0.5f,  0.5f,  0.5f,
                                    -0.5f,  0.5f, -0.5f,
                                    -0.5f, -0.5f, -0.5f,
                                    -0.5f, -0.5f, -0.5f,
                                    -0.5f, -0.5f,  0.5f,
                                    -0.5f,  0.5f,  0.5f,

                                    0.5f,  0.5f,  0.5f,
                                    0.5f,  0.5f, -0.5f,
                                    0.5f, -0.5f, -0.5f,
                                    0.5f, -0.5f, -0.5f,
                                    0.5f, -0.5f,  0.5f,
                                    0.5f,  0.5f,  0.5f,

                                    -0.5f, -0.5f, -0.5f,
                                    0.5f, -0.5f, -0.5f,
                                    0.5f, -0.5f,  0.5f,
                                    0.5f, -0.5f,  0.5f,
                                    -0.5f, -0.5f,  0.5f,
                                    -0.5f, -0.5f, -0.5f,

                                    -0.5f,  0.5f, -0.5f,
                                    0.5f,  0.5f, -0.5f,
                                    0.5f,  0.5f,  0.5f,
                                    0.5f,  0.5f,  0.5f,
                                    -0.5f,  0.5f,  0.5f,
                                    -0.5f,  0.5f, -0.5f,
    };
    auto vbo = std::make_shared<VBO>(coords);

    auto cube = std::make_shared<Cube>(_shader_program, vbo);
    auto light_cube = std::make_shared<Cube>(_shader_program, vbo);

    light_cube->bind(Settings{.bind_flag = GL_STATIC_DRAW, .with_texture = false, .with_color = false});

    _drawer.addPrimitive(light_cube);
    _drawer.addPrimitive(cube);
}

void Program5::run() {
    _drawer.draw();
}

void Program5::processKeyboardInput(GLFWwindow* window) {}

void Program5::processMouseInput(double xpos, double ypos) {}

void Program5::processMouseScroll(double xpos, double ypos) {}

void Program5::setDeltaTime(const float& delta_time) {}

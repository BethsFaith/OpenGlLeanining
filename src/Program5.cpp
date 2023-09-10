//
// Created by VerOchka on 10.09.2023.
//

#include "Program5.hpp"

Program5::Program5() {
    using namespace Figures;
    using namespace Constants;

    _shader_program = std::make_shared<ShaderProgram>(Shaders::getPath(Shaders::Sources::THIRDD_UNIF_TEXTURE_VERT),
                                                      Shaders::getPath(Shaders::Sources::TEXTURE_FRAG));

    Figures::Cube cube(_shader_program,
                       std::vector<float>{-0.5f, -0.5f, -0.5f,
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
    });


}

void Program5::run() {}

void Program5::processKeyboardInput(GLFWwindow* window) {}

void Program5::processMouseInput(double xpos, double ypos) {}

void Program5::processMouseScroll(double xpos, double ypos) {}

void Program5::setDeltaTime(const float& delta_time) {}

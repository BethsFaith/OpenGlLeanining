//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM1_HPP
#define INC_2_SHADERS_PROGRAM1_HPP

#include "../tools/objects/faces/Triangle.hpp"
#include "../tools/objects/faces/buffers/Vbo.hpp"
#include "Program.hpp"

// Устаревшее, не использовать без переписывания!!!
class Program1 : public Program {
public:
    Program1();
    ~Program1() override;

    void run() override;

    void processKeyboardInput(GLFWwindow* window) override;
    void processMouseInput(double x_pos, double y_pos) override;
    void processMouseScroll(double x_offset, double y_offset) override;
    void setDeltaTime(const float& delta_time) override;

private:
    Tools::Drawer* drawer;

    std::shared_ptr<Tools::Shaders::ShaderProgram> _shader_program;
    std::shared_ptr<Tools::Shaders::ShaderProgram> _color_shader_program;
};

#endif    //INC_2_SHADERS_PROGRAM1_HPP

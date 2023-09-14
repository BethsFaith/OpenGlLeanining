//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM1_HPP
#define INC_2_SHADERS_PROGRAM1_HPP

#include "Program.hpp"
#include "tools/objects/figures/Triangle.hpp"

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
    Figures::Drawer* drawer;

    std::shared_ptr<Figures::ShaderProgram> _shader_program;
    std::shared_ptr<Figures::ShaderProgram> _color_shader_program;
};

#endif    //INC_2_SHADERS_PROGRAM1_HPP

//
// Created by VerOchka on 10.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM5_HPP
#define INC_2_SHADERS_PROGRAM5_HPP

#include "Program.hpp"
#include "tools/objects/figures/Cube.hpp"

class Program5 : public Program {
public:
    Program5();
    ~Program5() override = default;

    void run() override;

    void processKeyboardInput(GLFWwindow* window) override;
    void processMouseInput(double xpos, double ypos) override;
    void processMouseScroll(double xpos, double ypos) override;

    void setDeltaTime(const float& delta_time) override;

private:
    std::shared_ptr<Figures::ShaderProgram> _shader_program;

    Figures::Drawer _drawer{};
};

#endif    //INC_2_SHADERS_PROGRAM5_HPP

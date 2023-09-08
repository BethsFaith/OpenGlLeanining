//
// Created by VerOchka on 23.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM_HPP
#define INC_2_SHADERS_PROGRAM_HPP

#include "tools/objects/figures/shaders/ShaderSources.hpp"
#include "tools/objects/figures/Drawer.hpp"

class Program {
public:
    Program() = default;
    virtual ~Program() = default;

    virtual void run() = 0;

    virtual void processKeyboardInput(GLFWwindow* window) = 0;

    virtual void processMouseInput(double xpos, double ypos) = 0;

    virtual void processMouseScroll(double xpos, double ypos) = 0;

    virtual void setDeltaTime(const float& delta_time) = 0;

protected:
    float last_x{};
    float last_y{};

    float fov = 49.0f;

    bool first_mouse = true;
};

#endif    //INC_2_SHADERS_PROGRAM_HPP

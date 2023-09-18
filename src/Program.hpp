//
// Created by VerOchka on 23.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM_HPP
#define INC_2_SHADERS_PROGRAM_HPP

#include "constants/Shaders.hpp"
#include "constants/Textures.hpp"
#include "tools/Drawer.hpp"

class Program {
public:
    Program() = default;
    virtual ~Program() = default;

    virtual void run() = 0;

    virtual void processKeyboardInput(GLFWwindow* window) = 0;

    virtual void processMouseInput(double x_pos, double y_pos) = 0;

    virtual void processMouseScroll(double x_offset, double y_offset) = 0;

    virtual void setDeltaTime(const float& delta_time) = 0;

protected:
    float last_x{};
    float last_y{};

    bool first_mouse = true;
};

#endif    //INC_2_SHADERS_PROGRAM_HPP

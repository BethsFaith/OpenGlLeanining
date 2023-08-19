//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM1_HPP
#define INC_2_SHADERS_PROGRAM1_HPP

#include "figures/shaders/ShaderSources.hpp"
#include "figures/Drawer.hpp"
#include "figures/Triangle.hpp"

class Program1 {
public:
    Program1();
    ~Program1();

    void run();

private:
    Drawer* drawer;

    std::shared_ptr<ShaderProgram> _shader_program;
    std::shared_ptr<ShaderProgram> _color_shader_program;
};

#endif    //INC_2_SHADERS_PROGRAM1_HPP

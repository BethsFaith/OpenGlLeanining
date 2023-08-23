//
// Created by VerOchka on 23.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM_HPP
#define INC_2_SHADERS_PROGRAM_HPP

#include "figures/shaders/ShaderSources.hpp"
#include "figures/Drawer.hpp"

class Program {
public:
    Program() = default;
    virtual ~Program() = default;

    virtual void run() = 0;

    virtual void processUserInput(GLFWwindow* window) = 0;
};

#endif    //INC_2_SHADERS_PROGRAM_HPP

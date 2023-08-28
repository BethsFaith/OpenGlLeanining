//
// Created by VerOchka on 26.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM3_HPP
#define INC_2_SHADERS_PROGRAM3_HPP

#include "Program.hpp"
#include "lib_headears/glm.hpp"
#include "figures/Rectangle.hpp"
#include "figures/Cube.hpp"
#include "figures/textures/Texture.hpp"

class Program3 : public Program{
public:
    Program3();
    ~Program3() override = default;

    void run() override;
    void processUserInput(GLFWwindow* window) override;

private:
    std::shared_ptr<ShaderProgram> _shader_program;

    Drawer _drawer{};
    Texture _texture1{GL_TEXTURE0};
    Texture _texture2{GL_TEXTURE1};
};

#endif    //INC_2_SHADERS_PROGRAM3_HPP

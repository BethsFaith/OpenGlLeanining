//
// Created by VerOchka on 17.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM2_HPP
#define INC_2_SHADERS_PROGRAM2_HPP

#include "figures/shaders/ShaderSources.hpp"
#include "figures/Drawer.hpp"
#include "figures/Rectangle.hpp"
#include "figures/buffers/Ebo.hpp"
#include "figures/buffers/Vbo.hpp"
#include "figures/textures/Texture.hpp"

class Program2 {
public:
    Program2();
    ~Program2() = default;

    void run();

private:
    std::shared_ptr<ShaderProgram> _shader_program;
    Drawer _drawer{};
    Texture _texture1{GL_TEXTURE0};
    Texture _texture2{GL_TEXTURE1};
};

#endif    //INC_2_SHADERS_PROGRAM2_HPP

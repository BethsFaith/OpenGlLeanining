//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_TRIANGLES_HPP
#define INC_2_SHADERS_TRIANGLES_HPP

#include "shaders/ShaderProgram.hpp"
#include "shaders/ShaderSources.hpp"

class Triangles {
public:
    Triangles();
    ~Triangles();

    void draw();
private:
    unsigned int VBO[2], VAO[2];
    ShaderProgram _uniform_shader_program;
    ShaderProgram _color_shader_program;
};

#endif    //INC_2_SHADERS_TRIANGLES_HPP

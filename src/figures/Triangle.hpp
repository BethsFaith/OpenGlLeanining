//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_TRIANGLE_HPP
#define INC_2_SHADERS_TRIANGLE_HPP

#include "Primitive.hpp"

class Triangle : public Primitive {
public:
    explicit Triangle(std::shared_ptr<ShaderProgram> shader_program);

    void draw() override;
};

#endif    //INC_2_SHADERS_TRIANGLE_HPP

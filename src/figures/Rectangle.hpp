//
// Created by VerOchka on 17.08.2023.
//

#ifndef INC_2_SHADERS_RECTANGLE_HPP
#define INC_2_SHADERS_RECTANGLE_HPP

#include "buffers/Vbo.hpp"
#include "buffers/Ebo.hpp"

#include "Primitive.hpp"

class Rectangle : public Primitive {
public:
    explicit Rectangle(const std::shared_ptr<ShaderProgram>& shader_program, const std::vector<float>& coords);
    ~Rectangle() = default;
    void draw() override;

private:

};

#endif    //INC_2_SHADERS_RECTANGLE_HPP

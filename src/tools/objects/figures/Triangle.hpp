//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_TRIANGLE_HPP
#define INC_2_SHADERS_TRIANGLE_HPP

#include "buffers/Vbo.hpp"
#include "Primitive.hpp"

namespace Figures {
    class Triangle : public Primitive {
    public:
        explicit Triangle(const std::shared_ptr<ShaderProgram>& shader_program, const std::vector<float>& coordinates);
        explicit Triangle(const std::shared_ptr<ShaderProgram>& shader_program, std::shared_ptr<VBO> vbo);

        void draw() override;
    };
}

#endif    //INC_2_SHADERS_TRIANGLE_HPP

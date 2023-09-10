//
// Created by VerOchka on 26.08.2023.
//

#ifndef INC_2_SHADERS_CUBE_HPP
#define INC_2_SHADERS_CUBE_HPP

#include "buffers/Ebo.hpp"
#include "buffers/Vbo.hpp"
#include "Primitive.hpp"

namespace Figures {
    class Cube : public Primitive {
    public:
        explicit Cube(const std::shared_ptr<ShaderProgram>& shader_program, const std::vector<float>& coords);
        explicit Cube(const std::shared_ptr<ShaderProgram>& shader_program, std::shared_ptr<VBO> vbo);

        ~Cube() override = default;

        void draw() override;
    };
}

#endif    //INC_2_SHADERS_CUBE_HPP

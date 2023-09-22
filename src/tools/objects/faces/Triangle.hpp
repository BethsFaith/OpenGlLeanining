//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_TRIANGLE_HPP
#define INC_2_SHADERS_TRIANGLE_HPP

#include "Primitive.hpp"
#include "buffers/Vbo.hpp"

namespace Tools::Objects::Faces {
    class Triangle : public Primitive {
    public:
        explicit Triangle();

        void draw() override;

        void bindData(const unsigned int& bind_flag) override;
    };
}

#endif    //INC_2_SHADERS_TRIANGLE_HPP

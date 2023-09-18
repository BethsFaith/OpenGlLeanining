//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_TRIANGLE_HPP
#define INC_2_SHADERS_TRIANGLE_HPP

#include "BasePrimitive.hpp"
#include "buffers/Vbo.hpp"

namespace Tools::Objects::Faces {
    class Triangle : public BasePrimitive {
    public:
        explicit Triangle();

        void draw() override;
    };
}

#endif    //INC_2_SHADERS_TRIANGLE_HPP

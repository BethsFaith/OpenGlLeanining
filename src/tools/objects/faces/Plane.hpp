//
// Created by VerOchka on 29.09.2023.
//

#ifndef INC_2_SHADERS_PLANE_HPP
#define INC_2_SHADERS_PLANE_HPP

#include "Primitive.hpp"
#include "buffers/Vbo.hpp"

namespace Tools::Objects::Faces {
    class Plane : public Primitive {
    public:
        explicit Plane(const Settings& settings);
        ~Plane() override = default;

        void bindData(const unsigned int& bind_flag) override;
        void draw() override;
    };
}

#endif    //INC_2_SHADERS_PLANE_HPP

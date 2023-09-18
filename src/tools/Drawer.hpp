//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_DRAWER_HPP
#define INC_2_SHADERS_DRAWER_HPP

#include "objects/faces/BasePrimitive.hpp"
#include "shaders/ShaderProgram.hpp"

namespace Tools {
    class Drawer {
    public:
        struct DrawablePrimitive{
            std::shared_ptr<Tools::Objects::Faces::BasePrimitive> primitive;
            std::shared_ptr<Shaders::ShaderProgram> shader;
        };

        Drawer() = default;
        ~Drawer() = default;

        void draw();
        void addPrimitive(const std::shared_ptr<Tools::Objects::Faces::BasePrimitive>& primitive,
                          const std::shared_ptr<Tools::Shaders::ShaderProgram>& shader_program);

        void removePrimitive(std::shared_ptr<Tools::Objects::Faces::BasePrimitive>);
        void removePrimitive(const unsigned int& uid);

    private:
        std::vector<DrawablePrimitive> _primitives;
    };
}

#endif    //INC_2_SHADERS_DRAWER_HPP

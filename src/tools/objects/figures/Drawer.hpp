//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_DRAWER_HPP
#define INC_2_SHADERS_DRAWER_HPP

#include "Primitive.hpp"

namespace Figures {
    class Drawer {
    public:
        Drawer() = default;
        ~Drawer() = default;

        void draw();
        void addPrimitive(const std::shared_ptr<Primitive>&);
        void removePrimitive(std::shared_ptr<Primitive>);

    private:
        std::vector<std::shared_ptr<Primitive>> _primitives;
    };
}

#endif    //INC_2_SHADERS_DRAWER_HPP

//
// Created by VerOchka on 19.09.2023.
//

#ifndef INC_2_SHADERS_ABSTRACTPRIMITIVE_HPP
#define INC_2_SHADERS_ABSTRACTPRIMITIVE_HPP

#include <functional>

namespace Tools::Objects::Faces {
    class AbstractPrimitive {
    public:
        explicit AbstractPrimitive() = default;
        virtual ~AbstractPrimitive() = default;

        virtual void setDrawCallback(std::function<void()> function) = 0;

        virtual void bind(const unsigned int& bind_flag) = 0;
        virtual void draw() = 0;

        [[nodiscard]] virtual unsigned int getUid() const = 0;
    };
}
#endif    //INC_2_SHADERS_ABSTRACTPRIMITIVE_HPP

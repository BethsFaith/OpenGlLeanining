//
// Created by VerOchka on 19.08.2023.
//

#ifndef INC_2_SHADERS_VBO_HPP
#define INC_2_SHADERS_VBO_HPP

#include <vector>
#include <utility>

#include "RaiiBuffer.hpp"
#include "Vertex.hpp"

namespace Tools::Objects::Faces::Buffers{
    class VBO : public RaiiBuffer {
    public:
        explicit VBO(const std::vector<Vertex>& data);
        ~VBO() override;

        void bind(const unsigned int& bind_flag) override;
        [[nodiscard]] unsigned int get() const override;
        void unbind() override;

    private:
        unsigned int _vbo{};
        std::vector<Vertex> _data;
    };
}

#endif    //INC_2_SHADERS_VBO_HPP

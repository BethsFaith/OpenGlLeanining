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
    template <typename T>
    class VBO : public RaiiBuffer {
    public:
        explicit VBO(const std::vector<T>& data);
        ~VBO() override;

        void bind() override;
        void unbind() override;

        void bindData(const unsigned int& bind_flag) override;

        [[nodiscard]] unsigned int get() const override;
        [[nodiscard]] const std::vector<T>& getVertices() const;

    private:
        unsigned int _vbo{};
        std::vector<T> _vertices;
    };
}

#endif    //INC_2_SHADERS_VBO_HPP

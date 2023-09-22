//
// Created by VerOchka on 19.08.2023.
//

#ifndef INC_2_SHADERS_EBO_HPP
#define INC_2_SHADERS_EBO_HPP

#include <vector>
#include <utility>

#include "RaiiBuffer.hpp"

namespace Tools::Objects::Faces::Buffers{
    class EBO : public RaiiBuffer {
    public:
        explicit EBO(std::vector<unsigned int> indices);
        ~EBO() override;

        void bind() override;
        void unbind() override;

        void bindData(const unsigned int& bind_flag) override;

        [[nodiscard]] unsigned int get() const override;
        [[nodiscard]] const std::vector<unsigned int>& getIndices() const;

    private:
        unsigned int _ebo{};

        std::vector<unsigned int> _indices;
    };
}
#endif    //INC_2_SHADERS_EBO_HPP

//
// Created by VerOchka on 19.08.2023.
//

#ifndef INC_2_SHADERS_VBO_HPP
#define INC_2_SHADERS_VBO_HPP

#include <vector>
#include <utility>

#include "RaiiBuffer.hpp"

class VBO : public RaiiBuffer {
public:
    explicit VBO(std::vector<float> data);
    ~VBO() override;

    void bind(const unsigned int& bind_flag) override;
    [[nodiscard]] unsigned int get() const override;

private:
    unsigned int _vbo{};
    std::vector<float> _data;
};

#endif    //INC_2_SHADERS_VBO_HPP

//
// Created by VerOchka on 17.08.2023.
//

#ifndef INC_2_SHADERS_VAO_HPP
#define INC_2_SHADERS_VAO_HPP

#include "RaiiBuffer.hpp"

class VAO : public RaiiBuffer{
public:
    VAO();
    ~VAO() override;

    void bind(const unsigned int& bind_flag) override;
    [[nodiscard]] unsigned int get() const override;

private:
    unsigned int _vao{};
};

#endif    //INC_2_SHADERS_VAO_HPP

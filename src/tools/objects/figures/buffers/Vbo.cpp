//
// Created by VerOchka on 19.08.2023.
//

#include "Vbo.hpp"

#include <iostream>

VBO::VBO(std::vector<float> data) : RaiiBuffer(1), _data(std::move(data)){
    glGenBuffers(1, &_vbo);
}

VBO::~VBO() {
    glDeleteBuffers(1, &_vbo);
}

void VBO::bind(const unsigned int& bind_flag) {
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, int(_data.size() * sizeof(float)), _data.data(), bind_flag);
}

unsigned int VBO::get() const {
    return _vbo;
}

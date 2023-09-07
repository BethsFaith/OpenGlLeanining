//
// Created by VerOchka on 17.08.2023.
//

#include "Vao.hpp"

VAO::VAO() : RaiiBuffer(0) {
    glGenVertexArrays(1, &_vao);
}

VAO::~VAO() {
    glDeleteBuffers(1, &_vao);
}

void VAO::bind(const unsigned int& bind_flag) {
    glBindVertexArray(_vao);
}

unsigned int VAO::get() const {
    return _vao;
}

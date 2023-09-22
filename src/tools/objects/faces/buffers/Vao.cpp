//
// Created by VerOchka on 17.08.2023.
//

#include "Vao.hpp"

namespace Tools::Objects::Faces::Buffers {
    VAO::VAO() : RaiiBuffer(0) {
        glGenVertexArrays(1, &_vao);
    }

    VAO::~VAO() {
        glDeleteBuffers(1, &_vao);
    }

    void VAO::bind() {
        glBindVertexArray(_vao);
    }

    void VAO::bindData(const unsigned int& bind_flag) {}

    void VAO::unbind() {
        glBindVertexArray(0);
    }

    unsigned int VAO::get() const {
        return _vao;
    }
}
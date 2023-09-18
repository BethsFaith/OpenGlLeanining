//
// Created by VerOchka on 19.08.2023.
//

#include "Ebo.hpp"

namespace Tools::Objects::Faces::Buffers {
    EBO::EBO(std::vector<unsigned int> indices) : RaiiBuffer(2), _indices(std::move(indices)) {
        glGenBuffers(1, &_ebo);
    }

    EBO::~EBO() {
        glDeleteBuffers(1, &_ebo);
    }

    void EBO::bind(const unsigned int& bind_flag) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(float), _indices.data(), bind_flag);
    }

    void EBO::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    unsigned int EBO::get() const {
        return _ebo;
    }
}
//
// Created by VerOchka on 19.08.2023.
//

#include "Vbo.hpp"

#include <iostream>

namespace Tools::Objects::Faces::Buffers {
    VBO::VBO(const std::vector<Vertex>& data) : RaiiBuffer(1), _data(data) {
        glGenBuffers(1, &_vbo);
    }

    VBO::~VBO() {
        glDeleteBuffers(1, &_vbo);
    }

    void VBO::bind(const unsigned int& bind_flag) {
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glBufferData(GL_ARRAY_BUFFER, int(_data.size() * sizeof(Vertex)), _data.data(), bind_flag);//_data.data(), bind_flag);
    }

    void VBO::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    unsigned int VBO::get() const {
        return _vbo;
    }
}
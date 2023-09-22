//
// Created by VerOchka on 19.08.2023.
//

#include "Vbo.hpp"

#include <iostream>

namespace Tools::Objects::Faces::Buffers {
    template <typename T>
    VBO<T>::VBO(const std::vector<T>& data) : RaiiBuffer(1), _vertices(data) {
        glGenBuffers(1, &_vbo);
    }

    template <typename T>
    VBO<T>::~VBO() {
        glDeleteBuffers(1, &_vbo);
    }

    template <typename T>
    void VBO<T>::bind() {
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    }

    template <typename T>
    void VBO<T>::bindData(const unsigned int& bind_flag) {
        glBufferData(GL_ARRAY_BUFFER, int(_vertices.size() * sizeof(T)),
                     &_vertices[0], bind_flag); //_data.data(), bind_flag);
    }

    template <typename T>
    void VBO<T>::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    template <typename T>
    unsigned int VBO<T>::get() const {
        return _vbo;
    }

    template <typename T>
    const std::vector<T>& VBO<T>::getVertices() const {
        return _vertices;
    }
}
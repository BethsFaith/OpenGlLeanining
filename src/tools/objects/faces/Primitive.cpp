//
// Created by VerOchka on 16.08.2023.
//

#include "Primitive.hpp"

namespace Tools::Objects::Faces {
    Primitive::Primitive(const int &vertex_number_) : Primitive(vertex_number_, {}){}

    Primitive::Primitive(const int& vertex_number_, const Settings &settings)
        : vertex_number(vertex_number_),
          _settings(settings) {
        _drawCallback = []() {};

        _vao = std::make_shared<Buffers::VAO>();
        add(_vao);
    }

    void Primitive::bind(const unsigned int& bind_flag) {
        for (auto& buffer : buffers) {
            buffer->bind(bind_flag);
        }

        int index = 0;
        // Координатный атрибут
        setVertexAttribute(index++, 3, (int)(sizeof(Buffers::Vertex)), (void*)nullptr);
        // Нормали вершин
        if (_settings.with_normals){
            setVertexAttribute(index++,
                               3,
                               (int)(sizeof(Buffers::Vertex)),
                               (void*)(offsetof(Buffers::Vertex, normal)));
        }
        if (_settings.with_texture) {
            // Текстурные координаты
            setVertexAttribute(index++,
                               2,
                               (int)(sizeof(Buffers::Vertex)),
                               (void*)(offsetof(Buffers::Vertex, tex_coords)));
        }
        _vao->unbind();
    }

    void Primitive::setVertexAttribute(const int& index, const int& size, const int& stride, void* offset) {
        glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(index);
    }

    void Primitive::add(std::shared_ptr<Buffers::RaiiBuffer> raii_buffer) {
        buffers.push_back(std::move(raii_buffer));

        std::sort(buffers.begin(),
                  buffers.end(),
                  [](const std::shared_ptr<Buffers::RaiiBuffer>& buf1, const std::shared_ptr<Buffers::RaiiBuffer>& buf2) {
                      return buf1->getPriority() < buf2->getPriority();
                  });
    }

    void Primitive::draw() {
        glBindVertexArray(_vao->get());

        _drawCallback();
    }

    void Primitive::setDrawCallback(std::function<void()> function) {
        _drawCallback = std::move(function);
    }

    unsigned int Primitive::getUid() const {
        return _vao->get();
    }
}